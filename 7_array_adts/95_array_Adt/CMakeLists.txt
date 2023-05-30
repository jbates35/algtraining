#Make Basic CMake project for C++17

PROJECT(array_adt)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

#Set to C99
set(CMAKE_C_STANDARD 99)

#allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(array_adt main.c)