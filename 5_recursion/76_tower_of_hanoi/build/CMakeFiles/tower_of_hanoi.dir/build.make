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
CMAKE_SOURCE_DIR = /home/jbates/algtraining/5_recursion/76_tower_of_hanoi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build

# Include any dependencies generated for this target.
include CMakeFiles/tower_of_hanoi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tower_of_hanoi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tower_of_hanoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tower_of_hanoi.dir/flags.make

CMakeFiles/tower_of_hanoi.dir/main.c.o: CMakeFiles/tower_of_hanoi.dir/flags.make
CMakeFiles/tower_of_hanoi.dir/main.c.o: ../main.c
CMakeFiles/tower_of_hanoi.dir/main.c.o: CMakeFiles/tower_of_hanoi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tower_of_hanoi.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tower_of_hanoi.dir/main.c.o -MF CMakeFiles/tower_of_hanoi.dir/main.c.o.d -o CMakeFiles/tower_of_hanoi.dir/main.c.o -c /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/main.c

CMakeFiles/tower_of_hanoi.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tower_of_hanoi.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/main.c > CMakeFiles/tower_of_hanoi.dir/main.c.i

CMakeFiles/tower_of_hanoi.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tower_of_hanoi.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/main.c -o CMakeFiles/tower_of_hanoi.dir/main.c.s

# Object files for target tower_of_hanoi
tower_of_hanoi_OBJECTS = \
"CMakeFiles/tower_of_hanoi.dir/main.c.o"

# External object files for target tower_of_hanoi
tower_of_hanoi_EXTERNAL_OBJECTS =

tower_of_hanoi: CMakeFiles/tower_of_hanoi.dir/main.c.o
tower_of_hanoi: CMakeFiles/tower_of_hanoi.dir/build.make
tower_of_hanoi: CMakeFiles/tower_of_hanoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tower_of_hanoi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tower_of_hanoi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tower_of_hanoi.dir/build: tower_of_hanoi
.PHONY : CMakeFiles/tower_of_hanoi.dir/build

CMakeFiles/tower_of_hanoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tower_of_hanoi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tower_of_hanoi.dir/clean

CMakeFiles/tower_of_hanoi.dir/depend:
	cd /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jbates/algtraining/5_recursion/76_tower_of_hanoi /home/jbates/algtraining/5_recursion/76_tower_of_hanoi /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build /home/jbates/algtraining/5_recursion/76_tower_of_hanoi/build/CMakeFiles/tower_of_hanoi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tower_of_hanoi.dir/depend

