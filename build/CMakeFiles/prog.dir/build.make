# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/elizaveta/Рабочий стол/Технопа/hw"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/elizaveta/Рабочий стол/Технопа/hw/build"

# Include any dependencies generated for this target.
include CMakeFiles/prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/project/src/main.c.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/project/src/main.c.o: ../project/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/elizaveta/Рабочий стол/Технопа/hw/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prog.dir/project/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prog.dir/project/src/main.c.o   -c "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/main.c"

CMakeFiles/prog.dir/project/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prog.dir/project/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/main.c" > CMakeFiles/prog.dir/project/src/main.c.i

CMakeFiles/prog.dir/project/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prog.dir/project/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/main.c" -o CMakeFiles/prog.dir/project/src/main.c.s

CMakeFiles/prog.dir/project/src/read_write.c.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/project/src/read_write.c.o: ../project/src/read_write.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/elizaveta/Рабочий стол/Технопа/hw/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/prog.dir/project/src/read_write.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prog.dir/project/src/read_write.c.o   -c "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/read_write.c"

CMakeFiles/prog.dir/project/src/read_write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prog.dir/project/src/read_write.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/read_write.c" > CMakeFiles/prog.dir/project/src/read_write.c.i

CMakeFiles/prog.dir/project/src/read_write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prog.dir/project/src/read_write.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/read_write.c" -o CMakeFiles/prog.dir/project/src/read_write.c.s

CMakeFiles/prog.dir/project/src/task_structure.c.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/project/src/task_structure.c.o: ../project/src/task_structure.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/elizaveta/Рабочий стол/Технопа/hw/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/prog.dir/project/src/task_structure.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prog.dir/project/src/task_structure.c.o   -c "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/task_structure.c"

CMakeFiles/prog.dir/project/src/task_structure.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prog.dir/project/src/task_structure.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/task_structure.c" > CMakeFiles/prog.dir/project/src/task_structure.c.i

CMakeFiles/prog.dir/project/src/task_structure.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prog.dir/project/src/task_structure.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/elizaveta/Рабочий стол/Технопа/hw/project/src/task_structure.c" -o CMakeFiles/prog.dir/project/src/task_structure.c.s

# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/project/src/main.c.o" \
"CMakeFiles/prog.dir/project/src/read_write.c.o" \
"CMakeFiles/prog.dir/project/src/task_structure.c.o"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

prog: CMakeFiles/prog.dir/project/src/main.c.o
prog: CMakeFiles/prog.dir/project/src/read_write.c.o
prog: CMakeFiles/prog.dir/project/src/task_structure.c.o
prog: CMakeFiles/prog.dir/build.make
prog: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/elizaveta/Рабочий стол/Технопа/hw/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: prog

.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	cd "/home/elizaveta/Рабочий стол/Технопа/hw/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/elizaveta/Рабочий стол/Технопа/hw" "/home/elizaveta/Рабочий стол/Технопа/hw" "/home/elizaveta/Рабочий стол/Технопа/hw/build" "/home/elizaveta/Рабочий стол/Технопа/hw/build" "/home/elizaveta/Рабочий стол/Технопа/hw/build/CMakeFiles/prog.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/prog.dir/depend

