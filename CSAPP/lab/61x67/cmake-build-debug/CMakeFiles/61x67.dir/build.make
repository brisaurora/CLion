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
CMAKE_SOURCE_DIR = E:\CLion\CSAPP\lab\61x67

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\CSAPP\lab\61x67\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/61x67.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/61x67.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/61x67.dir/flags.make

CMakeFiles/61x67.dir/main.c.obj: CMakeFiles/61x67.dir/flags.make
CMakeFiles/61x67.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\CSAPP\lab\61x67\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/61x67.dir/main.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\61x67.dir\main.c.obj -c E:\CLion\CSAPP\lab\61x67\main.c

CMakeFiles/61x67.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/61x67.dir/main.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\CSAPP\lab\61x67\main.c > CMakeFiles\61x67.dir\main.c.i

CMakeFiles/61x67.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/61x67.dir/main.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\CSAPP\lab\61x67\main.c -o CMakeFiles\61x67.dir\main.c.s

# Object files for target 61x67
61x67_OBJECTS = \
"CMakeFiles/61x67.dir/main.c.obj"

# External object files for target 61x67
61x67_EXTERNAL_OBJECTS =

61x67.exe: CMakeFiles/61x67.dir/main.c.obj
61x67.exe: CMakeFiles/61x67.dir/build.make
61x67.exe: CMakeFiles/61x67.dir/linklibs.rsp
61x67.exe: CMakeFiles/61x67.dir/objects1.rsp
61x67.exe: CMakeFiles/61x67.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\CSAPP\lab\61x67\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 61x67.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\61x67.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/61x67.dir/build: 61x67.exe
.PHONY : CMakeFiles/61x67.dir/build

CMakeFiles/61x67.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\61x67.dir\cmake_clean.cmake
.PHONY : CMakeFiles/61x67.dir/clean

CMakeFiles/61x67.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\CSAPP\lab\61x67 E:\CLion\CSAPP\lab\61x67 E:\CLion\CSAPP\lab\61x67\cmake-build-debug E:\CLion\CSAPP\lab\61x67\cmake-build-debug E:\CLion\CSAPP\lab\61x67\cmake-build-debug\CMakeFiles\61x67.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/61x67.dir/depend
