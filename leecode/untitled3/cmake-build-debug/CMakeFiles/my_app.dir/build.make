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
CMAKE_SOURCE_DIR = E:\CLion\leecode\untitled3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\leecode\untitled3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_app.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/my_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_app.dir/flags.make

CMakeFiles/my_app.dir/main.cpp.obj: CMakeFiles/my_app.dir/flags.make
CMakeFiles/my_app.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\leecode\untitled3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_app.dir/main.cpp.obj"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\my_app.dir\main.cpp.obj -c E:\CLion\leecode\untitled3\main.cpp

CMakeFiles/my_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/main.cpp.i"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CLion\leecode\untitled3\main.cpp > CMakeFiles\my_app.dir\main.cpp.i

CMakeFiles/my_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/main.cpp.s"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CLion\leecode\untitled3\main.cpp -o CMakeFiles\my_app.dir\main.cpp.s

# Object files for target my_app
my_app_OBJECTS = \
"CMakeFiles/my_app.dir/main.cpp.obj"

# External object files for target my_app
my_app_EXTERNAL_OBJECTS =

my_app.exe: CMakeFiles/my_app.dir/main.cpp.obj
my_app.exe: CMakeFiles/my_app.dir/build.make
my_app.exe: libdata1.dll.a
my_app.exe: CMakeFiles/my_app.dir/linklibs.rsp
my_app.exe: CMakeFiles/my_app.dir/objects1.rsp
my_app.exe: CMakeFiles/my_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\leecode\untitled3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_app.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my_app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_app.dir/build: my_app.exe
.PHONY : CMakeFiles/my_app.dir/build

CMakeFiles/my_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my_app.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my_app.dir/clean

CMakeFiles/my_app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\leecode\untitled3 E:\CLion\leecode\untitled3 E:\CLion\leecode\untitled3\cmake-build-debug E:\CLion\leecode\untitled3\cmake-build-debug E:\CLion\leecode\untitled3\cmake-build-debug\CMakeFiles\my_app.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_app.dir/depend

