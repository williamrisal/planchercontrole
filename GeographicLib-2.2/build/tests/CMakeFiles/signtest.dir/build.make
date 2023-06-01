# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build"

# Include any dependencies generated for this target.
include tests/CMakeFiles/signtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/signtest.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/signtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/signtest.dir/flags.make

tests/CMakeFiles/signtest.dir/signtest.cpp.o: tests/CMakeFiles/signtest.dir/flags.make
tests/CMakeFiles/signtest.dir/signtest.cpp.o: /Users/williamrisal/Documents/DGA\ projet/PlancherControle/GeographicLib-2.2/tests/signtest.cpp
tests/CMakeFiles/signtest.dir/signtest.cpp.o: tests/CMakeFiles/signtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/signtest.dir/signtest.cpp.o"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/signtest.dir/signtest.cpp.o -MF CMakeFiles/signtest.dir/signtest.cpp.o.d -o CMakeFiles/signtest.dir/signtest.cpp.o -c "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tests/signtest.cpp"

tests/CMakeFiles/signtest.dir/signtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/signtest.dir/signtest.cpp.i"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tests/signtest.cpp" > CMakeFiles/signtest.dir/signtest.cpp.i

tests/CMakeFiles/signtest.dir/signtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/signtest.dir/signtest.cpp.s"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tests/signtest.cpp" -o CMakeFiles/signtest.dir/signtest.cpp.s

# Object files for target signtest
signtest_OBJECTS = \
"CMakeFiles/signtest.dir/signtest.cpp.o"

# External object files for target signtest
signtest_EXTERNAL_OBJECTS =

tests/signtest: tests/CMakeFiles/signtest.dir/signtest.cpp.o
tests/signtest: tests/CMakeFiles/signtest.dir/build.make
tests/signtest: src/libGeographicLib.24.1.0.dylib
tests/signtest: tests/CMakeFiles/signtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable signtest"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/signtest.dir/build: tests/signtest
.PHONY : tests/CMakeFiles/signtest.dir/build

tests/CMakeFiles/signtest.dir/clean:
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/signtest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/signtest.dir/clean

tests/CMakeFiles/signtest.dir/depend:
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tests" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tests/CMakeFiles/signtest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/signtest.dir/depend

