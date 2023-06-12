cmake_minimum_required(VERSION 3.24)
project(stms C)

set(CMAKE_C_STANDARD 11)

add_executable(stms main.c student.h student.h student.c ../../../file.cpp)
