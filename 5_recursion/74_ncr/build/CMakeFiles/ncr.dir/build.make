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
CMAKE_SOURCE_DIR = /home/dev/algTraining/5_recursion/74_ncr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev/algTraining/5_recursion/74_ncr/build

# Include any dependencies generated for this target.
include CMakeFiles/ncr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ncr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ncr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ncr.dir/flags.make

CMakeFiles/ncr.dir/main.c.o: CMakeFiles/ncr.dir/flags.make
CMakeFiles/ncr.dir/main.c.o: ../main.c
CMakeFiles/ncr.dir/main.c.o: CMakeFiles/ncr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/algTraining/5_recursion/74_ncr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ncr.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ncr.dir/main.c.o -MF CMakeFiles/ncr.dir/main.c.o.d -o CMakeFiles/ncr.dir/main.c.o -c /home/dev/algTraining/5_recursion/74_ncr/main.c

CMakeFiles/ncr.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ncr.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dev/algTraining/5_recursion/74_ncr/main.c > CMakeFiles/ncr.dir/main.c.i

CMakeFiles/ncr.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ncr.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dev/algTraining/5_recursion/74_ncr/main.c -o CMakeFiles/ncr.dir/main.c.s

# Object files for target ncr
ncr_OBJECTS = \
"CMakeFiles/ncr.dir/main.c.o"

# External object files for target ncr
ncr_EXTERNAL_OBJECTS =

ncr: CMakeFiles/ncr.dir/main.c.o
ncr: CMakeFiles/ncr.dir/build.make
ncr: CMakeFiles/ncr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dev/algTraining/5_recursion/74_ncr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ncr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ncr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ncr.dir/build: ncr
.PHONY : CMakeFiles/ncr.dir/build

CMakeFiles/ncr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ncr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ncr.dir/clean

CMakeFiles/ncr.dir/depend:
	cd /home/dev/algTraining/5_recursion/74_ncr/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev/algTraining/5_recursion/74_ncr /home/dev/algTraining/5_recursion/74_ncr /home/dev/algTraining/5_recursion/74_ncr/build /home/dev/algTraining/5_recursion/74_ncr/build /home/dev/algTraining/5_recursion/74_ncr/build/CMakeFiles/ncr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ncr.dir/depend

