cmake_minimum_required(VERSION 3.6)
project(sortAlgs)

# Add subdirectories for each sub-project
add_subdirectory(338_bubbleSort)
add_subdirectory(341_insertionSort)
add_subdirectory(348_selectionSort)
add_subdirectory(353_quickSort)
add_subdirectory(356_mergeSortI)
add_subdirectory(358_mergeSortR)
add_subdirectory(360_countSort)
add_subdirectory(362_radixSort)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/sortAlgs.c) 
