cmake_minimum_required(VERSION 3.10)
project(shm C)

set(CMAKE_C_STANDARD 99)

add_executable(shm main.c)
set_target_properties(shm PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")