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
CMAKE_SOURCE_DIR = /home/xewii/projects/misc/sfst

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xewii/projects/misc/sfst/build

# Include any dependencies generated for this target.
include test/CMakeFiles/Screen_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/Screen_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Screen_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Screen_test.dir/flags.make

test/CMakeFiles/Screen_test.dir/Screen.cpp.o: test/CMakeFiles/Screen_test.dir/flags.make
test/CMakeFiles/Screen_test.dir/Screen.cpp.o: ../test/Screen.cpp
test/CMakeFiles/Screen_test.dir/Screen.cpp.o: test/CMakeFiles/Screen_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xewii/projects/misc/sfst/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Screen_test.dir/Screen.cpp.o"
	cd /home/xewii/projects/misc/sfst/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Screen_test.dir/Screen.cpp.o -MF CMakeFiles/Screen_test.dir/Screen.cpp.o.d -o CMakeFiles/Screen_test.dir/Screen.cpp.o -c /home/xewii/projects/misc/sfst/test/Screen.cpp

test/CMakeFiles/Screen_test.dir/Screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Screen_test.dir/Screen.cpp.i"
	cd /home/xewii/projects/misc/sfst/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xewii/projects/misc/sfst/test/Screen.cpp > CMakeFiles/Screen_test.dir/Screen.cpp.i

test/CMakeFiles/Screen_test.dir/Screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Screen_test.dir/Screen.cpp.s"
	cd /home/xewii/projects/misc/sfst/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xewii/projects/misc/sfst/test/Screen.cpp -o CMakeFiles/Screen_test.dir/Screen.cpp.s

# Object files for target Screen_test
Screen_test_OBJECTS = \
"CMakeFiles/Screen_test.dir/Screen.cpp.o"

# External object files for target Screen_test
Screen_test_EXTERNAL_OBJECTS =

test/Screen_test: test/CMakeFiles/Screen_test.dir/Screen.cpp.o
test/Screen_test: test/CMakeFiles/Screen_test.dir/build.make
test/Screen_test: lib-sfst.so.
test/Screen_test: lib/libgtest_main.a
test/Screen_test: /usr/lib/libsfml-graphics.so.2.5.1
test/Screen_test: /usr/lib/libsfml-window.so.2.5.1
test/Screen_test: /usr/lib/libsfml-audio.so.2.5.1
test/Screen_test: /usr/lib/libsfml-system.so.2.5.1
test/Screen_test: lib/libgtest.a
test/Screen_test: test/CMakeFiles/Screen_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xewii/projects/misc/sfst/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Screen_test"
	cd /home/xewii/projects/misc/sfst/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Screen_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/xewii/projects/misc/sfst/build/test && /usr/bin/cmake -D TEST_TARGET=Screen_test -D TEST_EXECUTABLE=/home/xewii/projects/misc/sfst/build/test/Screen_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/xewii/projects/misc/sfst/build/test -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=Screen_test_TESTS -D CTEST_FILE=/home/xewii/projects/misc/sfst/build/test/Screen_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/Screen_test.dir/build: test/Screen_test
.PHONY : test/CMakeFiles/Screen_test.dir/build

test/CMakeFiles/Screen_test.dir/clean:
	cd /home/xewii/projects/misc/sfst/build/test && $(CMAKE_COMMAND) -P CMakeFiles/Screen_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Screen_test.dir/clean

test/CMakeFiles/Screen_test.dir/depend:
	cd /home/xewii/projects/misc/sfst/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xewii/projects/misc/sfst /home/xewii/projects/misc/sfst/test /home/xewii/projects/misc/sfst/build /home/xewii/projects/misc/sfst/build/test /home/xewii/projects/misc/sfst/build/test/CMakeFiles/Screen_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Screen_test.dir/depend

