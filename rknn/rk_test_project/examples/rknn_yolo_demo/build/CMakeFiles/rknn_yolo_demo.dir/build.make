# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build

# Include any dependencies generated for this target.
include CMakeFiles/rknn_yolo_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rknn_yolo_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rknn_yolo_demo.dir/flags.make

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o: CMakeFiles/rknn_yolo_demo.dir/flags.make
CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o: ../src/SCYolo3Detecor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o"
	aarch64-linux-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o -c /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolo3Detecor.cc

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.i"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolo3Detecor.cc > CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.i

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.s"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolo3Detecor.cc -o CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.s

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.requires:

.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.requires

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.provides: CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.requires
	$(MAKE) -f CMakeFiles/rknn_yolo_demo.dir/build.make CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.provides.build
.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.provides

CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.provides.build: CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o


CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o: CMakeFiles/rknn_yolo_demo.dir/flags.make
CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o: ../src/SCYolov3_post_process.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o"
	aarch64-linux-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o -c /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolov3_post_process.cc

CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.i"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolov3_post_process.cc > CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.i

CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.s"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/SCYolov3_post_process.cc -o CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.s

CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.requires:

.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.requires

CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.provides: CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.requires
	$(MAKE) -f CMakeFiles/rknn_yolo_demo.dir/build.make CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.provides.build
.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.provides

CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.provides.build: CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o


CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o: CMakeFiles/rknn_yolo_demo.dir/flags.make
CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o: ../src/test_yolo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o"
	aarch64-linux-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o -c /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/test_yolo.cc

CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.i"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/test_yolo.cc > CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.i

CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.s"
	aarch64-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/src/test_yolo.cc -o CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.s

CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.requires:

.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.requires

CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.provides: CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.requires
	$(MAKE) -f CMakeFiles/rknn_yolo_demo.dir/build.make CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.provides.build
.PHONY : CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.provides

CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.provides.build: CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o


# Object files for target rknn_yolo_demo
rknn_yolo_demo_OBJECTS = \
"CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o" \
"CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o" \
"CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o"

# External object files for target rknn_yolo_demo
rknn_yolo_demo_EXTERNAL_OBJECTS =

rknn_yolo_demo: CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o
rknn_yolo_demo: CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o
rknn_yolo_demo: CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o
rknn_yolo_demo: CMakeFiles/rknn_yolo_demo.dir/build.make
rknn_yolo_demo: ../../../librknn_api/lib64/librknn_api.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_calib3d.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_core.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_dnn.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_features2d.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_flann.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_gapi.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_highgui.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgcodecs.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_imgproc.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_ml.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_objdetect.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_photo.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_stitching.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_video.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so.4.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libopencv_videoio.so.4.1.0
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libz.so
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libz.so.1
rknn_yolo_demo: ../../libs/opencv/opencv410_aarch64/lib64/libz.so.1.2.11
rknn_yolo_demo: CMakeFiles/rknn_yolo_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable rknn_yolo_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rknn_yolo_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rknn_yolo_demo.dir/build: rknn_yolo_demo

.PHONY : CMakeFiles/rknn_yolo_demo.dir/build

CMakeFiles/rknn_yolo_demo.dir/requires: CMakeFiles/rknn_yolo_demo.dir/src/SCYolo3Detecor.cc.o.requires
CMakeFiles/rknn_yolo_demo.dir/requires: CMakeFiles/rknn_yolo_demo.dir/src/SCYolov3_post_process.cc.o.requires
CMakeFiles/rknn_yolo_demo.dir/requires: CMakeFiles/rknn_yolo_demo.dir/src/test_yolo.cc.o.requires

.PHONY : CMakeFiles/rknn_yolo_demo.dir/requires

CMakeFiles/rknn_yolo_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rknn_yolo_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rknn_yolo_demo.dir/clean

CMakeFiles/rknn_yolo_demo.dir/depend:
	cd /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build /home/zkj/Documents/Windows_Share/Windows_share_27F4/Board_workspace/rknn_board_test/rk_test_project/examples/rknn_yolo_demo/build/CMakeFiles/rknn_yolo_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rknn_yolo_demo.dir/depend
