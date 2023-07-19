cmake_minimum_required(VERSION 3.6)
project(LinkedLists)

# Add subdirectories for each sub-project
add_subdirectory(175_showLinkedList)
add_subdirectory(177_showRecursLinkedList)
add_subdirectory(180_countAndSum)
add_subdirectory(182_max)
add_subdirectory(184_search)
add_subdirectory(191_insert)


# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/linkedlist.c)