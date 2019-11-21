# g++ -o build/testtest src/main.cpp src/utils.cpp -I./include -lk4a

set (PROJECT_NAME Streamer)
cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME} VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)


                  # add_library(utils STATIC src/utils.cpp include/utils.hpp)
# target_include_directories(utils PUBLIC include)
# target_compile_features(utils PUBLIC cxx_std_11)

add_executable(${PROJECT_NAME} src/main.cpp src/utils.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/include/pcl-1.8/)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include/eigen3)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/include/vtk-6.3/)

set(BUILD_SHARED_LIBS ON) # works fine even when commented

link_directories(/usr/lib/x86_64-linux-gnu/)

find_package(Boost COMPONENTS filesystem system REQUIRED)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

target_link_libraries (${PROJECT_NAME} k4a boost_system ${PCL_LIBRARIES})


# target_link_libraries(${PROJECT_NAME} PUBLIC 
#                         k4a
#                         pcl_io
#                         pcl_visualization
#                         pcl_common
#                         boost_system)

## --------------------------------------------------------------------------------
# FOR PCL Visualization
# http://pointclouds.org/documentation/tutorials/cloud_viewer.php
# cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# project(cloud_viewer)

# find_package(PCL 1.2 REQUIRED)

# include_directories(${PCL_INCLUDE_DIRS})
# link_directories(${PCL_LIBRARY_DIRS})
# add_definitions(${PCL_DEFINITIONS})

# add_executable (cloud_viewer cloud_viewer.cpp)
# target_link_libraries (cloud_viewer ${PCL_LIBRARIES})
## --------------------------------------------------------------------------------