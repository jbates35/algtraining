cmake_minimum_required(VERSION 3.6)
project(LinkedLists)

# Add subdirectories for each sub-project
add_subdirectory(175_showLinkedList)
add_subdirectory(177_showRecursLinkedList)
add_subdirectory(180_countAndSum)
add_subdirectory(182_max)
add_subdirectory(184_search)
add_subdirectory(191_insert)
add_subdirectory(193_delete)
add_subdirectory(197_removeDuplicates)
add_subdirectory(201_reverseList)
add_subdirectory(204_mergelists)
add_subdirectory(210_circularlists)
add_subdirectory(222_doublylinkedlist)
add_subdirectory(226_studentChallenge1_findMiddle)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/linkedlist.c src/rlinkedlist.c src/dlinkedlist.c)