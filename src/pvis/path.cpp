#include "include/path.hpp"

Path::Path(std::vector<PoseCloud> p){
	this->poses = p;
}

Path::Path(std::string posesFile, std::string cloudsDir){
	/**************
	 * This algorithm merely retrieves the poses and clouds from Disk and stores in the private variables
	 * ***********/
	readFile(posesFile, cloudsDir);
}

void Path::readFile(std::string fileName, std::string cloudsDir){
	std::ifstream posFile(fileName);
	std::string line;
	int counter = 0;

	if(!posFile.good()){
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}

	while(std::getline(posFile, line)){
		std::vector<std::string> strs;
		boost::split(strs, line, boost::is_any_of("\t "));
		double x = std::stod(strs.at(0)), y=std::stod(strs.at(1)), z = std::stod(strs.at(2)), yaw = std::stod(strs.at(3)), pitch = std::stod(strs.at(4)), roll = std::stod(strs.at(5));
		
		std::string cloudFile = cloudsDir + std::to_string(counter) + ".pcd";
		PoseCloud p(x,y,z,roll,pitch,yaw, cloudFile);
		poses.push_back(p);
		counter++;
	}
}

void Path::visPath(Viewer &v, int CollectionId, std::string nameChannel){
	ObjectCollection obj(CollectionId, nameChannel, VS_OBJECT_COLLECTION_T_AXIS3D);
	
	for(int i = 0; i<poses.size(); i++){
		obj.add(1+i, coll::Pose3d(poses[i].getPose().x(),
					  poses[i].getPose().y(),
					  poses[i].getPose().z(),
					  poses[i].getPose().yaw(),
					  poses[i].getPose().pitch(),
					  poses[i].getPose().roll()));
	}

	v.sendCollection(obj, true);
}

void Path::visCloud(lcm_t* lcm, int CollectionId, int idx){
	ptcld_cfg pconfig = ptcld_cfg(20000, "Clouds", 1, 1, CollectionId, 1, {255,255,255});
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::copyPointCloud(poses[idx].getCloud(), *cloud);

	for (size_t i = 0u; i<cloud->points.size(); ++i){
		cloud->points[i].r = 255;
		cloud->points[i].g = 255;
		cloud->points[i].b = 255;
	}

	pronto_vis* pc_vis_ = new pronto_vis( lcm);
	pc_vis_->ptcld_to_lcm(pconfig, *cloud, idx, idx);
}

void Path::visPath(lcm_t* lcm, int CollectionId, std::string nameChannel){
	vs_object_collection_t objs;
	size_t n = poses.size();
	if(n>1) {
		objs.id = CollectionId;
		objs.name = (char*)nameChannel.c_str();
		objs.type = VS_OBJECT_COLLECTION_T_AXIS3D;
		objs.reset = false;
		objs.nobjects = n;
		vs_object_t posesToPrint[n];
		for(size_t i = 0; i<n; i++){
			Eigen::Quaterniond quat = euler_to_quat(poses[i].getPose().roll(), poses[i].getPose().pitch(), poses[i].getPose().yaw());
			
			posesToPrint[i].id = i;
			posesToPrint[i].x = poses[i].getPose().x();
			posesToPrint[i].y = poses[i].getPose().y();
			posesToPrint[i].z = poses[i].getPose().z();
			posesToPrint[i].qw = quat.w();
			posesToPrint[i].qx = quat.x();
			posesToPrint[i].qy = quat.y();
			posesToPrint[i].qz = quat.z();

			visCloud(lcm, i, i);
		}

		objs.objects = posesToPrint;
		vs_object_collection_t_publish(lcm, "OBJECT_COLLECTION", &objs);
	}

}




void Path::push_back(PoseCloud p){
	poses.push_back(p);
}
