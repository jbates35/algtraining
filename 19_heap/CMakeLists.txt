cmake_minimum_required(VERSION 3.6)
project(heap)

# Add subdirectories for each sub-project
add_subdirectory(329_insertHeap)
add_subdirectory(332_sortHeap)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/heapADT.c src/heap.c)
