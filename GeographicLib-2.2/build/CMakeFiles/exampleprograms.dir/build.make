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

# Utility rule file for exampleprograms.

# Include any custom commands dependencies for this target.
include CMakeFiles/exampleprograms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exampleprograms.dir/progress.make

CMakeFiles/exampleprograms:
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -G Unix\ Makefiles -B exampleprograms -S /Users/williamrisal/Documents/DGA\ projet/PlancherControle/GeographicLib-2.2/examples -D USE_BOOST_FOR_EXAMPLES=OFF -D GeographicLib_DIR=/Users/williamrisal/Documents/DGA\ projet/PlancherControle/GeographicLib-2.2/build
	/opt/homebrew/Cellar/cmake/3.26.4/bin/cmake --build exampleprograms --parallel 8

exampleprograms: CMakeFiles/exampleprograms
exampleprograms: CMakeFiles/exampleprograms.dir/build.make
.PHONY : exampleprograms

# Rule to build all files generated by this target.
CMakeFiles/exampleprograms.dir/build: exampleprograms
.PHONY : CMakeFiles/exampleprograms.dir/build

CMakeFiles/exampleprograms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exampleprograms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exampleprograms.dir/clean

CMakeFiles/exampleprograms.dir/depend:
	cd "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build" "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CMakeFiles/exampleprograms.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exampleprograms.dir/depend

