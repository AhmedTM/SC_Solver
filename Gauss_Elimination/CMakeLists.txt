project(gausselimination)
set(EXECUTABLE_OUTPUT_PATH ./bin)
set(LIBRARY_OUTPUT_PATH ./lib)


include_directories(./include)

add_library(libgausselimination STATIC path/to/source/code/files)
add_executable(gaussElimination path/to/source/code/files)