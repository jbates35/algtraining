cmake_minimum_required(VERSION 3.6)
project(permutation)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add executable target
add_executable(permutation main.c)

# Add a custom target for Cppcheck
add_custom_target(
    cppcheck
    COMMAND cppcheck
    --enable=all
    --inconclusive
    --std=c99
    ${CMAKE_SOURCE_DIR}/main.c
    COMMENT "Running Cppcheck"
)

# Make Cppcheck target dependent on the desired build target
add_dependencies(cppcheck permutation)
