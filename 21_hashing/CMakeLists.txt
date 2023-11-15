cmake_minimum_required(VERSION 3.6)
project(hashing)

# Add subdirectories for each sub-project
add_subdirectory(366_chaining)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/chainhash.c) 
