# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/agent/rk_test_project/examples/rknn_mobilenet_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agent/rk_test_project/examples/rknn_mobilenet_demo/build

# Include any dependencies generated for this target.
include CMakeFiles/rknn_class_infer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rknn_class_infer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rknn_class_infer.dir/flags.make

CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o: CMakeFiles/rknn_class_infer.dir/flags.make
CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o: ../src/class_infer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agent/rk_test_project/examples/rknn_mobilenet_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o"
	/home/agent/aarch64-rockchip-linux-toolchain/bin/aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o -c /home/agent/rk_test_project/examples/rknn_mobilenet_demo/src/class_infer.cc

CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.i"
	/home/agent/aarch64-rockchip-linux-toolchain/bin/aarch64-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/agent/rk_test_project/examples/rknn_mobilenet_demo/src/class_infer.cc > CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.i

CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.s"
	/home/agent/aarch64-rockchip-linux-toolchain/bin/aarch64-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/agent/rk_test_project/examples/rknn_mobilenet_demo/src/class_infer.cc -o CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.s

# Object files for target rknn_class_infer
rknn_class_infer_OBJECTS = \
"CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o"

# External object files for target rknn_class_infer
rknn_class_infer_EXTERNAL_OBJECTS =

rknn_class_infer: CMakeFiles/rknn_class_infer.dir/src/class_infer.cc.o
rknn_class_infer: CMakeFiles/rknn_class_infer.dir/build.make
rknn_class_infer: ../../../librknn_api/lib64/librknn_api.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so.4.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so.4.1.0
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libz.so
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libz.so.1
rknn_class_infer: ../../libs/opencv/opencv410_aarch64/lib64/libz.so.1.2.11
rknn_class_infer: CMakeFiles/rknn_class_infer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/agent/rk_test_project/examples/rknn_mobilenet_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rknn_class_infer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rknn_class_infer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rknn_class_infer.dir/build: rknn_class_infer

.PHONY : CMakeFiles/rknn_class_infer.dir/build

CMakeFiles/rknn_class_infer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rknn_class_infer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rknn_class_infer.dir/clean

CMakeFiles/rknn_class_infer.dir/depend:
	cd /home/agent/rk_test_project/examples/rknn_mobilenet_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agent/rk_test_project/examples/rknn_mobilenet_demo /home/agent/rk_test_project/examples/rknn_mobilenet_demo /home/agent/rk_test_project/examples/rknn_mobilenet_demo/build /home/agent/rk_test_project/examples/rknn_mobilenet_demo/build /home/agent/rk_test_project/examples/rknn_mobilenet_demo/build/CMakeFiles/rknn_class_infer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rknn_class_infer.dir/depend
