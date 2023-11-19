cmake_minimum_required(VERSION 3.6)
project(graphs)

# Add subdirectories for each sub-project
add_subdirectory(377_breadthFS)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/queueCircular.c src/graphs.c)
