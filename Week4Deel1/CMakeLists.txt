cmake_minimum_required(VERSION 3.26)
project(Week2Deel2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Week2Deel2 main.cpp
        readFile.cpp
        readFile.h
        Stack.cpp
        Stack.h
        validator.cpp
        validator.h)
