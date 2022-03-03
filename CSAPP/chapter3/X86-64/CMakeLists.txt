cmake_minimum_required(VERSION 3.20)
project(X86_64 C)

set(CMAKE_C_STANDARD 99)

add_executable(X86_64 main.c)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")