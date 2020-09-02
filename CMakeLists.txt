cmake_minimum_required(VERSION 3.17)
project(TaskManager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(TaskManager main.cpp Process.cpp Process.h)