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
CMAKE_SOURCE_DIR = "/home/ilya/Рабочий стол/algoritm/lab_4/first"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp"

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/shortest_path_test.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/shortest_path_test.o: ../shortest_path_test.cpp
CMakeFiles/tests.dir/shortest_path_test.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/shortest_path_test.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/shortest_path_test.o -MF CMakeFiles/tests.dir/shortest_path_test.o.d -o CMakeFiles/tests.dir/shortest_path_test.o -c "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path_test.cpp"

CMakeFiles/tests.dir/shortest_path_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/shortest_path_test.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path_test.cpp" > CMakeFiles/tests.dir/shortest_path_test.i

CMakeFiles/tests.dir/shortest_path_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/shortest_path_test.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path_test.cpp" -o CMakeFiles/tests.dir/shortest_path_test.s

CMakeFiles/tests.dir/shortest_path.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/shortest_path.o: ../shortest_path.cpp
CMakeFiles/tests.dir/shortest_path.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/shortest_path.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/shortest_path.o -MF CMakeFiles/tests.dir/shortest_path.o.d -o CMakeFiles/tests.dir/shortest_path.o -c "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path.cpp"

CMakeFiles/tests.dir/shortest_path.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/shortest_path.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path.cpp" > CMakeFiles/tests.dir/shortest_path.i

CMakeFiles/tests.dir/shortest_path.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/shortest_path.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_4/first/shortest_path.cpp" -o CMakeFiles/tests.dir/shortest_path.s

CMakeFiles/tests.dir/graph.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/graph.o: ../graph.cpp
CMakeFiles/tests.dir/graph.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/graph.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/graph.o -MF CMakeFiles/tests.dir/graph.o.d -o CMakeFiles/tests.dir/graph.o -c "/home/ilya/Рабочий стол/algoritm/lab_4/first/graph.cpp"

CMakeFiles/tests.dir/graph.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/graph.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/algoritm/lab_4/first/graph.cpp" > CMakeFiles/tests.dir/graph.i

CMakeFiles/tests.dir/graph.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/graph.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/algoritm/lab_4/first/graph.cpp" -o CMakeFiles/tests.dir/graph.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/shortest_path_test.o" \
"CMakeFiles/tests.dir/shortest_path.o" \
"CMakeFiles/tests.dir/graph.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/shortest_path_test.o
tests: CMakeFiles/tests.dir/shortest_path.o
tests: CMakeFiles/tests.dir/graph.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/local/lib/libCatch2Main.a
tests: /usr/local/lib/libCatch2.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd "/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ilya/Рабочий стол/algoritm/lab_4/first" "/home/ilya/Рабочий стол/algoritm/lab_4/first" "/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp" "/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp" "/home/ilya/Рабочий стол/algoritm/lab_4/first/tmp/CMakeFiles/tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

