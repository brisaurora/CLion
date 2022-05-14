cmake_minimum_required(VERSION 3.10)
project(sigjmp C)

set(CMAKE_C_STANDARD 99)

add_executable(sigjmp main.c)
set_target_properties(sigjmp PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")