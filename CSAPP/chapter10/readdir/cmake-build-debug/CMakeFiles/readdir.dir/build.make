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
CMAKE_SOURCE_DIR = /home/aurora/drive/CSAPP/chapter10/readdir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/readdir.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/readdir.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/readdir.dir/flags.make

CMakeFiles/readdir.dir/main.c.o: CMakeFiles/readdir.dir/flags.make
CMakeFiles/readdir.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/readdir.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/readdir.dir/main.c.o   -c /home/aurora/drive/CSAPP/chapter10/readdir/main.c

CMakeFiles/readdir.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/readdir.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aurora/drive/CSAPP/chapter10/readdir/main.c > CMakeFiles/readdir.dir/main.c.i

CMakeFiles/readdir.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/readdir.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aurora/drive/CSAPP/chapter10/readdir/main.c -o CMakeFiles/readdir.dir/main.c.s

CMakeFiles/readdir.dir/main.c.o.requires:

.PHONY : CMakeFiles/readdir.dir/main.c.o.requires

CMakeFiles/readdir.dir/main.c.o.provides: CMakeFiles/readdir.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/readdir.dir/build.make CMakeFiles/readdir.dir/main.c.o.provides.build
.PHONY : CMakeFiles/readdir.dir/main.c.o.provides

CMakeFiles/readdir.dir/main.c.o.provides.build: CMakeFiles/readdir.dir/main.c.o


# Object files for target readdir
readdir_OBJECTS = \
"CMakeFiles/readdir.dir/main.c.o"

# External object files for target readdir
readdir_EXTERNAL_OBJECTS =

readdir: CMakeFiles/readdir.dir/main.c.o
readdir: CMakeFiles/readdir.dir/build.make
readdir: CMakeFiles/readdir.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable readdir"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/readdir.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/readdir.dir/build: readdir

.PHONY : CMakeFiles/readdir.dir/build

CMakeFiles/readdir.dir/requires: CMakeFiles/readdir.dir/main.c.o.requires

.PHONY : CMakeFiles/readdir.dir/requires

CMakeFiles/readdir.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/readdir.dir/cmake_clean.cmake
.PHONY : CMakeFiles/readdir.dir/clean

CMakeFiles/readdir.dir/depend:
	cd /home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aurora/drive/CSAPP/chapter10/readdir /home/aurora/drive/CSAPP/chapter10/readdir /home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug /home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug /home/aurora/drive/CSAPP/chapter10/readdir/cmake-build-debug/CMakeFiles/readdir.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/readdir.dir/depend

