cmake_minimum_required(VERSION 3.10)
project(pipe C)

set(CMAKE_C_STANDARD 99)

add_executable(pipe main.c)
set_target_properties(pipe PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")