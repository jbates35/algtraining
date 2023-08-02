cmake_minimum_required(VERSION 3.6)
project(stackarr)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add executable target
add_executable(stackarr main.c)

# Specify the include directories
target_include_directories(stackarr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Add the source files to your target
target_sources(stackarr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/stackarr.c)
