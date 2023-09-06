cmake_minimum_required(VERSION 3.6)
project(queues)

# Add subdirectories for each sub-project
add_subdirectory(257_queue)
add_subdirectory(261_circularQueue)

# Specify the include directories
include_directories(include)

# Add the utility files to a library
add_library(utils src/queue.c src/queueCircular.c)