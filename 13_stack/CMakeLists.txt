cmake_minimum_required(VERSION 3.6)
project(stack)

# Add subdirectories for each sub-project
add_subdirectory(234_stackArray)
add_subdirectory(237_stackLL)
add_subdirectory(241_parentheses)
add_subdirectory(246_postfixConversion1)
add_subdirectory(249_postfixConversion2)
add_subdirectory(252_postfixEvaluation)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/stackarr.c src/stackll.c)