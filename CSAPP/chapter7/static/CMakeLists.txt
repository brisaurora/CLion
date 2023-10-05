cmake_minimum_required(VERSION 3.20)
project(static C)

set(CMAKE_C_STANDARD 99)

add_executable(static main.c)
set_target_properties(static PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")