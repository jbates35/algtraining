cmake_minimum_required(VERSION 3.6)
project(trees)

# Add subdirectories for each sub-project
add_subdirectory(299_binTree)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/queueCircular.c src/binTree.c src/arrayAdt.c src/stackarr.c)