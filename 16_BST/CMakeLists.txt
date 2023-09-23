cmake_minimum_required(VERSION 3.6)
project(bst)

# Add subdirectories for each sub-project
add_subdirectory(305_createBST)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/bst.c src/queueCircular.c src/binTree.c src/arrayAdt.c src/stackarr.c)