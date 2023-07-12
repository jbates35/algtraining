cmake_minimum_required(VERSION 3.6)
project(diagMatrix)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add executable target
add_executable(diagMatrix main.c)

# Add a custom target for Cppcheck
add_custom_target(
    cppcheck
    COMMAND cppcheck
    --enable=all
    --inconclusive
    --std=c99
    -I /usr/include
    -I /usr/local/include
    --project=${CMAKE_BINARY_DIR}/compile_commands.json
    COMMENT "Running Cppcheck"
)

# Make Cppcheck target dependent on the desired build target
add_dependencies(diagMatrix cppcheck)
