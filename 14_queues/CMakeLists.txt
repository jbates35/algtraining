cmake_minimum_required(VERSION 3.6)
project(queue)

# Add subdirectories for each sub-project
add_subdirectory(257_queue)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/queue.c)