cmake_minimum_required(VERSION 3.10)
project(pipe_three C)

set(CMAKE_C_STANDARD 99)

add_executable(pipe_three main.c)
set_target_properties(pipe_three PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")