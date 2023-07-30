cmake_minimum_required(VERSION 3.6)
project(sparsematsWithLL)

# Add subdirectories for each sub-project
add_subdirectory(228_sparseMatLL)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/sparseMatrix.c)