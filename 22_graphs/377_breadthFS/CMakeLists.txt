cmake_minimum_required(VERSION 3.6)
project(BFS)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)
# Add executable target
add_executable(BFS main.c)


# Specify the include directories
target_include_directories(BFS PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Add the source files to your target
target_sources(BFS PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/graphs.c ${CMAKE_CURRENT_SOURCE_DIR}/../src/queueCircular.c ${CMAKE_CURRENT_SOURCE_DIR}/../src/stackarr.c)
