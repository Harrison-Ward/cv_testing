cmake_minimum_required(VERSION 3.9)
project(AsciiProject)

# Set the path to the Homebrew-installed LLVM
set(LLVM_DIR "/usr/local/opt/llvm")

# Set the compilers
# set(CMAKE_C_COMPILER "${LLVM_DIR}/bin/clang")
# set(CMAKE_CXX_COMPILER "${LLVM_DIR}/bin/clang++")

# Find OpenCV
find_package(OpenCV 4.0.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Find OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executables
add_executable(ascii ascii.cpp image_processing.cpp)
add_executable(ascii_video_filter ascii_video_filter.cpp image_processing.cpp)
add_executable(ascii_gui ascii_gui.cpp image_processing.cpp)

# Link libraries for ascii target
target_link_libraries(ascii ${OpenCV_LIBS})
if(OpenMP_CXX_FOUND)
    target_link_libraries(ascii OpenMP::OpenMP_CXX)
endif()

# Link libraries for ascii_video_filter target
target_link_libraries(ascii_video_filter ${OpenCV_LIBS} sfml-graphics sfml-window sfml-system)
if(OpenMP_CXX_FOUND)
    target_link_libraries(ascii_video_filter OpenMP::OpenMP_CXX)
endif()

# Link libraries for ascii_gui target
target_link_libraries(ascii_gui ${OpenCV_LIBS} sfml-graphics sfml-window sfml-system)
if(OpenMP_CXX_FOUND)
    target_link_libraries(ascii_gui OpenMP::OpenMP_CXX)
endif()
