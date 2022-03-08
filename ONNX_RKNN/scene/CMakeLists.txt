cmake_minimum_required(VERSION 3.4.1)

project(rknn_class_infer_linux)

set(CMAKE_SYSTEM_NAME Linux)
add_definitions(-w)
# for aarch64
#set(CROSS_COMPILE_TOOL ${CMAKE_SOURCE_DIR}/../../../../../../prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu)

# for armhf
# set(CROSS_COMPILE_TOOL ${CMAKE_SOURCE_DIR}/../../../../../../prebuilts/gcc/linux-x86/arm/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf)

#1126
# set(CROSS_COMPILE_TOOL /home/zkj/Documents/Windows_Share/Windows_share/1126-cross-compile-tool/gcc-arm-linux-gnueabihf/bin/arm-linux-gnueabihf)
# set(CROSS_COMPILE_TOOL /home/xiang/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf-master/bin/arm-linux-gnueabihf)
set(CMAKE_C_COMPILER ${CROSS_COMPILE_TOOL}-gcc)
set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_TOOL}-g++)

#1806/1808
#set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
#set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

#SET(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
#SET(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (CMAKE_C_COMPILER MATCHES "aarch64")
  MESSAGE(STATUS "64--------------")
  set(LIB_ARCH lib64)
else()
  MESSAGE(STATUS "32--------------")
  set(LIB_ARCH lib)
endif()

# rknn api
set(RKNN_API_PATH ${CMAKE_SOURCE_DIR}/librknn_api)
include_directories(${RKNN_API_PATH}/include)
set(RKNN_API_LIB ${RKNN_API_PATH}/${LIB_ARCH}/librknn_api.so)

# opencv
set(OPENCV_PATH ${CMAKE_SOURCE_DIR}/libs/opencv/opencv410_arm32)
include_directories(${OPENCV_PATH}/include)
include_directories(${OPENCV_PATH}/include/opencv4/)
include_directories(${OPENCV_PATH}/include/opencv4/opencv2)
#file(GLOB OPENCV_LIBS ${OPENCV_PATH}/${LIB_ARCH}/*.so*)
#file(GLOB OPENCV_LIBS ${OPENCV_PATH}/lib/*.so*)
#file(GLOB OPENCV_STATIC_LIBS ${OPENCV_PATH}/lib/*.so*)

SET(OPENCV_LIBS
			${OPENCV_PATH}/lib/libopencv_world.so
			${OPENCV_PATH}/lib/opencv4/3rdparty/liblibjpeg-turbo.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/libade.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/libIlmImf.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/liblibjasper.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/liblibjpeg-turbo.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/liblibtiff.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/liblibwebp.a
			${OPENCV_PATH}/lib/opencv4/3rdparty/libquirc.a 
			${OPENCV_PATH}/lib/opencv4/3rdparty/libzlib.a
			)

set(CMAKE_INSTALL_RPATH "lib")

# add_executable(rknn_class_infer
#         src/main.cpp
#         #src/opencv_test.cc
#         #src/deeplabV3_test.cc
#         #src/CDeeplabV3Segamentation.cc
#         )

AUX_SOURCE_DIRECTORY(src/main.cpp SRC_LIST)

# 这里又出现一个新的命令set，是用于定义变量的，EXECUTABLE_OUT_PATH和PROJECT_SOURCE_DIR是CMake自带的预定义变量，其意义如下，
# EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
# PROJECT_SOURCE_DIR：工程的根目录
# 所以，这里set的意思是把存放elf文件的位置设置为工程根目录下的bin目录。（cmake有很多预定义变量，详细的可以网上搜索一下）

# add_library(includeT test SHARED ${SRC})

# 生成可执行文件
add_executable (test_eigen ${SRC_LIST})
		
target_link_libraries(test_eigen
	${RKNN_API_LIB}
	${OPENCV_LIBS}
  pthread
  dl
)

# install target and libraries
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/test_eigen)
install(TARGETS test_eigen DESTINATION ./)
install(FILES model/SceneResnet18_18pth.rknn DESTINATION ./)
install(FILES model/1.jpg DESTINATION ./)

install(PROGRAMS ${RKNN_API_LIB} DESTINATION lib)
install(PROGRAMS ${OPENCV_LIBS} DESTINATION lib)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
