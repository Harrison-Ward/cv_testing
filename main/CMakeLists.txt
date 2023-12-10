cmake_minimum_required(VERSION 3.9)
project(AsciiProject)

# Find OpenCV
find_package(OpenCV 4.0.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Find OpenMP
find_package(OpenMP REQUIRED)

# Add executables
add_executable(ascii ascii.cpp image_processing.cpp)
add_executable(ascii_video_filter ascii_video_filter.cpp image_processing.cpp)

# Link libraries for ascii target
if(OpenMP_CXX_FOUND)
    target_link_libraries(ascii ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
else()
    target_link_libraries(ascii ${OpenCV_LIBS})
endif()

# Link libraries for ascii_video_filter target
if(OpenMP_CXX_FOUND)
    target_link_libraries(ascii_video_filter ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
else()
    target_link_libraries(ascii_video_filter ${OpenCV_LIBS})
endif()
