# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/ethan/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ethan/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ethan/Repositories/SudokuSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ethan/Repositories/SudokuSolver

# Include any dependencies generated for this target.
include CMakeFiles/SudokuSolver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SudokuSolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SudokuSolver.dir/flags.make

CMakeFiles/SudokuSolver.dir/main.c.o: CMakeFiles/SudokuSolver.dir/flags.make
CMakeFiles/SudokuSolver.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ethan/Repositories/SudokuSolver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SudokuSolver.dir/main.c.o"
	/home/linuxbrew/.linuxbrew/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SudokuSolver.dir/main.c.o   -c /home/ethan/Repositories/SudokuSolver/main.c

CMakeFiles/SudokuSolver.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SudokuSolver.dir/main.c.i"
	/home/linuxbrew/.linuxbrew/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ethan/Repositories/SudokuSolver/main.c > CMakeFiles/SudokuSolver.dir/main.c.i

CMakeFiles/SudokuSolver.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SudokuSolver.dir/main.c.s"
	/home/linuxbrew/.linuxbrew/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ethan/Repositories/SudokuSolver/main.c -o CMakeFiles/SudokuSolver.dir/main.c.s

# Object files for target SudokuSolver
SudokuSolver_OBJECTS = \
"CMakeFiles/SudokuSolver.dir/main.c.o"

# External object files for target SudokuSolver
SudokuSolver_EXTERNAL_OBJECTS =

SudokuSolver: CMakeFiles/SudokuSolver.dir/main.c.o
SudokuSolver: CMakeFiles/SudokuSolver.dir/build.make
SudokuSolver: CMakeFiles/SudokuSolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ethan/Repositories/SudokuSolver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SudokuSolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SudokuSolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SudokuSolver.dir/build: SudokuSolver

.PHONY : CMakeFiles/SudokuSolver.dir/build

CMakeFiles/SudokuSolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SudokuSolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SudokuSolver.dir/clean

CMakeFiles/SudokuSolver.dir/depend:
	cd /home/ethan/Repositories/SudokuSolver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ethan/Repositories/SudokuSolver /home/ethan/Repositories/SudokuSolver /home/ethan/Repositories/SudokuSolver /home/ethan/Repositories/SudokuSolver /home/ethan/Repositories/SudokuSolver/CMakeFiles/SudokuSolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SudokuSolver.dir/depend

