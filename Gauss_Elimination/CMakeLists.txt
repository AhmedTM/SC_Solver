cmake_minimum_required(VERSION 3.16)
project(gausselimination)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


include_directories(./include ${PROJECT_SOURCE_DIR})


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_library(vec src/vector.cpp)
add_executable(gaussElimination ${sources})#src/main.cpp src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)
add_library(libgausselimination STATIC src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)
target_link_libraries(gaussElimination vec)