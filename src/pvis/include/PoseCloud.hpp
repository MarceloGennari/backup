#include <isam/isam.h>

#include <lcmtypes/vs_object_collection_t.h>
#include <lcmtypes/vs_point3d_list_collection_t.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include <pronto_utils/pronto_vis.hpp>
#include "visualization/collections_math.hpp"
#include "visualization/viewer.hpp"
#include "visualization/pointcloud.hpp"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

class PoseCloud{
	public:
		/* Constructors */
		PoseCloud(isam::Pose3d poseWorldFrame, pcl::PointCloud<pcl::PointXYZ> cloudWorldFrame);
		PoseCloud(double x, double y, double z, double roll, double pitch, double yaw, std::string PointCloudPath);
		PoseCloud(double x, double y, double z, double roll, double pitch, double yaw, pcl::PointCloud<pcl::PointXYZ> cloud);
		
		/* Visualization */
		void visPose( Viewer &v, int CollectionId, std::string nameChannel);
		void visCloud( Viewer &v, int CollectionId, std::string nameChannel);
		void visPoseCloud( Viewer &v, int CollectionId, std::string nameChannel);
		
		/* Getters and Setters */
		isam::Pose3d getPose(){ return pose;};
	        pcl::PointCloud<pcl::PointXYZ> getCloud(){ return pointCloud;};
		
		void setPose(isam::Pose3d p){ this->pose = p;};
		void setCloud(pcl::PointCloud<pcl::PointXYZ> cloud){ this->pointCloud = cloud; };	

				
	private:
		/* Private Members */
		isam::Pose3d pose;
		pcl::PointCloud<pcl::PointXYZ> pointCloud;
		lcm_t* m_lcm;
		pronto_vis* pc_vis_;
};
