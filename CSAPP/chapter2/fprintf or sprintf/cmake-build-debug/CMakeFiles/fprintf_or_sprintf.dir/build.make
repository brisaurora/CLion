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
CMAKE_SOURCE_DIR = "E:\CLion\CSAPP\chapter2\fprintf or sprintf"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/fprintf_or_sprintf.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/fprintf_or_sprintf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fprintf_or_sprintf.dir/flags.make

CMakeFiles/fprintf_or_sprintf.dir/main.c.obj: CMakeFiles/fprintf_or_sprintf.dir/flags.make
CMakeFiles/fprintf_or_sprintf.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fprintf_or_sprintf.dir/main.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\fprintf_or_sprintf.dir\main.c.obj -c "E:\CLion\CSAPP\chapter2\fprintf or sprintf\main.c"

CMakeFiles/fprintf_or_sprintf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fprintf_or_sprintf.dir/main.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\CLion\CSAPP\chapter2\fprintf or sprintf\main.c" > CMakeFiles\fprintf_or_sprintf.dir\main.c.i

CMakeFiles/fprintf_or_sprintf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fprintf_or_sprintf.dir/main.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\CLion\CSAPP\chapter2\fprintf or sprintf\main.c" -o CMakeFiles\fprintf_or_sprintf.dir\main.c.s

# Object files for target fprintf_or_sprintf
fprintf_or_sprintf_OBJECTS = \
"CMakeFiles/fprintf_or_sprintf.dir/main.c.obj"

# External object files for target fprintf_or_sprintf
fprintf_or_sprintf_EXTERNAL_OBJECTS =

fprintf_or_sprintf.exe: CMakeFiles/fprintf_or_sprintf.dir/main.c.obj
fprintf_or_sprintf.exe: CMakeFiles/fprintf_or_sprintf.dir/build.make
fprintf_or_sprintf.exe: CMakeFiles/fprintf_or_sprintf.dir/linklibs.rsp
fprintf_or_sprintf.exe: CMakeFiles/fprintf_or_sprintf.dir/objects1.rsp
fprintf_or_sprintf.exe: CMakeFiles/fprintf_or_sprintf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fprintf_or_sprintf.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fprintf_or_sprintf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fprintf_or_sprintf.dir/build: fprintf_or_sprintf.exe
.PHONY : CMakeFiles/fprintf_or_sprintf.dir/build

CMakeFiles/fprintf_or_sprintf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fprintf_or_sprintf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fprintf_or_sprintf.dir/clean

CMakeFiles/fprintf_or_sprintf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CLion\CSAPP\chapter2\fprintf or sprintf" "E:\CLion\CSAPP\chapter2\fprintf or sprintf" "E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug" "E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug" "E:\CLion\CSAPP\chapter2\fprintf or sprintf\cmake-build-debug\CMakeFiles\fprintf_or_sprintf.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fprintf_or_sprintf.dir/depend

