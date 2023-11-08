cmake_minimum_required(VERSION 3.6)
project(sortAlgs)

# Add subdirectories for each sub-project
add_subdirectory(338_bubbleSort)
add_subdirectory(341_insertionSort)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/sortAlgs.c) 
