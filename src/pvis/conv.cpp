/* This will hopefully convert from a world perspective to an odometry one */

#include <string>
#include <iostream>
#include <fstream>
#include <isam/isam.h>

#include <lcm/lcm-cpp.hpp>
#include <lcmtypes/bot_core.hpp>
#include <lcmtypes/visualization.h> // VS_OBJECT_COLLECTION_T_AXIS3D

#include <pronto_utils/pronto_vis.hpp> // visualize pt clds
#include <pronto_utils/pronto_conversions_lcm.hpp>
#include <ConciseArgs>

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <cloud_accumulate/cloud_accumulate.hpp>

// dift filters
#include "pronto_lidar_filters/lidar_filters.hpp"

#include <path_util/path_util.h>

using namespace std;
using namespace isam;
void writePoses(std::string fileName, std::string fileOut, std::string dirIn, std::string dirOut){
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_transformed(new pcl::PointCloud<pcl::PointXYZ>);

	std::vector<Pose3d> poses;
	std::ifstream posFile(fileName);
	std::ofstream outFile(fileOut, std::ios::app);
	std::string line;
	int counter = 0;
	std::string constraint;

	if(!posFile.good()){
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}

	while(std::getline(posFile, line)){
		std::vector<std::string> strs;
		boost::split(strs, line, boost::is_any_of("\t "));
		double x = std::stod(strs.at(0)), y=std::stod(strs.at(1)), z = std::stod(strs.at(2)), yaw = std::stod(strs.at(3)), pitch = std::stod(strs.at(4)), roll = std::stod(strs.at(5));
		isam::Pose3d pose3d(x,y,z,yaw,pitch,roll);
		poses.push_back(pose3d);
	}

	for(int i = 0; i< poses.size(); i++){
		Pose3d current = poses[i];		
		pcl::io::loadPCDFile<pcl::PointXYZ>("/home/marcelo/rpg-navigation/software/recsys/src/pvis/" +	dirIn + std::to_string(i) + ".pcd", *cloud);
		Eigen::Matrix4d t = poses[i].oTw();
		pcl::transformPointCloud(*cloud, *cloud_transformed, t);
	        pcl::io::savePCDFileASCII("/home/marcelo/rpg-navigation/software/recsys/src/pvis/" + dirOut + std::to_string(i) + ".pcd", *cloud_transformed);

		if(i == 0)
			continue;
		Pose3d past = poses[i-1];
		Pose3d b = current.ominus(past);
			
		
		constraint =  "EDGE3 " + std::to_string(counter++) +  " " + std::to_string(counter+1) +" " + std::to_string(b.x()) + " " + std::to_string(b.y()) +  " " + std::to_string(b.z()) +  " " + std::to_string(b.roll()) +  " " + std::to_string(b.pitch()) + " " +std::to_string(b.yaw());
		constraint =  constraint +  "  10 0 0 0 0 0 10 0 0 0 0 10 0 0 0 100 0 0 100 0 25\n";
		outFile << constraint;
		
	
	}
}

int main(int argc, char **argv) {
	/* This script takes as input poses described in the format x y z yaw pitch roll and outputs in the format EDGE3 0 1 x y z yaw pitch roll cov. It also converts the point clouds to the world reference */
      
  ConciseArgs parser(argc, argv, "simple-fusion");
  std::string inF;
  std::string outF;
  std::string relativePathAICPClouds;
  std::string relativePathisamClouds;
  parser.add(inF, "i", "input_file", "input_file");
  parser.add(outF, "o", "output file", "output file");
  parser.add(relativePathAICPClouds, "a", "AICPClouds Directory", "The folder that holds the clouds in the relative reference");
  parser.add(relativePathisamClouds, "s", "isam-clouds directory", "The folder that holds the clouds in the global reference");
parser.parse();
 
 writePoses(inF, outF, relativePathAICPClouds, relativePathisamClouds);  

}
