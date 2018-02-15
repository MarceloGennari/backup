#include <isam/isam.h>

#include <pronto_utils/pronto_vis.hpp>

#include <iostream>
#include <fstream>
#include <lcm/lcm.h>
#include <lcm/lcm-cpp.hpp>

#include <boost/algorithm/string.hpp>

// Pronto Lib
#include "visualization/collections_math.hpp"
#include "visualization/viewer.hpp"
#include "visualization/pointcloud.hpp"

// AICP Lib
#include "aicpRegistration/registration.hpp"
#include "aicpRegistration/common.hpp"

#include "aicpOverlap/overlap.hpp"
#include "aicpOverlap/common.hpp"

#include "aicpClassification/classification.hpp"
#include "aicpClassification/common.hpp"
#include "drawingUtils/drawingUtils.hpp"

#include "commonUtils/cloudIO.h"
#include "commonUtils/common.hpp" // Includes things like CONFIG_LOC and PROJECT_LOC and PATH_SEPARATOR
// yaml
#include "yaml-cpp/yaml.h"

// pcl Lib
#include <pcl/io/pcd_io.h>

#include <unistd.h>
#include <ConciseArgs>
#include <lcmtypes/octomap_utils.h>


// My Lib
#include "include/path.hpp"

using namespace std;
using namespace isam;
using namespace aicp;
struct Candidate{
	Pose3d pose;
	int id;
	int CloudMapNumb;
};

struct CommandLineConfig
{
  string configFile;
  string pointCloudA;
  string pointCloudB;
};

/* AICP VARIABLES*/
RegistrationParams registration_params;
OverlapParams overlap_params;
ClassificationParams classification_params;
string experiments_param;
string configNameAICP;
CommandLineConfig cl_cfg;

float reject = 0.45;  
std::vector<Pose3d> listPoses;
std::vector<Pose3d> posesCorrected;

std::vector<Eigen::Matrix4f> transforms;

std::vector<std::pair<Candidate,Candidate>> links; /* Where links.first is the reading cloud and links.second is the reference cloud*/


std::vector<std::pair<pcl::PointCloud<pcl::PointXYZ>, pcl::PointCloud<pcl::PointXYZ> > > candidateClouds_original;
std::vector<std::pair<pcl::PointCloud<pcl::PointXYZ>, pcl::PointCloud<pcl::PointXYZ> > > candidateClouds;

std::vector<Candidate> candid;
double threshold;
int sample;
std::string cloudsDir;
std::string appendLine = "";
double xadd = 0;
double yadd = 0;
double distance(Candidate c1, Candidate c2){
	double x = c1.pose.x()-c2.pose.x();
	double y = c1.pose.y()-c2.pose.y();
	double z = c1.pose.z()-c2.pose.z();
	double dist = x*x+y*y+z*z;

	return sqrt(dist);
}

void findCandidatePairs(){
	Candidate newest = candid[candid.size()-1];

      	for(int i = 0; i<candid.size()-1; i++){
		/**************
		 * The Requirements to be a loop closure are:
		 * 	1. The distance between the Poses should be less than a certain value
		 * 	2. The two Poses should be more than 2 samples away from each other
		 **************/
		if(distance(newest , candid[i]) < threshold && newest.CloudMapNumb-2*sample > candid[i].CloudMapNumb){
			/* This means that links.first will be the read and links.second will be the reference */
			std::pair<Candidate, Candidate> p1(newest, candid[i]);
			links.push_back(p1);
		}
	}
}

void readFile(std::string filName, Viewer &v){

	/************
	 * The idea of the algorithm is:
	 * 1. Downsample the poses based on number of samples (one every {int} freq times)
	 * 2. Find the distance between the downsample pose and all of the previous ones
	 * 	2.1 If the distance between any of the downsampled poses is bigger than a threshold y:
	 * 		Add the pair to the vector links;
	 * 3. Send Collections of links to Director
	 * ***********/  

	ifstream posFile;
	std::string line;
    	posFile.open(filName);
	int numl = 0;

  if(!posFile.good()){
	cout << "Unable to open file" << endl;
	exit(1);
  }

  ObjectCollection obj(1, std::string("Poses"), VS_OBJECT_COLLECTION_T_AXIS3D);
	Eigen::Matrix4d World;
  while(std::getline(posFile, line)){	
	std::vector<std::string> strs;
	boost::split(strs, line, boost::is_any_of("\t "));
	double x = std::stod(strs.at(0)), y = std::stod(strs.at(1)), z = std::stod(strs.at(2)), yaw = std::stod(strs.at(3)), pitch = std::stod(strs.at(4)), roll = std::stod(strs.at(5));
	
	Pose3d pose3dC(x,y,z,yaw,pitch,roll);

 /* This is to add a little disturbance to the position of the pose */       
//	if(numl == 114){
//		pose3dC.set_x(x+xadd);
//		pose3dC.set_y(y+yadd);
//		std::cout << "Added 0.1 to each coordinate to pose3dC" << std::endl;
//	}

	if(numl==0){
		// Transform to world reference frame
		World = pose3dC.oTw();
	}
	Pose3d pose3d(World*pose3dC.wTo());
	
	listPoses.push_back(pose3d);
	obj.add(2009+numl, coll::Pose3d(pose3d.x(),pose3d.y(),pose3d.z(),pose3d.yaw(),pose3d.pitch(),pose3d.roll()));
	v.sendCollection(obj,true);	

	/** Downsampling **/	
	if(numl%sample == 0){
		Candidate c = {pose3d, numl+2009, numl};
		candid.push_back(c);
		findCandidatePairs();
	}
	numl++;	
  }
  
}

void printLines(Viewer &v, std::string name, int id){
	LinkCollection link(id, std::string(name));
	for(int i = 0; i<links.size(); i++){
		link.add(i+1, 1, links[i].first.id, 1, links[i].second.id);
	}
	v.sendCollection(link, true);
}

void getPointClouds(Viewer &v){
	int count = 3;
	pcl::PCDReader reader;
		
	ObjectCollection obj(901, std::string("Pose Read"), VS_OBJECT_COLLECTION_T_AXIS3D);
	ObjectCollection obj2(900, std::string("Pose Reference"), VS_OBJECT_COLLECTION_T_AXIS3D);
	PointCloudCollection pc_collection(902, std::string("Point Clouds"), 901, VS_POINT3D_LIST_COLLECTION_T_POINT);
	PointCloudPtr pc = boost::make_shared<PointCloud>(2000);
			
	for(int i = 0; i< links.size() ; i++){
		pcl::PointCloud<pcl::PointXYZ> cloud_read;
		pcl::PointCloud<pcl::PointXYZ> cloud_reference;

		std::string map1 = cloudsDir +  std::to_string(links[i].first.CloudMapNumb) + ".pcd";
		std::string map2 = cloudsDir + std::to_string(links[i].second.CloudMapNumb) + ".pcd";
		
		reader.read(map1, cloud_read); 
		reader.read(map2, cloud_reference);
		std::pair<pcl::PointCloud<pcl::PointXYZ>, pcl::PointCloud<pcl::PointXYZ>> pa1(cloud_read, cloud_reference);	
		candidateClouds_original.push_back(pa1);

		/* Transforming the point cloud to the pose reference */
		Eigen::Matrix4d t = links[i].first.pose.wTo();
		Eigen::Matrix4d t2 = links[i].second.pose.wTo();

		/* PAY ATTENTION!!! SOMETIMES THE CLOUD IS IN THE POSE REFERENCE FRAME AND SOMETIMES IT IS IN THE WORLD REFERENCE FRAME */
		pcl::PointCloud<pcl::PointXYZ> cloud_read_transformed;
		pcl::PointCloud<pcl::PointXYZ> cloud_ref_transformed;
		pcl::transformPointCloud(cloud_read, cloud_read_transformed, t);
		pcl::transformPointCloud(cloud_reference, cloud_ref_transformed, t2);
	
		/* Create Pair of Clouds */
		std::pair<pcl::PointCloud<pcl::PointXYZ>, pcl::PointCloud<pcl::PointXYZ>> p1(cloud_read_transformed, cloud_ref_transformed);
		candidateClouds.push_back(p1);

		Pose3d pSel = links[i].first.pose;
		Pose3d pSel2 = links[i].second.pose;
		
		obj.add(1+i, coll::Pose3d(pSel.x(), pSel.y(), pSel.z(), pSel.yaw(), pSel.pitch(), pSel.roll()));
		obj2.add(2+i, coll::Pose3d(pSel2.x(), pSel2.y(), pSel2.z(), pSel2.yaw(), pSel2.pitch(), pSel2.roll()));

		count++;
		count++;
	
		/* Trying to plot points */
		for(int k = 0; k<cloud_read_transformed.size(); k++){
			double x = cloud_read_transformed.at(k).x, y = cloud_read_transformed.at(k).y, z = cloud_read_transformed.at(k).z;
			pc->addPoint(x,y,z, 1., 0., 0.);
		}

		for(int k = 0; k<cloud_ref_transformed.size(); k++){
			double x = cloud_ref_transformed.at(k).x, y = cloud_ref_transformed.at(k).y, z = cloud_ref_transformed.at(k).z;
			pc->addPoint(x,y,z, 1., 0., 0.);
		}

		std::cout << "Send point cloud "<< i << std::endl;
		//cin.get();
	}
	
	pc_collection.add(boost::make_shared<PointCloudPtr>(pc));
	v.sendCollection(pc_collection, true);	
	v.sendCollection(obj, true);
	v.sendCollection(obj2, true);
	
}

void findTransforms(){
	int numberErased = 0;
	int counter = -1;
  for(int i = 0; i<candidateClouds.size(); i++){
	counter++;
	 /*===================================
	  =            YAML Config            =
	  ===================================*/
	  string yamlConfig_;
	  YAML::Node yn_;
	  yamlConfig_ = cl_cfg.configFile;
	  yn_ = YAML::LoadFile(yamlConfig_);
	
	  YAML::Node registrationNode = yn_["AICP"]["Registration"];
	  for(YAML::const_iterator it=registrationNode.begin();it != registrationNode.end();++it) {
	
	    const string key = it->first.as<string>();
	
	    if(key.compare("type") == 0) {
	      registration_params.type = it->second.as<string>();
	    }
	    else if(key.compare("sensorRange") == 0) {
	      registration_params.sensorRange =  it->second.as<float>();
	    }
	    else if(key.compare("sensorAngularView") == 0) {
	      registration_params.sensorAngularView =  it->second.as<float>();
	    }
	    else if(key.compare("loadPosesFrom") == 0) {
	      registration_params.loadPosesFrom = it->second.as<string>();
	    }
	    else if(key.compare("initialTransform") == 0) {
	      registration_params.initialTransform = it->second.as<string>();
	    }
	    else if(key.compare("saveCorrectedPose") == 0) {
	      registration_params.saveCorrectedPose =  it->second.as<bool>();
	    }
	    else if(key.compare("saveInitializedReadingCloud") == 0) {
	      registration_params.saveInitializedReadingCloud =  it->second.as<bool>();
	    }
	    else if(key.compare("saveRegisteredReadingCloud") == 0) {
	      registration_params.saveRegisteredReadingCloud =  it->second.as<bool>();
	    }
	    else if(key.compare("enableLcmVisualization") == 0) {
	      registration_params.enableLcmVisualization =  it->second.as<bool>();
	    }
	  }
	  if(registration_params.type.compare("Pointmatcher") == 0) {
	
	    YAML::Node pointmatcherNode = registrationNode["Pointmatcher"];
	
	    for(YAML::const_iterator it=pointmatcherNode.begin();it != pointmatcherNode.end();++it) {
	      const string key = it->first.as<string>();
	
	      if(key.compare("configFileName") == 0) {
	        registration_params.pointmatcher.configFileName.append(FILTERS_CONFIG_LOC);
	        registration_params.pointmatcher.configFileName.append(PATH_SEPARATOR);
	        registration_params.pointmatcher.configFileName = FILTERS_CONFIG_LOC + PATH_SEPARATOR + it->second.as<string>();
	      }
	      else if(key.compare("printOutputStatistics") == 0) {
	        registration_params.pointmatcher.printOutputStatistics =  it->second.as<bool>();
	      }
	    }
	  }
	  else if(registration_params.type.compare("GICP") == 0) {
	
	    YAML::Node gicpNode = registrationNode["GICP"];
	
	    for(YAML::const_iterator it=gicpNode.begin();it != gicpNode.end();++it) {
	      const string key = it->first.as<string>();
	      const float val = it->second.as<float>();
	    }
	  }
	  YAML::Node overlapNode = yn_["AICP"]["Overlap"];
	  for(YAML::const_iterator it=overlapNode.begin();it != overlapNode.end();++it) {
	
	    const string key = it->first.as<string>();
	
	    if(key.compare("type") == 0) {
	      overlap_params.type = it->second.as<string>();
	    }
	  }
	  if(overlap_params.type.compare("OctreeBased") == 0) {
	
	    YAML::Node octreeBasedNode = overlapNode["OctreeBased"];
	
	    for(YAML::const_iterator it=octreeBasedNode.begin();it != octreeBasedNode.end();++it) {
	      const string key = it->first.as<string>();
	
	      if(key.compare("octomapResolution") == 0) {
	        overlap_params.octree_based.octomapResolution = it->second.as<float>();
	      }
	    }
	  }
	  YAML::Node classificationNode = yn_["AICP"]["Classifier"];
	  for (YAML::const_iterator it = classificationNode.begin(); it != classificationNode.end(); ++it) {
	    const std::string key = it->first.as<std::string>();
	
	    if (key.compare("type") == 0) {
	      classification_params.type = it->second.as<std::string>();
	    }
	  }
	
	  if (classification_params.type.compare("SVM") == 0) {
	
	    YAML::Node svmNode = classificationNode["SVM"];
	
	    for(YAML::const_iterator it=svmNode.begin();it != svmNode.end();++it) {
	      const std::string key = it->first.as<std::string>();
	
	      if(key.compare("threshold") == 0) {
	        classification_params.svm.threshold = it->second.as<double>();
	      }
	      else if(key.compare("trainingFile") == 0) {
	        classification_params.svm.trainingFile = it->second.as<std::string>();
	      }
	      else if(key.compare("testingFile") == 0) {
	          classification_params.svm.testingFile = it->second.as<std::string>();
	      }
	      else if(key.compare("saveFile") == 0) {
	        classification_params.svm.saveFile = it->second.as<std::string>();
	      }
	      else if(key.compare("saveProbs") == 0) {
	        classification_params.svm.saveProbs = it->second.as<std::string>();
	      }
	      else if(key.compare("modelLocation") == 0) {
	        classification_params.svm.modelLocation = it->second.as<std::string>();
	      }
	    }
	  }
	  YAML::Node experimentsNode = yn_["AICP"]["Experiments"];
	  for(YAML::const_iterator it=experimentsNode.begin();it != experimentsNode.end();++it) {
	
	    const string key = it->first.as<string>();
	
	    if(key.compare("type") == 0) {
	      experiments_param = it->second.as<string>();
	    }
	  }
	
	  cout << "============================" << endl
	       << "Parsed YAML Config" << endl
	       << "============================" << endl;
	
	  cout << "[Main] Registration Type: "                 << registration_params.type                          << endl;
	  cout << "[Main] Sensor Range: "                      << registration_params.sensorRange                   << endl;
	  cout << "[Main] Sensor Angular View: "               << registration_params.sensorAngularView             << endl;
	  cout << "[Main] Load Poses from: "                   << registration_params.loadPosesFrom                 << endl;
	  cout << "[Main] Initial Transform: "                 << registration_params.initialTransform              << endl;
	  cout << "[Main] Save Corrected Pose: "               << registration_params.saveCorrectedPose             << endl;
	  cout << "[Main] Save Initialized Reading Cloud: "    << registration_params.saveInitializedReadingCloud   << endl;
	  cout << "[Main] Save Registered Reading Cloud: "     << registration_params.saveRegisteredReadingCloud    << endl;
	  cout << "[Main] Enable Lcm Visualization: "          << registration_params.enableLcmVisualization        << endl;
	
	  if(registration_params.type.compare("Pointmatcher") == 0) {
	    cout << "[Pointmatcher] Config File Name: "                << registration_params.pointmatcher.configFileName        << endl;
	    cout << "[Pointmatcher] Print Registration Statistics: "   << registration_params.pointmatcher.printOutputStatistics << endl;
	  }
	  else if(registration_params.type.compare("GICP") == 0) {
	}
	
	  cout << "[Main] Overlap Type: "                   << overlap_params.type                             << endl;
	
	  if(overlap_params.type.compare("OctreeBased") == 0) {
	    cout << "[OctreeBased] Octomap Resolution: "    << overlap_params.octree_based.octomapResolution   << endl;
	  }
	
	  cout << "[Main] Classification Type: "       << classification_params.type                    << endl;
	
	  if(classification_params.type.compare("SVM") == 0) {
	    cout << "[SVM] Acceptance Threshold: "    << classification_params.svm.threshold           << endl;
	    cout << "[SVM] Training File: "           << classification_params.svm.trainingFile        << endl;
	    cout << "[SVM] Testing File: "            << classification_params.svm.testingFile         << endl;
	    cout << "[SVM] Saving Model To: "         << classification_params.svm.saveFile            << endl;
	    cout << "[SVM] Saving Probs To: "         << classification_params.svm.saveProbs           << endl;
	    cout << "[SVM] Loading Model From: "      << classification_params.svm.modelLocation       << endl;
	  }
	
	  cout << "[Main] Experiments Type: "               << experiments_param                               << endl;
	  cout << "============================" << endl;
	
	
	  pcl::PointCloud<pcl::PointXYZ> cloud_read = candidateClouds[i].first;
	  pcl::PointCloud<pcl::PointXYZ> cloud_ref = candidateClouds[i].second;
	  Pose3d ref = links[i].second.pose;
	  Pose3d read = links[i].first.pose;


	/*===================================
	  =        Filter Input Clouds        =
	  ===================================*/
	
	  pcl::PointCloud<pcl::PointXYZ> overlap_points_A;
	  pcl::PointCloud<pcl::PointXYZ> overlap_points_B;

	  // ------------------
	  // FOV-based Overlap
	  // ------------------
	  Eigen::Isometry3d ground_truth_reference_pose_iso = fromMatrix4fToIsometry3d(ref.wTo().cast<float>());
	  Eigen::Isometry3d estimated_reading_pose_iso = fromMatrix4fToIsometry3d(read.wTo().cast<float>());
	 
	 // pcl::PointCloud<pcl::PointXYZ> cloud_read2 = cloud_read;
	 // pcl::PointCloud<pcl::PointXYZ>::Ptr initialized_cloud_read (new pcl::PointCloud<pcl::PointXYZ>(cloud_read2));
	 //
	 // float fov_overlap = overlapFilter(cloud_ref, *initialized_cloud_read,
	 //                                   ground_truth_reference_pose_iso, estimated_reading_pose_iso,
	 //                                   registration_params.sensorRange , registration_params.sensorAngularView,
	 //                                   overlap_points_A, overlap_points_B);
	 // cout << "====================================" << endl
	 //      << "[Main] FOV-based Overlap: " << fov_overlap << " %" << endl
	 //      << "====================================" << endl;

 	 // ------------------------------------
 	 // Pre-filtering: 1) down-sampling
 	 //                2) planes extraction
 	 // ------------------------------------
 	 pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_A_prefiltered (new pcl::PointCloud<pcl::PointXYZ>);
	 pcl::PointCloud<pcl::PointXYZ> cloud_ref_copy(cloud_ref);
	 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ref_ptr (new pcl::PointCloud<pcl::PointXYZ>(cloud_ref_copy));
	 regionGrowingUniformPlaneSegmentationFilter(cloud_ref_ptr, point_cloud_A_prefiltered);
	 pcl::PointCloud<pcl::PointXYZ> cloud_read_copy(cloud_read);
 	 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_read_ptr (new pcl::PointCloud<pcl::PointXYZ>(cloud_read_copy));
	 pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud_B_prefiltered (new pcl::PointCloud<pcl::PointXYZ>);
 	 regionGrowingUniformPlaneSegmentationFilter(cloud_read_ptr, point_cloud_B_prefiltered);

	 // ---------------------
	  // Octree-based Overlap
	  // ---------------------
	  std::unique_ptr<AbstractOverlapper> overlapper_ = create_overlapper(overlap_params);
	
	  ColorOcTree* ref_tree;
	  ColorOcTree* read_tree = new ColorOcTree(overlap_params.octree_based.octomapResolution);
	
	  // Create octree from reference cloud (wrt robot point of view),
	  // add the reading cloud and compute overlap
	  //Eigen::Isometry3d ground_truth_reading_pose_iso = fromMatrix4fToIsometry3d(ground_truth_reading_pose);
	  ref_tree = overlapper_->computeOverlap(*point_cloud_A_prefiltered, *point_cloud_B_prefiltered,
	                                         ground_truth_reference_pose_iso, estimated_reading_pose_iso,
	                                         read_tree);
	  float octree_overlap = overlapper_->getOverlap();
	
	  cout << "====================================" << endl
	       << "[Main] Octree-based Overlap: " << octree_overlap << " %" << endl
	       << "====================================" << endl;

	  /*===================================
	  =              AICP Core            =
	  ===================================*/

	  float current_ratio = octree_overlap/100.0;
	  if (current_ratio < reject){
		// Probably not a good fit, so reject
		links.erase(links.begin()+i);
		candidateClouds.erase(candidateClouds.begin()+i);
		candidateClouds_original.erase(candidateClouds_original.begin()+i);
		i--;
		continue;
	  } 
	  else if(current_ratio < 0.25){
		current_ratio = 0.25;	 
	  } else if (current_ratio > 0.70)
	    current_ratio = 0.70;
	
	  // Auto-tune ICP chain (quantile for the outlier filter)
	  configNameAICP = FILTERS_CONFIG_LOC;
	  configNameAICP.append("/icp_autotuned.yaml");
	
	  replaceRatioConfigFile(registration_params.pointmatcher.configFileName, configNameAICP, current_ratio);
	  registration_params.pointmatcher.configFileName = configNameAICP;
   
	  /*===================================
	  =          Register Clouds          =
	  ===================================*/

  	  std::cout << "register clouds part" << std::endl;	  
	  Eigen::Matrix4f T = Eigen::Matrix4f::Zero(4,4);
	
	  std::unique_ptr<AbstractRegistrator> registration = create_registrator(registration_params);
	  std::cout << "After registration" << std::endl;
	  vector<float> soa_predictions;
	  registration->registerClouds(*point_cloud_A_prefiltered, *point_cloud_B_prefiltered, T, soa_predictions);
	//  registration->registerClouds(point_cloud_A, *initialized_reading_cloud_ptr, T, soa_predictions);
	  cout << "[Main] Degeneracy (degenerate if ~ 0): " << soa_predictions.at(0) << " %" << endl;
	  cout << "[Main] ICN (degenerate if ~ 0): " << soa_predictions.at(1) << endl;
	
	  cout << "============================" << endl
	       << "Computed 3D Transform:" << endl
	       << "============================" << endl
	       << T << endl;
	
	  Eigen::Matrix4f corrected_reading_pose;
	  corrected_reading_pose = T * read.wTo().cast<float>();
	  cout << "============================" << endl
	       << "Corrected Reading Pose:" << endl
	       << "============================" << endl
	       << corrected_reading_pose << endl;

	  pcl::PointCloud<pcl::PointXYZ> cloud_result;
	  pcl::transformPointCloud(cloud_read, cloud_result, T);
	  
 	  transforms.push_back(corrected_reading_pose);

 
	  pcl::io::savePCDFileASCII ("Results/CloudReadCorrectedAICP_" + std::to_string(i) + ".pcd", cloud_result);
	  pcl::io::savePCDFileASCII ("Results/CloudRead_" + std::to_string(i) + ".pcd", cloud_read);
	  pcl::io::savePCDFileASCII ("Results/CloudReference_" + std::to_string(i) + ".pcd", cloud_ref);
	  registration.release();
	}
}

void transform(Viewer &v){
	ObjectCollection obj(217, std::string("Pose Corrected AICP"), VS_OBJECT_COLLECTION_T_AXIS3D);
	std::cout << transforms.size() << " " << links.size() << " " << candidateClouds.size() << std::endl;		
	
	for(int i = 0; i<links.size(); i++){	
		Pose3d ref = listPoses[links[i].second.CloudMapNumb];
	 	ObjectCollection obj3(219+i, std::string("Reference Pose " + std::to_string(i)), VS_OBJECT_COLLECTION_T_AXIS3D);
		obj3.add(i+1, coll::Pose3d(ref.x(), ref.y(), ref.z(), ref.yaw(), ref.pitch(), ref.roll()));
		v.sendCollection( obj3, true);	
		Eigen::Matrix4d corrected_reading_pose = transforms[i].cast<double>();
	
		Pose3d newPose = isam::Pose3d(corrected_reading_pose);

		obj.add(1+i, coll::Pose3d(newPose.x(), newPose.y(), newPose.z(), newPose.yaw(), newPose.pitch(), newPose.roll()));

		/********************
		 * This is the corrected pose. 
		 * Now we just need to find the transformation (ODOMETRY or EDGE3) from the reference pose to the newPose 
		 * ******************/
		// Everything in Reference to the first pose:

		Pose3d od = newPose.ominus(ref);

		/********************
		 * Now we just need to print out the Loop Closures:
		 * ******************/
		int from = links[i].second.CloudMapNumb;
		int to = links[i].first.CloudMapNumb;
		std::string newLine = "EDGE3 " + std::to_string(from) + " " +
						 std::to_string(to) + " " +
						 std::to_string(od.x()) + " " +
						 std::to_string(od.y()) + " " +
						 std::to_string(od.z()) + " " +
						 std::to_string(od.roll()) + " " +
						 std::to_string(od.pitch()) + " " +
						 std::to_string(od.yaw()) + "  " + /* Remember additional space */
						 "10 0 0 0 0 0 10 0 0 0 0 10 0 0 0 100 0 0 100 0 25\n";
		std::cout << newLine;
		appendLine = appendLine + newLine;
		//cin.get();
	}
	
	v.sendCollection(obj,true);	


}

void appendToFile(std::string append, std::string filIn, std::string filOut){
	/* This function takes as inputs:
	 * 	1. The Append String
	 * 	2. The File to Append to
	 * 	3. The File that is going to be written to
	 *
	 * The idea is: A file is read, then the append string is put at the end of the file and the result is written at filOut
	 * ***********/

	std::ifstream in(filIn);
	std::ofstream out(filOut);

	out << in.rdbuf();
	out << append;
}

int main(int argc, char** argv)
{
  std::string filname;
  std::string filname2;
  filname = ""; // where's the scan at?
  
  cl_cfg.configFile.append(CONFIG_LOC);
  cl_cfg.configFile.append(PATH_SEPARATOR);
  cl_cfg.configFile.append("aicp_config.yaml");
  cl_cfg.pointCloudA = "";
  cl_cfg.pointCloudB = "";
	
  ConciseArgs parser(argc, argv, "");
  parser.add(filname, "f", "filename", "ISAM file to process in x y z yaw pitch roll format (e.g. posesFromAICP)");
  parser.add(filname2, "i", "iSAM Form", "ISAM file to process in EDGE3 format");
  parser.add(threshold, "t", "threshold", "loop closure Threshold");
  parser.add(sample, "s", "sample", "Sampling constant");
  parser.add(cloudsDir, "cd", "Cloud Directory", "Directory of the isam-clouds");
  parser.add(reject, "r", "Reject Overlap Ratio", "Reject Overlap Ration");
  parser.add(xadd, "x", "add to x" ,"add");
  parser.add(yadd, "y", "add to y", "add");  
  parser.parse();
 
  lcm_t * lcm;
  lcm = lcm_create(NULL);
  
    if(!lcm)
  {
    cerr << "Failed to create lcm connection" << endl;
    return 1;
  }
 /*******
   * The idea here is: we open the file with the poses. We read line by line after the user presses a key and we draw it to director
   * *****/
  std::cout << "Outputting to lcm" << std::endl;
  Viewer viewer(lcm);
  //LinkCollection link(1, std::string("Links"));

  readFile(filname, viewer);
 
  std::cout << "Number of Loop Closures found: " << links.size() << std::endl; 
  printLines(viewer, "Links Candidates", 723);

  /* Populates the candidateClouds vector with the clouds that need to be inputted to the icp algorithm */
  /* Problem 1: The Point clouds should be visible in Director, but they are not */
  getPointClouds(viewer);

  /* Populates the transforms vector with the transformation between the candidate clouds */
  findTransforms();

  /* Transforms the poses to new estimation */
  transform(viewer);

  printLines(viewer, "Links Closed Loops", 724);

  appendToFile(appendLine, filname2, "Results/husky_isam_trajectory.txt");  
  /* Uses the ICP to find rotation and translation between clouds */
  lcm_destroy(lcm);
  return 0;
}
