cmake_minimum_required(VERSION 3.6)
project(rb)

# Add subdirectories for each sub-project
add_subdirectory(326_RedBlackTrees)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/redblack.src src/queueCircular.c src/arrayAdt.c src/stackarr.c)