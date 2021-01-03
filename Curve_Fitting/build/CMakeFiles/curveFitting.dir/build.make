# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build

# Include any dependencies generated for this target.
include CMakeFiles/curveFitting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/curveFitting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/curveFitting.dir/flags.make

CMakeFiles/curveFitting.dir/src/converters.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/converters.cpp.o: ../src/converters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/curveFitting.dir/src/converters.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/converters.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/converters.cpp

CMakeFiles/curveFitting.dir/src/converters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/converters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/converters.cpp > CMakeFiles/curveFitting.dir/src/converters.cpp.i

CMakeFiles/curveFitting.dir/src/converters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/converters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/converters.cpp -o CMakeFiles/curveFitting.dir/src/converters.cpp.s

CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o: ../src/linear_algerbra_ops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/linear_algerbra_ops.cpp

CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/linear_algerbra_ops.cpp > CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.i

CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/linear_algerbra_ops.cpp -o CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.s

CMakeFiles/curveFitting.dir/src/main.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/curveFitting.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/main.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/main.cpp

CMakeFiles/curveFitting.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/main.cpp > CMakeFiles/curveFitting.dir/src/main.cpp.i

CMakeFiles/curveFitting.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/main.cpp -o CMakeFiles/curveFitting.dir/src/main.cpp.s

CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o: ../src/multlivariable_linear_regression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/multlivariable_linear_regression.cpp

CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/multlivariable_linear_regression.cpp > CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.i

CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/multlivariable_linear_regression.cpp -o CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.s

CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o: ../src/polynomial_regression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/polynomial_regression.cpp

CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/polynomial_regression.cpp > CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.i

CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/polynomial_regression.cpp -o CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.s

CMakeFiles/curveFitting.dir/src/read_csv.cpp.o: CMakeFiles/curveFitting.dir/flags.make
CMakeFiles/curveFitting.dir/src/read_csv.cpp.o: ../src/read_csv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/curveFitting.dir/src/read_csv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curveFitting.dir/src/read_csv.cpp.o -c /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/read_csv.cpp

CMakeFiles/curveFitting.dir/src/read_csv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curveFitting.dir/src/read_csv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/read_csv.cpp > CMakeFiles/curveFitting.dir/src/read_csv.cpp.i

CMakeFiles/curveFitting.dir/src/read_csv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curveFitting.dir/src/read_csv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/src/read_csv.cpp -o CMakeFiles/curveFitting.dir/src/read_csv.cpp.s

# Object files for target curveFitting
curveFitting_OBJECTS = \
"CMakeFiles/curveFitting.dir/src/converters.cpp.o" \
"CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o" \
"CMakeFiles/curveFitting.dir/src/main.cpp.o" \
"CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o" \
"CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o" \
"CMakeFiles/curveFitting.dir/src/read_csv.cpp.o"

# External object files for target curveFitting
curveFitting_EXTERNAL_OBJECTS =

../bin/curveFitting: CMakeFiles/curveFitting.dir/src/converters.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/src/linear_algerbra_ops.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/src/main.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/src/multlivariable_linear_regression.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/src/polynomial_regression.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/src/read_csv.cpp.o
../bin/curveFitting: CMakeFiles/curveFitting.dir/build.make
../bin/curveFitting: CMakeFiles/curveFitting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../bin/curveFitting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/curveFitting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/curveFitting.dir/build: ../bin/curveFitting

.PHONY : CMakeFiles/curveFitting.dir/build

CMakeFiles/curveFitting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/curveFitting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/curveFitting.dir/clean

CMakeFiles/curveFitting.dir/depend:
	cd /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build /home/ahmedtarek/Scientific_Computing/SC_Solver/Curve_Fitting/build/CMakeFiles/curveFitting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/curveFitting.dir/depend
