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
CMAKE_SOURCE_DIR = /home/dev/algTraining/7_array_adts/array_adt_script

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev/algTraining/7_array_adts/array_adt_script/build

# Include any dependencies generated for this target.
include CMakeFiles/arrayGeneral.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/arrayGeneral.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/arrayGeneral.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrayGeneral.dir/flags.make

CMakeFiles/arrayGeneral.dir/main.c.o: CMakeFiles/arrayGeneral.dir/flags.make
CMakeFiles/arrayGeneral.dir/main.c.o: ../main.c
CMakeFiles/arrayGeneral.dir/main.c.o: CMakeFiles/arrayGeneral.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/algTraining/7_array_adts/array_adt_script/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arrayGeneral.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/arrayGeneral.dir/main.c.o -MF CMakeFiles/arrayGeneral.dir/main.c.o.d -o CMakeFiles/arrayGeneral.dir/main.c.o -c /home/dev/algTraining/7_array_adts/array_adt_script/main.c

CMakeFiles/arrayGeneral.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arrayGeneral.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dev/algTraining/7_array_adts/array_adt_script/main.c > CMakeFiles/arrayGeneral.dir/main.c.i

CMakeFiles/arrayGeneral.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arrayGeneral.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dev/algTraining/7_array_adts/array_adt_script/main.c -o CMakeFiles/arrayGeneral.dir/main.c.s

CMakeFiles/arrayGeneral.dir/arrayAdt.c.o: CMakeFiles/arrayGeneral.dir/flags.make
CMakeFiles/arrayGeneral.dir/arrayAdt.c.o: ../arrayAdt.c
CMakeFiles/arrayGeneral.dir/arrayAdt.c.o: CMakeFiles/arrayGeneral.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/algTraining/7_array_adts/array_adt_script/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/arrayGeneral.dir/arrayAdt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/arrayGeneral.dir/arrayAdt.c.o -MF CMakeFiles/arrayGeneral.dir/arrayAdt.c.o.d -o CMakeFiles/arrayGeneral.dir/arrayAdt.c.o -c /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdt.c

CMakeFiles/arrayGeneral.dir/arrayAdt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arrayGeneral.dir/arrayAdt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdt.c > CMakeFiles/arrayGeneral.dir/arrayAdt.c.i

CMakeFiles/arrayGeneral.dir/arrayAdt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arrayGeneral.dir/arrayAdt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdt.c -o CMakeFiles/arrayGeneral.dir/arrayAdt.c.s

CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o: CMakeFiles/arrayGeneral.dir/flags.make
CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o: ../arrayAdtSort.c
CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o: CMakeFiles/arrayGeneral.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev/algTraining/7_array_adts/array_adt_script/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o -MF CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o.d -o CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o -c /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdtSort.c

CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdtSort.c > CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.i

CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dev/algTraining/7_array_adts/array_adt_script/arrayAdtSort.c -o CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.s

# Object files for target arrayGeneral
arrayGeneral_OBJECTS = \
"CMakeFiles/arrayGeneral.dir/main.c.o" \
"CMakeFiles/arrayGeneral.dir/arrayAdt.c.o" \
"CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o"

# External object files for target arrayGeneral
arrayGeneral_EXTERNAL_OBJECTS =

arrayGeneral: CMakeFiles/arrayGeneral.dir/main.c.o
arrayGeneral: CMakeFiles/arrayGeneral.dir/arrayAdt.c.o
arrayGeneral: CMakeFiles/arrayGeneral.dir/arrayAdtSort.c.o
arrayGeneral: CMakeFiles/arrayGeneral.dir/build.make
arrayGeneral: CMakeFiles/arrayGeneral.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dev/algTraining/7_array_adts/array_adt_script/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable arrayGeneral"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrayGeneral.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arrayGeneral.dir/build: arrayGeneral
.PHONY : CMakeFiles/arrayGeneral.dir/build

CMakeFiles/arrayGeneral.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arrayGeneral.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arrayGeneral.dir/clean

CMakeFiles/arrayGeneral.dir/depend:
	cd /home/dev/algTraining/7_array_adts/array_adt_script/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev/algTraining/7_array_adts/array_adt_script /home/dev/algTraining/7_array_adts/array_adt_script /home/dev/algTraining/7_array_adts/array_adt_script/build /home/dev/algTraining/7_array_adts/array_adt_script/build /home/dev/algTraining/7_array_adts/array_adt_script/build/CMakeFiles/arrayGeneral.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrayGeneral.dir/depend

