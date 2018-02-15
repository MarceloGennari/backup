# Install script for directory: /home/marcelo/rpg-navigation/software/recsys

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/marcelo/rpg-navigation/software/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/marcelo/rpg-navigation/software/recsys/pod-build/lib/liblcmtypes_motion_estimate.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_collection_config_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_text_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_link_collection_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_reset_collections_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_point3d_list_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_object_collection_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_cov_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_cov_collection_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_property_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_link_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_point3d_list_collection_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_color_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_object_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_text_collection_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/vs_point3d_t.h"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/c/lcmtypes/motion_estimate.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/pod-build/lib/pkgconfig/lcmtypes_motion_estimate.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/link_collection_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/cov_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/point3d_list_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/color_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/point3d_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/text_collection_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/reset_collections_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/object_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/text_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/object_collection_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/collection_config_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/link_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/point3d_list_collection_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/property_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/vs/cov_collection_t.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/cpp/lcmtypes/motion_estimate.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/java" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/pod-build/lcmtypes_motion_estimate.jar")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/link_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/link_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/object_collection_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/object_collection_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/text_collection_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/text_collection_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/link_collection_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/link_collection_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/reset_collections_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/reset_collections_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/__init__.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/point3d_list_collection_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/point3d_list_collection_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/text_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/text_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/collection_config_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/collection_config_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/object_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/object_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/point3d_list_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/point3d_list_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/color_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/color_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/cov_collection_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/cov_collection_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/point3d_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/point3d_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/property_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/property_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs/cov_t.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/vs" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/python/vs/cov_t.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lcmtypes" TYPE FILE FILES
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_object_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_point3d_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_collection_config_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_point3d_list_collection_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_link_collection_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_cov_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_text_collection_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_reset_collections_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_link_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_point3d_list_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_text_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_property_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_color_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_object_collection_t.lcm"
    "/home/marcelo/rpg-navigation/software/recsys/lcmtypes/vs_cov_collection_t.lcm"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/motion_estimate_scripts/spoof_driving_posture.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcelo/rpg-navigation/software/build/lib/python2.7/dist-packages/motion_estimate_scripts" TYPE FILE FILES "/home/marcelo/rpg-navigation/software/recsys/scripts/spoof_driving_posture.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/marcelo/rpg-navigation/software/recsys/pod-build/spoof-driving-posture")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/marcelo/rpg-navigation/software/recsys/pod-build/src/pvis/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/marcelo/rpg-navigation/software/recsys/pod-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
