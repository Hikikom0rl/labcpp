# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/hikikomori/Documents/cpplabs/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hikikomori/Documents/cpplabs/lab3

# Include any dependencies generated for this target.
include CMakeFiles/diff.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/diff.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/diff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/diff.dir/flags.make

CMakeFiles/diff.dir/diff.cpp.o: CMakeFiles/diff.dir/flags.make
CMakeFiles/diff.dir/diff.cpp.o: diff.cpp
CMakeFiles/diff.dir/diff.cpp.o: CMakeFiles/diff.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hikikomori/Documents/cpplabs/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/diff.dir/diff.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/diff.dir/diff.cpp.o -MF CMakeFiles/diff.dir/diff.cpp.o.d -o CMakeFiles/diff.dir/diff.cpp.o -c /home/hikikomori/Documents/cpplabs/lab3/diff.cpp

CMakeFiles/diff.dir/diff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/diff.dir/diff.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hikikomori/Documents/cpplabs/lab3/diff.cpp > CMakeFiles/diff.dir/diff.cpp.i

CMakeFiles/diff.dir/diff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/diff.dir/diff.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hikikomori/Documents/cpplabs/lab3/diff.cpp -o CMakeFiles/diff.dir/diff.cpp.s

# Object files for target diff
diff_OBJECTS = \
"CMakeFiles/diff.dir/diff.cpp.o"

# External object files for target diff
diff_EXTERNAL_OBJECTS =

diff: CMakeFiles/diff.dir/diff.cpp.o
diff: CMakeFiles/diff.dir/build.make
diff: CMakeFiles/diff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hikikomori/Documents/cpplabs/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable diff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/diff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/diff.dir/build: diff
.PHONY : CMakeFiles/diff.dir/build

CMakeFiles/diff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/diff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/diff.dir/clean

CMakeFiles/diff.dir/depend:
	cd /home/hikikomori/Documents/cpplabs/lab3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hikikomori/Documents/cpplabs/lab3 /home/hikikomori/Documents/cpplabs/lab3 /home/hikikomori/Documents/cpplabs/lab3 /home/hikikomori/Documents/cpplabs/lab3 /home/hikikomori/Documents/cpplabs/lab3/CMakeFiles/diff.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/diff.dir/depend

