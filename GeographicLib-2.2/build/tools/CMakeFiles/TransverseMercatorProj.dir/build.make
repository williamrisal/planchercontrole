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
include tools/CMakeFiles/TransverseMercatorProj.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tools/CMakeFiles/TransverseMercatorProj.dir/compiler_depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/TransverseMercatorProj.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/TransverseMercatorProj.dir/flags.make

tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o: tools/CMakeFiles/TransverseMercatorProj.dir/flags.make
tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o: /Users/williamrisal/Documents/DGA\ projet/PlancherControle/GeographicLib-2.2/tools/TransverseMercatorProj.cpp
tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o: /Users/williamrisal/Documents/DGA\ projet/PlancherControle/GeographicLib-2.2/man/TransverseMercatorProj.usage
tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o: tools/CMakeFiles/TransverseMercatorProj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o -MF CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o.d -o CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o -c "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tools/TransverseMercatorProj.cpp"

tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.i"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tools/TransverseMercatorProj.cpp" > CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.i

tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.s"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tools/TransverseMercatorProj.cpp" -o CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.s

# Object files for target TransverseMercatorProj
TransverseMercatorProj_OBJECTS = \
"CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o"

# External object files for target TransverseMercatorProj
TransverseMercatorProj_EXTERNAL_OBJECTS =

tools/TransverseMercatorProj: tools/CMakeFiles/TransverseMercatorProj.dir/TransverseMercatorProj.cpp.o
tools/TransverseMercatorProj: tools/CMakeFiles/TransverseMercatorProj.dir/build.make
tools/TransverseMercatorProj: src/libGeographicLib.24.1.0.dylib
tools/TransverseMercatorProj: tools/CMakeFiles/TransverseMercatorProj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TransverseMercatorProj"
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TransverseMercatorProj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/TransverseMercatorProj.dir/build: tools/TransverseMercatorProj
.PHONY : tools/CMakeFiles/TransverseMercatorProj.dir/build

tools/CMakeFiles/TransverseMercatorProj.dir/clean:
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" && $(CMAKE_COMMAND) -P CMakeFiles/TransverseMercatorProj.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/TransverseMercatorProj.dir/clean

tools/CMakeFiles/TransverseMercatorProj.dir/depend:
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/tools" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/tools/CMakeFiles/TransverseMercatorProj.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tools/CMakeFiles/TransverseMercatorProj.dir/depend

