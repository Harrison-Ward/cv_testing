# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/harrisonward/Desktop/CS/Git/vision/main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/harrisonward/Desktop/CS/Git/vision/main

# Include any dependencies generated for this target.
include CMakeFiles/ascii_video_filter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ascii_video_filter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ascii_video_filter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ascii_video_filter.dir/flags.make

CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o: CMakeFiles/ascii_video_filter.dir/flags.make
CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o: ascii_video_filter.cpp
CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o: CMakeFiles/ascii_video_filter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/harrisonward/Desktop/CS/Git/vision/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o -MF CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o.d -o CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o -c /Users/harrisonward/Desktop/CS/Git/vision/main/ascii_video_filter.cpp

CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/harrisonward/Desktop/CS/Git/vision/main/ascii_video_filter.cpp > CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.i

CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/harrisonward/Desktop/CS/Git/vision/main/ascii_video_filter.cpp -o CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.s

CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o: CMakeFiles/ascii_video_filter.dir/flags.make
CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o: image_processing.cpp
CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o: CMakeFiles/ascii_video_filter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/harrisonward/Desktop/CS/Git/vision/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o -MF CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o.d -o CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o -c /Users/harrisonward/Desktop/CS/Git/vision/main/image_processing.cpp

CMakeFiles/ascii_video_filter.dir/image_processing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ascii_video_filter.dir/image_processing.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/harrisonward/Desktop/CS/Git/vision/main/image_processing.cpp > CMakeFiles/ascii_video_filter.dir/image_processing.cpp.i

CMakeFiles/ascii_video_filter.dir/image_processing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ascii_video_filter.dir/image_processing.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/harrisonward/Desktop/CS/Git/vision/main/image_processing.cpp -o CMakeFiles/ascii_video_filter.dir/image_processing.cpp.s

# Object files for target ascii_video_filter
ascii_video_filter_OBJECTS = \
"CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o" \
"CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o"

# External object files for target ascii_video_filter
ascii_video_filter_EXTERNAL_OBJECTS =

ascii_video_filter: CMakeFiles/ascii_video_filter.dir/ascii_video_filter.cpp.o
ascii_video_filter: CMakeFiles/ascii_video_filter.dir/image_processing.cpp.o
ascii_video_filter: CMakeFiles/ascii_video_filter.dir/build.make
ascii_video_filter: /usr/local/lib/libopencv_gapi.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_stitching.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_alphamat.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_aruco.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_bgsegm.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_bioinspired.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_ccalib.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_dnn_objdetect.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_dnn_superres.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_dpm.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_face.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_freetype.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_fuzzy.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_hfs.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_img_hash.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_intensity_transform.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_line_descriptor.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_mcc.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_quality.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_rapid.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_reg.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_rgbd.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_saliency.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_sfm.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_stereo.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_structured_light.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_superres.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_surface_matching.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_tracking.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_videostab.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_viz.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_wechat_qrcode.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_xfeatures2d.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_xobjdetect.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_xphoto.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libsfml-graphics.2.6.1.dylib
ascii_video_filter: /usr/local/lib/libsfml-window.2.6.1.dylib
ascii_video_filter: /usr/local/lib/libsfml-system.2.6.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_shape.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_highgui.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_datasets.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_plot.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_text.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_ml.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_phase_unwrapping.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_optflow.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_ximgproc.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_video.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_videoio.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_imgcodecs.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_objdetect.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_calib3d.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_dnn.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_features2d.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_flann.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_photo.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_imgproc.4.8.1.dylib
ascii_video_filter: /usr/local/lib/libopencv_core.4.8.1.dylib
ascii_video_filter: /usr/local/opt/libomp/lib/libomp.dylib
ascii_video_filter: CMakeFiles/ascii_video_filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/harrisonward/Desktop/CS/Git/vision/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ascii_video_filter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ascii_video_filter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ascii_video_filter.dir/build: ascii_video_filter
.PHONY : CMakeFiles/ascii_video_filter.dir/build

CMakeFiles/ascii_video_filter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ascii_video_filter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ascii_video_filter.dir/clean

CMakeFiles/ascii_video_filter.dir/depend:
	cd /Users/harrisonward/Desktop/CS/Git/vision/main && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/harrisonward/Desktop/CS/Git/vision/main /Users/harrisonward/Desktop/CS/Git/vision/main /Users/harrisonward/Desktop/CS/Git/vision/main /Users/harrisonward/Desktop/CS/Git/vision/main /Users/harrisonward/Desktop/CS/Git/vision/main/CMakeFiles/ascii_video_filter.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ascii_video_filter.dir/depend

