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
CMAKE_SOURCE_DIR = E:\CLion\leecode\three_num

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\leecode\three_num\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/three_num.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/three_num.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/three_num.dir/flags.make

CMakeFiles/three_num.dir/main.cpp.obj: CMakeFiles/three_num.dir/flags.make
CMakeFiles/three_num.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\leecode\three_num\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/three_num.dir/main.cpp.obj"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\three_num.dir\main.cpp.obj -c E:\CLion\leecode\three_num\main.cpp

CMakeFiles/three_num.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/three_num.dir/main.cpp.i"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CLion\leecode\three_num\main.cpp > CMakeFiles\three_num.dir\main.cpp.i

CMakeFiles/three_num.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/three_num.dir/main.cpp.s"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CLion\leecode\three_num\main.cpp -o CMakeFiles\three_num.dir\main.cpp.s

# Object files for target three_num
three_num_OBJECTS = \
"CMakeFiles/three_num.dir/main.cpp.obj"

# External object files for target three_num
three_num_EXTERNAL_OBJECTS =

three_num.exe: CMakeFiles/three_num.dir/main.cpp.obj
three_num.exe: CMakeFiles/three_num.dir/build.make
three_num.exe: CMakeFiles/three_num.dir/linklibs.rsp
three_num.exe: CMakeFiles/three_num.dir/objects1.rsp
three_num.exe: CMakeFiles/three_num.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\leecode\three_num\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable three_num.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\three_num.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/three_num.dir/build: three_num.exe
.PHONY : CMakeFiles/three_num.dir/build

CMakeFiles/three_num.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\three_num.dir\cmake_clean.cmake
.PHONY : CMakeFiles/three_num.dir/clean

CMakeFiles/three_num.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\leecode\three_num E:\CLion\leecode\three_num E:\CLion\leecode\three_num\cmake-build-debug E:\CLion\leecode\three_num\cmake-build-debug E:\CLion\leecode\three_num\cmake-build-debug\CMakeFiles\three_num.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/three_num.dir/depend

