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
CMAKE_SOURCE_DIR = E:\CLion\my_fs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\my_fs\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_fs.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/my_fs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_fs.dir/flags.make

CMakeFiles/my_fs.dir/main.c.obj: CMakeFiles/my_fs.dir/flags.make
CMakeFiles/my_fs.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\my_fs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_fs.dir/main.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\my_fs.dir\main.c.obj -c E:\CLion\my_fs\main.c

CMakeFiles/my_fs.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_fs.dir/main.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\my_fs\main.c > CMakeFiles\my_fs.dir\main.c.i

CMakeFiles/my_fs.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_fs.dir/main.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\my_fs\main.c -o CMakeFiles\my_fs.dir\main.c.s

CMakeFiles/my_fs.dir/init.c.obj: CMakeFiles/my_fs.dir/flags.make
CMakeFiles/my_fs.dir/init.c.obj: ../init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\my_fs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_fs.dir/init.c.obj"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\my_fs.dir\init.c.obj -c E:\CLion\my_fs\init.c

CMakeFiles/my_fs.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_fs.dir/init.c.i"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\CLion\my_fs\init.c > CMakeFiles\my_fs.dir\init.c.i

CMakeFiles/my_fs.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_fs.dir/init.c.s"
	D:\MinGw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\CLion\my_fs\init.c -o CMakeFiles\my_fs.dir\init.c.s

# Object files for target my_fs
my_fs_OBJECTS = \
"CMakeFiles/my_fs.dir/main.c.obj" \
"CMakeFiles/my_fs.dir/init.c.obj"

# External object files for target my_fs
my_fs_EXTERNAL_OBJECTS =

my_fs.exe: CMakeFiles/my_fs.dir/main.c.obj
my_fs.exe: CMakeFiles/my_fs.dir/init.c.obj
my_fs.exe: CMakeFiles/my_fs.dir/build.make
my_fs.exe: CMakeFiles/my_fs.dir/linklibs.rsp
my_fs.exe: CMakeFiles/my_fs.dir/objects1.rsp
my_fs.exe: CMakeFiles/my_fs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\my_fs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable my_fs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my_fs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_fs.dir/build: my_fs.exe
.PHONY : CMakeFiles/my_fs.dir/build

CMakeFiles/my_fs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my_fs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my_fs.dir/clean

CMakeFiles/my_fs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\my_fs E:\CLion\my_fs E:\CLion\my_fs\cmake-build-debug E:\CLion\my_fs\cmake-build-debug E:\CLion\my_fs\cmake-build-debug\CMakeFiles\my_fs.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_fs.dir/depend
