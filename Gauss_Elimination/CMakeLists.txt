project(gausselimination)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


include_directories(./include)

add_library(libgausselimination STATIC src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp)
add_executable(gaussElimination src/gauss_eliminiation.cpp src/matrix.cpp src/vector.cpp src/main.cpp)