# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program\clion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program\clion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CLion\communication\pipe_three

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\communication\pipe_three\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pipe_three.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/pipe_three.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipe_three.dir/flags.make

CMakeFiles/pipe_three.dir/main.c.obj: CMakeFiles/pipe_three.dir/flags.make
CMakeFiles/pipe_three.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\communication\pipe_three\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pipe_three.dir/main.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pipe_three.dir\main.c.obj -c E:\CLion\communication\pipe_three\main.c

CMakeFiles/pipe_three.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipe_three.dir/main.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\communication\pipe_three\main.c > CMakeFiles\pipe_three.dir\main.c.i

CMakeFiles/pipe_three.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipe_three.dir/main.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\communication\pipe_three\main.c -o CMakeFiles\pipe_three.dir\main.c.s

# Object files for target pipe_three
pipe_three_OBJECTS = \
"CMakeFiles/pipe_three.dir/main.c.obj"

# External object files for target pipe_three
pipe_three_EXTERNAL_OBJECTS =

pipe_three.exe: CMakeFiles/pipe_three.dir/main.c.obj
pipe_three.exe: CMakeFiles/pipe_three.dir/build.make
pipe_three.exe: CMakeFiles/pipe_three.dir/linklibs.rsp
pipe_three.exe: CMakeFiles/pipe_three.dir/objects1.rsp
pipe_three.exe: CMakeFiles/pipe_three.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\communication\pipe_three\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pipe_three.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pipe_three.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipe_three.dir/build: pipe_three.exe
.PHONY : CMakeFiles/pipe_three.dir/build

CMakeFiles/pipe_three.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pipe_three.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pipe_three.dir/clean

CMakeFiles/pipe_three.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\communication\pipe_three E:\CLion\communication\pipe_three E:\CLion\communication\pipe_three\cmake-build-debug E:\CLion\communication\pipe_three\cmake-build-debug E:\CLion\communication\pipe_three\cmake-build-debug\CMakeFiles\pipe_three.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipe_three.dir/depend

