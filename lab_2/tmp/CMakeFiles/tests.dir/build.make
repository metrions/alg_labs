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
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/closest_pair.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/closest_pair.o: ../closest_pair.cpp
CMakeFiles/tests.dir/closest_pair.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/closest_pair.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/closest_pair.o -MF CMakeFiles/tests.dir/closest_pair.o.d -o CMakeFiles/tests.dir/closest_pair.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp"

CMakeFiles/tests.dir/closest_pair.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/closest_pair.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp" > CMakeFiles/tests.dir/closest_pair.i

CMakeFiles/tests.dir/closest_pair.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/closest_pair.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair.cpp" -o CMakeFiles/tests.dir/closest_pair.s

CMakeFiles/tests.dir/point.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/point.o: ../point.cpp
CMakeFiles/tests.dir/point.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/point.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/point.o -MF CMakeFiles/tests.dir/point.o.d -o CMakeFiles/tests.dir/point.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp"

CMakeFiles/tests.dir/point.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/point.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp" > CMakeFiles/tests.dir/point.i

CMakeFiles/tests.dir/point.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/point.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/point.cpp" -o CMakeFiles/tests.dir/point.s

CMakeFiles/tests.dir/closest_pair_test.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/closest_pair_test.o: ../closest_pair_test.cpp
CMakeFiles/tests.dir/closest_pair_test.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/closest_pair_test.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/closest_pair_test.o -MF CMakeFiles/tests.dir/closest_pair_test.o.d -o CMakeFiles/tests.dir/closest_pair_test.o -c "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp"

CMakeFiles/tests.dir/closest_pair_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/closest_pair_test.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp" > CMakeFiles/tests.dir/closest_pair_test.i

CMakeFiles/tests.dir/closest_pair_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/closest_pair_test.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_2/closest_pair_test.cpp" -o CMakeFiles/tests.dir/closest_pair_test.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/closest_pair.o" \
"CMakeFiles/tests.dir/point.o" \
"CMakeFiles/tests.dir/closest_pair_test.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/closest_pair.o
tests: CMakeFiles/tests.dir/point.o
tests: CMakeFiles/tests.dir/closest_pair_test.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/local/lib/libCatch2Main.a
tests: /usr/local/lib/libCatch2.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ilya/Рабочий стол/algoritm/lab_2" "/home/ilya/Рабочий стол/algoritm/lab_2" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp" "/home/ilya/Рабочий стол/algoritm/lab_2/tmp/CMakeFiles/tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

