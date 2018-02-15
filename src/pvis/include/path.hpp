#include <isam/isam.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include <pronto_utils/pronto_vis.hpp>
#include "visualization/collections_math.hpp"
#include "visualization/viewer.hpp"
#include "visualization/pointcloud.hpp"

#include "PoseCloud.hpp"

class Path {
	public:
		Path(){};
		Path(std::vector<PoseCloud> p);
		Path(std::string posesFile, std::string cloudsDir);
		
		/* Member Functions */
		void visPath(Viewer &v, int CollectionId, std::string nameChannel);
		void visPath(lcm_t* lcm, int CollectionId, std::string nameChannel);
		void visCloud(lcm_t* lcm, int CollectionId, int idx);
		void push_back(PoseCloud p);
		void push_back(isam::Pose3d);
		int size(){ return poses.size(); };

		/* Getters and Setters */
		PoseCloud get(int i){ return poses[i];};
		void set(int i, PoseCloud p){ poses[i] =  p; };		

	private:
		/* Member Variables */
		std::vector<PoseCloud> poses;
		
		/* Member Functions */
		void readFile(std::string fileName, std::string cloudsDir);
};
