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
CMAKE_SOURCE_DIR = /home/dev/algTraining/5_recursion/67_taylor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev/algTraining/5_recursion/67_taylor/build

# Include any dependencies generated for this target.
include CMakeFiles/sumNaturalNumbers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sumNaturalNumbers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sumNaturalNumbers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sumNaturalNumbers.dir/flags.make

CMakeFiles/sumNaturalNumbers.dir/main.c.o: CMakeFiles/sumNaturalNumbers.dir/flags.make
CMakeFiles/sumNaturalNumbers.dir/main.c.o: ../main.c
CMakeFiles/sumNaturalNumbers.dir/main.c.o: CMakeFiles/sumNaturalNumbers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/algTraining/5_recursion/67_taylor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sumNaturalNumbers.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sumNaturalNumbers.dir/main.c.o -MF CMakeFiles/sumNaturalNumbers.dir/main.c.o.d -o CMakeFiles/sumNaturalNumbers.dir/main.c.o -c /home/dev/algTraining/5_recursion/67_taylor/main.c

CMakeFiles/sumNaturalNumbers.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sumNaturalNumbers.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dev/algTraining/5_recursion/67_taylor/main.c > CMakeFiles/sumNaturalNumbers.dir/main.c.i

CMakeFiles/sumNaturalNumbers.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sumNaturalNumbers.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dev/algTraining/5_recursion/67_taylor/main.c -o CMakeFiles/sumNaturalNumbers.dir/main.c.s

# Object files for target sumNaturalNumbers
sumNaturalNumbers_OBJECTS = \
"CMakeFiles/sumNaturalNumbers.dir/main.c.o"

# External object files for target sumNaturalNumbers
sumNaturalNumbers_EXTERNAL_OBJECTS =

sumNaturalNumbers: CMakeFiles/sumNaturalNumbers.dir/main.c.o
sumNaturalNumbers: CMakeFiles/sumNaturalNumbers.dir/build.make
sumNaturalNumbers: CMakeFiles/sumNaturalNumbers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dev/algTraining/5_recursion/67_taylor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sumNaturalNumbers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sumNaturalNumbers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sumNaturalNumbers.dir/build: sumNaturalNumbers
.PHONY : CMakeFiles/sumNaturalNumbers.dir/build

CMakeFiles/sumNaturalNumbers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sumNaturalNumbers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sumNaturalNumbers.dir/clean

CMakeFiles/sumNaturalNumbers.dir/depend:
	cd /home/dev/algTraining/5_recursion/67_taylor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev/algTraining/5_recursion/67_taylor /home/dev/algTraining/5_recursion/67_taylor /home/dev/algTraining/5_recursion/67_taylor/build /home/dev/algTraining/5_recursion/67_taylor/build /home/dev/algTraining/5_recursion/67_taylor/build/CMakeFiles/sumNaturalNumbers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sumNaturalNumbers.dir/depend

