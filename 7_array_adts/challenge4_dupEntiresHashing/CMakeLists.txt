cmake_minimum_required(VERSION 3.6)
project(challenge4)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add executable target
add_executable(challenge4 main.c arrayAdt.c arrayAdt.h)

# Add a custom target for Cppcheck
add_custom_target(
    cppcheck
    COMMAND cppcheck
    --enable=all
    --inconclusive
    --std=c99
    ${CMAKE_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/arrayAdt.c
    COMMENT "Running Cppcheck"
)

# Make Cppcheck target dependent on the desired build target
add_dependencies(cppcheck challenge4)
