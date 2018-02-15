#include <ConciseArgs>
#include <lcm/lcm.h>
#include <lcm/lcm-cpp.hpp>
#include <path.hpp>

#include <pronto_utils/pronto_math.hpp>
#include <pronto_utils/pronto_vis.hpp>

#include <lcmtypes/vs_object_collection_t.h>
#include <lcmtypes/vs_point3d_list_collection_t.h>

#include <bot_core/bot_core.h>


int main(int argc, char**argv){
	std::string filname = "";
	std::string cloudDir = "";
	int channelId = 85;
	std::string name = "Path Robot";

	ConciseArgs parser(argc, argv, "");
	parser.add(filname, "f", "File Name", "Poses File");
	parser.add(cloudDir, "cd", "Cloud Directory", "Cloud Directory path");
	parser.add(channelId, "i", "Channel ID", "The channel to be used");
	parser.add(name, "n", "Name", "The Name of the Channel");
	parser.parse();

	lcm_t *lcm;
	lcm = lcm_create(NULL);
	pronto_vis* pv_vis_;
	int obj_coll_id = 10000;
	obj_cfg oconfig = obj_cfg(obj_coll_id, "Poses", 5, 1);

	if(!lcm){
		std::cerr << "Failed to create lcm" << std::endl;
		return 1;
	}

	Viewer viewer(lcm);
	
	Path path(filname, cloudDir);
	path.visPath(lcm, channelId, name);
}
