# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/aurora/drive/CSAPP/chapter8/sigjmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sigjmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sigjmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sigjmp.dir/flags.make

CMakeFiles/sigjmp.dir/main.c.o: CMakeFiles/sigjmp.dir/flags.make
CMakeFiles/sigjmp.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sigjmp.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sigjmp.dir/main.c.o   -c /home/aurora/drive/CSAPP/chapter8/sigjmp/main.c

CMakeFiles/sigjmp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sigjmp.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aurora/drive/CSAPP/chapter8/sigjmp/main.c > CMakeFiles/sigjmp.dir/main.c.i

CMakeFiles/sigjmp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sigjmp.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aurora/drive/CSAPP/chapter8/sigjmp/main.c -o CMakeFiles/sigjmp.dir/main.c.s

CMakeFiles/sigjmp.dir/main.c.o.requires:

.PHONY : CMakeFiles/sigjmp.dir/main.c.o.requires

CMakeFiles/sigjmp.dir/main.c.o.provides: CMakeFiles/sigjmp.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/sigjmp.dir/build.make CMakeFiles/sigjmp.dir/main.c.o.provides.build
.PHONY : CMakeFiles/sigjmp.dir/main.c.o.provides

CMakeFiles/sigjmp.dir/main.c.o.provides.build: CMakeFiles/sigjmp.dir/main.c.o


# Object files for target sigjmp
sigjmp_OBJECTS = \
"CMakeFiles/sigjmp.dir/main.c.o"

# External object files for target sigjmp
sigjmp_EXTERNAL_OBJECTS =

sigjmp: CMakeFiles/sigjmp.dir/main.c.o
sigjmp: CMakeFiles/sigjmp.dir/build.make
sigjmp: CMakeFiles/sigjmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sigjmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sigjmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sigjmp.dir/build: sigjmp

.PHONY : CMakeFiles/sigjmp.dir/build

CMakeFiles/sigjmp.dir/requires: CMakeFiles/sigjmp.dir/main.c.o.requires

.PHONY : CMakeFiles/sigjmp.dir/requires

CMakeFiles/sigjmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sigjmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sigjmp.dir/clean

CMakeFiles/sigjmp.dir/depend:
	cd /home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aurora/drive/CSAPP/chapter8/sigjmp /home/aurora/drive/CSAPP/chapter8/sigjmp /home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug /home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug /home/aurora/drive/CSAPP/chapter8/sigjmp/cmake-build-debug/CMakeFiles/sigjmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sigjmp.dir/depend

