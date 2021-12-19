cmake_minimum_required(VERSION 3.10)
project(my_fs C)

set(CMAKE_C_STANDARD 99)

add_executable(my_fs main.c init.h init.c)
