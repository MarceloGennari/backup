#include "include/PoseCloud.hpp"

PoseCloud::PoseCloud(isam::Pose3d poseWorldFrame, pcl::PointCloud<pcl::PointXYZ> cloudWorldFrame){
	this->pose = poseWorldFrame;
	this->pointCloud = cloudWorldFrame;
	this->m_lcm = lcm_create(NULL);
	this->pc_vis_ = new pronto_vis(m_lcm);
}

PoseCloud::PoseCloud(double x, double y, double z, double roll, double pitch, double yaw, std::string PointCloudPath){
	isam::Pose3d p(x,y,z,yaw, pitch, roll);
	this->pose = p;
	pcl::PointCloud<pcl::PointXYZ> cloud;
	if( pcl::io::loadPCDFile<pcl::PointXYZ>(PointCloudPath, cloud) == -1){
		PCL_ERROR("Couldn't Read file PointCloud");
	}

	this->pointCloud = cloud;
	this->m_lcm = lcm_create(NULL);
	this->pc_vis_ = new pronto_vis(m_lcm);
}

PoseCloud::PoseCloud(double x, double y, double z, double roll, double pitch, double yaw, pcl::PointCloud<pcl::PointXYZ> cloud){
	isam::Pose3d p(x,y,z,yaw,pitch,roll);
	this->pose = p;
	this->pointCloud = cloud;
	this->m_lcm = lcm_create(NULL);
	this->pc_vis_ = new pronto_vis(m_lcm);
}

void PoseCloud::visPose( Viewer &v, int CollectionId, std::string nameChannel){
	ObjectCollection obj(CollectionId, nameChannel, VS_OBJECT_COLLECTION_T_AXIS3D);
	obj.add(1, coll::Pose3d(pose.x(), pose.y(), pose.z(), pose.yaw(), pose.pitch(), pose.roll()));
	v.sendCollection(obj, true);
}

void PoseCloud::visCloud( Viewer &v, int CollectionId, std::string nameChannel){
	
}

void PoseCloud::visPoseCloud(Viewer &v, int CollectionId, std::string nameChannel){

}
