cmake_minimum_required(VERSION 3.6)
project(postfix1)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add executable target
add_executable(postfix1 main.c)

# Specify the include directories
target_include_directories(postfix1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Add the source files to your target
target_sources(postfix1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/stackarr.c)
