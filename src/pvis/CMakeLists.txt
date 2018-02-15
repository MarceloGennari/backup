add_definitions( -ggdb3 -std=c++11  )

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(pvis)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(PkgConfig REQUIRED)

pkg_check_modules(BOT2_VIS bot2-vis)
if(NOT BOT2_VIS_FOUND)
    message("bot2-vis not found.  Not building libbot2 renderer")
    return()
endif(NOT BOT2_VIS_FOUND)

pkg_check_modules(PCL_IO pcl_io-1.7)
if(PCL_IO_FOUND)
  find_package(PCL 1.7 REQUIRED)#COMPONENTS common io)
  include_directories(${PCL_INCLUDE_DIRS})
  link_directories(${PCL_LIBRARY_DIRS})
  add_definitions(${PCL_DEFINITIONS})
  set(PCL_LIBRARIES pcl_io-1.7 pcl_common-1.7 pcl_filters-1.7 pcl_features-1.7 pcl_io-1.7 pcl_surface-1.7 pcl_segmentation-1.7 pcl_visualization-1.7 pcl_search-1.7 pcl_kdtree-1.7 pcl_keypoints-1.7)
endif()

pkg_check_modules(PCL_IO pcl_io-1.8)
if(PCL_IO_FOUND)
  find_package(PCL 1.8 REQUIRED)#COMPONENTS common io)
  include_directories(${PCL_INCLUDE_DIRS})
  link_directories(${PCL_LIBRARY_DIRS})
  add_definitions(${PCL_DEFINITIONS})
  set(PCL_LIBRARIES pcl_io-1.8 pcl_common-1.8 pcl_filters-1.8 pcl_features-1.8 pcl_io-1.8 pcl_surface-1.8 pcl_segmentation-1.8 pcl_visualization-1.8 pcl_search-1.8 pcl_kdtree-1.8 pcl_keypoints-1.8)
endif()

############## vo slam w/ relative lidar points
###############
add_executable(pvisualize main.cpp)
pods_use_pkg_config_packages(pvisualize pronto_vis pronto_math  eigen3 ${PCL_LIBRARIES})
target_link_libraries (pvisualize isam cholmod boost_system )
pods_install_executables(pvisualize)

############## vo slam w/ relative lidar points
###############
add_executable(convert conv.cpp)
pods_use_pkg_config_packages(convert pronto_vis pronto_math  eigen3 ${PCL_LIBRARIES})
target_link_libraries (convert isam cholmod boost_system )
pods_install_executables(convert)

############# Poses visualizer
set(CMAKE_CXX_FLAGS ${CMAKE_CSS_FLAGS} " -g")
add_executable(posesVisual pos.cpp)
pods_use_pkg_config_packages(posesVisual path-util eigen3 pronto_vis bot2-frames ${PCL_LIBRARIES})
target_link_libraries(posesVisual lcm boost_system boost_thread cloud_accumulate pthread yaml-cpp  pronto_vis cholmod boost_filesystem ${VTK_LIBRARIES} pronto_lidar_filters aicpRegistration aicpOverlap commonUtils pointmatcherUtils aicpClassification filteringUtils drawingUtils octrees-difference octomap pointmatcher)
pods_install_executables(posesVisual)

include_directories(include/)

############# Visualize Path
add_executable(visualize_path visPath.cpp path.cpp include/path.hpp PoseCloud.cpp include/PoseCloud.hpp)
pods_use_pkg_config_packages(visualize_path path-util eigen3 pronto_vis pronto_math bot2-frames ${PCL_LIBRARIES})
target_link_libraries(visualize_path lcm boost_system boost_thread cloud_accumulate pthread yaml-cpp  pronto_vis cholmod boost_filesystem ${VTK_LIBRARIES} pronto_lidar_filters aicpRegistration commonUtils pointmatcherUtils pointmatcher)
pods_install_executables(visualize_path)
