cmake_minimum_required(VERSION 3.10)
project(my_file_system C)

set(CMAKE_C_STANDARD 99)

add_executable(my_file_system main.c fs_operation.h fs_operation.c fs_config.h)
set_target_properties(my_file_system PROPERTIES LINK_FLAGS -Wl,--stack,10000000)