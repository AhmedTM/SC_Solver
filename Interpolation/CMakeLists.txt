project(interpolation)
set(EXECUTABLE_OUTPUT_PATH ./bin)
set(LIBRARY_OUTPUT_PATH ./lib)


include_directories(./include)

add_library(libinterpolation STATIC path/to/source/code/files)
add_executable(interpolation path/to/source/code/files)

TARGET_LINK_LIBRARIES(interpolation libgausselimination)
TARGET_LINK_LIBRARIES(libinterpolation libgausselimination)