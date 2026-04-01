cmake_minimum_required(VERSION 3.15)
project(KMeansVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SFML (assuming installed via brew on Mac)
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# Need to set up standard includes and our source folder
include_directories(src)

add_executable(KMeansVisualizer src/main.cpp src/Point.cpp src/Centroid.cpp src/KMeans.cpp)

target_link_libraries(KMeansVisualizer SFML::Graphics SFML::Window SFML::System)
