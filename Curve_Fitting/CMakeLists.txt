project(curvefitting)
set(EXECUTABLE_OUTPUT_PATH ./bin)
set(LIBRARY_OUTPUT_PATH ./lib)


include_directories(./include)

add_library(libcurvefitting STATIC path/to/source/code/files/without/main.cpp)
add_executable(curveFitting path/to/source/code/files)

TARGET_LINK_LIBRARIES(curveFitting libgausselimination)
TARGET_LINK_LIBRARIES(libcurvefitting libgausselimination)