cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(interface)


set(CMAKE_CXX_STANDARD 14) # fix: error: ‘plus’ is not a member of ‘pcl::traits’

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# include_directories(
#   include
#   ${catkin_INCLUDE_DIRS}
#   ${OpenCV_LIBRARIES}
#   ${PCL_INCLUDE_DIRS}
# )



add_executable (demo main.cpp interface.cpp) # 所有cpp文件加上must
target_link_libraries (demo ${PCL_LIBRARIES}  ${OpenCV_LIBRARIES})




