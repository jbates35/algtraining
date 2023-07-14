cmake_minimum_required(VERSION 3.6)
project(SparseMatrices)

# Add subdirectories for each sub-project
add_subdirectory(164_sparseMatProgram)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/sparseMatrix.c)