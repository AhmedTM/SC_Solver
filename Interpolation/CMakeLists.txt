cmake_minimum_required(VERSION 3.16)
project(interpolation)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


include_directories(./include ${PROJECT_SOURCE_DIR})


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(interpolation ${sources})#src/main.cpp src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)
add_library(interpolation STATIC src/matrix.cpp src/vector.cpp include/matrix.h include/vector.h)