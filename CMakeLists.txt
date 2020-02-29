cmake_minimum_required(VERSION 3.15)
project(sfml_framework)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(sfml_framework
    src/main.cpp
    src/mleczny.cpp
    src/mleczny.h)
