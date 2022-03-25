# project name
PROJECT(Scene)

# using C++11  环境
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3 -mtune=native ")

# cmake最低版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)


# eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

FIND_PACKAGE(OpenCV REQUIRED)

# show the message of OpenCV
message(STATUS "OpenCV library status:")
message(STATUS "    version: 	${OpenCV_VERSION}")
message(STATUS "    headers: 	${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: 	${OpenCV_LIBS}")

# link headers 链接头文件
INCLUDE_DIRECTORIES({OpenCV_INCLUDE_DIRS})

# rknn api
set(RKNN_API_PATH /home/agent/C-_Project/Test_Vs_Cmake/SimpleTest_Cmake/librknn_api)
include_directories(${RKNN_API_PATH}/include)
set(RKNN_API_LIB ${RKNN_API_PATH}/lib64/librknn_api.so)

# # opencv 1808/6
# set(OPENCV_PATH /home/agent/rk_test_project/examples/libs/opencv/opencv410_aarch64)
# include_directories(${OPENCV_PATH}/include)
# file(GLOB OPENCV_LIBS /home/agent/rk_test_project/examples/libs/opencv/opencv410_aarch64/lib64/*.so*)


add_executable (test_eigen src/main.cc)

# after ADD_EXECUTABLE，为生成文件target添加库，这个必须写在ADD_EXECUTABLE()之后，为生成文件target添加库。
# TARGET_LINK_LIBRARIES(target library1 <debug | optimized> library2...)
TARGET_LINK_LIBRARIES(test_eigen ${OpenCV_LIBS})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
