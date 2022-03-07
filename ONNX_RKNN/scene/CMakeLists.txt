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

# rknn api
set(RKNN_API_PATH ${CMAKE_SOURCE_DIR}/librknn_api)
include_directories(${RKNN_API_PATH}/include)
set(RKNN_API_LIB ${RKNN_API_PATH}/lib64/librknn_api.so)

# opencv
FIND_PACKAGE(OpenCV REQUIRED)

# show the message of OpenCV
message(STATUS "OpenCV library status:")
message(STATUS "    version: 	${OpenCV_VERSION}")
message(STATUS "    headers: 	${OpenCV_INCLUDE_DIRS}")
message(STATUS "    libraries: 	${OpenCV_LIBS}")

# link headers 链接头文件
INCLUDE_DIRECTORIES({OpenCV_INCLUDE_DIRS})

add_executable(rknn_class_infer
        src/main.cpp
        #src/opencv_test.cc
        #src/deeplabV3_test.cc
        #src/CDeeplabV3Segamentation.cc
        )

target_link_libraries(rknn_class_infer
	${RKNN_API_LIB}
	${OPENCV_LIBS}
  pthread
  dl
)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
