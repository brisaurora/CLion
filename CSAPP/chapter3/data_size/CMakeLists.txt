cmake_minimum_required(VERSION 3.20)
project(data_size)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_size main.cpp)
#set_target_properties(data_size PROPERTIES LINK_FLAGS -Wl,--stack,5294969296)