cmake_minimum_required(VERSION 3.16)
project(gausselimination)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


include_directories(./include ${PROJECT_SOURCE_DIR})


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(gaussElimination ${sources})#src/main.cpp src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)