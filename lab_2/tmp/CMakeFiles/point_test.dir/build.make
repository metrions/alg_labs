# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ilya/Рабочий стол/algoritm/lab_2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ilya/Рабочий стол/algoritm/lab_2/tmp"

# Include any dependencies generated for this target.
include CMakeFiles/point_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/point_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/point_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/point_test.dir/flags.make

CMakeFiles/point_test.dir/closest_pair_test.cpp.o: CMakeFiles/point_test.dir/flags.make
CMakeFiles/point_test.dir/closest_pair_test.cpp.o: ../closest_pair_test.cpp
CMakeFiles/point_test.dir/closest_pair_test.cpp.o: CMakeFiles/point_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/point_test.dir/closest_pair_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/point_test.dir/closest_pair_test.cpp.o -MF CMakeFiles/point_test.dir/closest_pair_test.cpp.o.d -o CMakeFiles/point_test.dir/closest_pair_test.cpp.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp"

CMakeFiles/point_test.dir/closest_pair_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/point_test.dir/closest_pair_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp" > CMakeFiles/point_test.dir/closest_pair_test.cpp.i

CMakeFiles/point_test.dir/closest_pair_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/point_test.dir/closest_pair_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp" -o CMakeFiles/point_test.dir/closest_pair_test.cpp.s

CMakeFiles/point_test.dir/closest_pair.cpp.o: CMakeFiles/point_test.dir/flags.make
CMakeFiles/point_test.dir/closest_pair.cpp.o: ../closest_pair.cpp
CMakeFiles/point_test.dir/closest_pair.cpp.o: CMakeFiles/point_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/point_test.dir/closest_pair.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/point_test.dir/closest_pair.cpp.o -MF CMakeFiles/point_test.dir/closest_pair.cpp.o.d -o CMakeFiles/point_test.dir/closest_pair.cpp.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp"

CMakeFiles/point_test.dir/closest_pair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/point_test.dir/closest_pair.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp" > CMakeFiles/point_test.dir/closest_pair.cpp.i

CMakeFiles/point_test.dir/closest_pair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/point_test.dir/closest_pair.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp" -o CMakeFiles/point_test.dir/closest_pair.cpp.s

CMakeFiles/point_test.dir/point.cpp.o: CMakeFiles/point_test.dir/flags.make
CMakeFiles/point_test.dir/point.cpp.o: ../point.cpp
CMakeFiles/point_test.dir/point.cpp.o: CMakeFiles/point_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/point_test.dir/point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/point_test.dir/point.cpp.o -MF CMakeFiles/point_test.dir/point.cpp.o.d -o CMakeFiles/point_test.dir/point.cpp.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp"

CMakeFiles/point_test.dir/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/point_test.dir/point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp" > CMakeFiles/point_test.dir/point.cpp.i

CMakeFiles/point_test.dir/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/point_test.dir/point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp" -o CMakeFiles/point_test.dir/point.cpp.s

# Object files for target point_test
point_test_OBJECTS = \
"CMakeFiles/point_test.dir/closest_pair_test.cpp.o" \
"CMakeFiles/point_test.dir/closest_pair.cpp.o" \
"CMakeFiles/point_test.dir/point.cpp.o"

# External object files for target point_test
point_test_EXTERNAL_OBJECTS =

point_test: CMakeFiles/point_test.dir/closest_pair_test.cpp.o
point_test: CMakeFiles/point_test.dir/closest_pair.cpp.o
point_test: CMakeFiles/point_test.dir/point.cpp.o
point_test: CMakeFiles/point_test.dir/build.make
point_test: /usr/local/lib/libCatch2Main.a
point_test: /usr/local/lib/libCatch2.a
point_test: CMakeFiles/point_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable point_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/point_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/point_test.dir/build: point_test
.PHONY : CMakeFiles/point_test.dir/build

CMakeFiles/point_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/point_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/point_test.dir/clean

CMakeFiles/point_test.dir/depend:
	cd "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ilya/Рабочий стол/algoritm/lab_2" "/home/ilya/Рабочий стол/algoritm/lab_2" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles/point_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/point_test.dir/depend

