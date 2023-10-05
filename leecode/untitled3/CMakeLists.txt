cmake_minimum_required(VERSION 3.20)
project(test)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -mcmodel=large")
add_library(data1 SHARED data1.cpp)

if (UNIX AND NOT APPLE)
    set_target_properties(my_app PROPERTIES COMPILE_FLAGS "-mcmodel=large")
    set_target_properties(my_app PROPERTIES LINK_FLAGS "-mcmodel=large")
endif()

set(CMAKE_CXX_STANDARD 14)
add_executable(my_app main.cpp)
target_link_libraries(my_app data1)
