cmake_minimum_required(VERSION 3.6)
project(Matrices)

# Add subdirectories for each sub-project
add_subdirectory(143_diagMatrix)
add_subdirectory(145_lowSRMatrix)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/arrayAdt.c src/matrixAdt.c src/smatrixAdt.c)