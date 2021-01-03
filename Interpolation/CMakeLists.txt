cmake_minimum_required(VERSION 3.16)
project(interpolation)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


include_directories(./include ${PROJECT_SOURCE_DIR}/src)


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(Interpolation ${sources})#src/main.cpp src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)
