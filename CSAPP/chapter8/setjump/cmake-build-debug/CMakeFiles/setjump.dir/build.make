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
CMAKE_SOURCE_DIR = /home/aurora/drive/CSAPP/chapter8/setjump

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/setjump.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/setjump.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/setjump.dir/flags.make

CMakeFiles/setjump.dir/main.c.o: CMakeFiles/setjump.dir/flags.make
CMakeFiles/setjump.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/setjump.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/setjump.dir/main.c.o   -c /home/aurora/drive/CSAPP/chapter8/setjump/main.c

CMakeFiles/setjump.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/setjump.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aurora/drive/CSAPP/chapter8/setjump/main.c > CMakeFiles/setjump.dir/main.c.i

CMakeFiles/setjump.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/setjump.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aurora/drive/CSAPP/chapter8/setjump/main.c -o CMakeFiles/setjump.dir/main.c.s

CMakeFiles/setjump.dir/main.c.o.requires:

.PHONY : CMakeFiles/setjump.dir/main.c.o.requires

CMakeFiles/setjump.dir/main.c.o.provides: CMakeFiles/setjump.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/setjump.dir/build.make CMakeFiles/setjump.dir/main.c.o.provides.build
.PHONY : CMakeFiles/setjump.dir/main.c.o.provides

CMakeFiles/setjump.dir/main.c.o.provides.build: CMakeFiles/setjump.dir/main.c.o


# Object files for target setjump
setjump_OBJECTS = \
"CMakeFiles/setjump.dir/main.c.o"

# External object files for target setjump
setjump_EXTERNAL_OBJECTS =

setjump: CMakeFiles/setjump.dir/main.c.o
setjump: CMakeFiles/setjump.dir/build.make
setjump: CMakeFiles/setjump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable setjump"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/setjump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/setjump.dir/build: setjump

.PHONY : CMakeFiles/setjump.dir/build

CMakeFiles/setjump.dir/requires: CMakeFiles/setjump.dir/main.c.o.requires

.PHONY : CMakeFiles/setjump.dir/requires

CMakeFiles/setjump.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/setjump.dir/cmake_clean.cmake
.PHONY : CMakeFiles/setjump.dir/clean

CMakeFiles/setjump.dir/depend:
	cd /home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aurora/drive/CSAPP/chapter8/setjump /home/aurora/drive/CSAPP/chapter8/setjump /home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug /home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug /home/aurora/drive/CSAPP/chapter8/setjump/cmake-build-debug/CMakeFiles/setjump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/setjump.dir/depend

