cmake_minimum_required(VERSION 3.10)
project(tinyserver_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(tinyserver)

add_executable(tinyserver_master
        tinyserver/daemon.cpp
        tinyserver/daemon.h
        tinyserver/log.cpp
        tinyserver/log.h
        tinyserver/main.cpp
        tinyserver/predefine.cpp
        tinyserver/predefine.h
        tinyserver/processpool.h
        tinyserver/task.cpp
        tinyserver/task.h)
