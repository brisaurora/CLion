cmake_minimum_required(VERSION 3.10)
project(sender C)

set(CMAKE_C_STANDARD 99)

add_executable(sender main.c)
set_target_properties(sender PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")