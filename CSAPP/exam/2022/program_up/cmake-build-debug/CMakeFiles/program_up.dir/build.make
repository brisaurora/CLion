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
CMAKE_SOURCE_DIR = E:\CLion\CSAPP\exam\2022\program_up

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/program_up.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/program_up.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program_up.dir/flags.make

CMakeFiles/program_up.dir/main.c.obj: CMakeFiles/program_up.dir/flags.make
CMakeFiles/program_up.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/program_up.dir/main.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\program_up.dir\main.c.obj -c E:\CLion\CSAPP\exam\2022\program_up\main.c

CMakeFiles/program_up.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/program_up.dir/main.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\CSAPP\exam\2022\program_up\main.c > CMakeFiles\program_up.dir\main.c.i

CMakeFiles/program_up.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/program_up.dir/main.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\CSAPP\exam\2022\program_up\main.c -o CMakeFiles\program_up.dir\main.c.s

# Object files for target program_up
program_up_OBJECTS = \
"CMakeFiles/program_up.dir/main.c.obj"

# External object files for target program_up
program_up_EXTERNAL_OBJECTS =

program_up.exe: CMakeFiles/program_up.dir/main.c.obj
program_up.exe: CMakeFiles/program_up.dir/build.make
program_up.exe: CMakeFiles/program_up.dir/linklibs.rsp
program_up.exe: CMakeFiles/program_up.dir/objects1.rsp
program_up.exe: CMakeFiles/program_up.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable program_up.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\program_up.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program_up.dir/build: program_up.exe
.PHONY : CMakeFiles/program_up.dir/build

CMakeFiles/program_up.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\program_up.dir\cmake_clean.cmake
.PHONY : CMakeFiles/program_up.dir/clean

CMakeFiles/program_up.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\CSAPP\exam\2022\program_up E:\CLion\CSAPP\exam\2022\program_up E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug E:\CLion\CSAPP\exam\2022\program_up\cmake-build-debug\CMakeFiles\program_up.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/program_up.dir/depend

