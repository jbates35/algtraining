cmake_minimum_required(VERSION 3.6)
project(stack)

# Add subdirectories for each sub-project
add_subdirectory(234_stackArray)
add_subdirectory(237_stackLL)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/stackarr.c src/stackll.c)