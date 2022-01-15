cmake_minimum_required(VERSION 3.10)
project(hook C)

set(CMAKE_C_STANDARD 99)

add_executable(hook main.c)
add_executable(hooklib main.c)