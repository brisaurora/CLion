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
CMAKE_SOURCE_DIR = E:\CLion\CSAPP\chapter3\data_size

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data_size.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/data_size.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_size.dir/flags.make

CMakeFiles/data_size.dir/main.cpp.obj: CMakeFiles/data_size.dir/flags.make
CMakeFiles/data_size.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data_size.dir/main.cpp.obj"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\data_size.dir\main.cpp.obj -c E:\CLion\CSAPP\chapter3\data_size\main.cpp

CMakeFiles/data_size.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_size.dir/main.cpp.i"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CLion\CSAPP\chapter3\data_size\main.cpp > CMakeFiles\data_size.dir\main.cpp.i

CMakeFiles/data_size.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_size.dir/main.cpp.s"
	D:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CLion\CSAPP\chapter3\data_size\main.cpp -o CMakeFiles\data_size.dir\main.cpp.s

# Object files for target data_size
data_size_OBJECTS = \
"CMakeFiles/data_size.dir/main.cpp.obj"

# External object files for target data_size
data_size_EXTERNAL_OBJECTS =

data_size.exe: CMakeFiles/data_size.dir/main.cpp.obj
data_size.exe: CMakeFiles/data_size.dir/build.make
data_size.exe: CMakeFiles/data_size.dir/linklibs.rsp
data_size.exe: CMakeFiles/data_size.dir/objects1.rsp
data_size.exe: CMakeFiles/data_size.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable data_size.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\data_size.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_size.dir/build: data_size.exe
.PHONY : CMakeFiles/data_size.dir/build

CMakeFiles/data_size.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\data_size.dir\cmake_clean.cmake
.PHONY : CMakeFiles/data_size.dir/clean

CMakeFiles/data_size.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CLion\CSAPP\chapter3\data_size E:\CLion\CSAPP\chapter3\data_size E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug E:\CLion\CSAPP\chapter3\data_size\cmake-build-debug\CMakeFiles\data_size.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_size.dir/depend

