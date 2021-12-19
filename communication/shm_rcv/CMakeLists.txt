cmake_minimum_required(VERSION 3.10)
project(shm_rcv C)

set(CMAKE_C_STANDARD 99)

add_executable(shm_rcv main.c)
set_target_properties(shm_rcv PROPERTIES
        COMPILE_FLAGS "-pthread"
        LINK_FLAGS "-pthread")