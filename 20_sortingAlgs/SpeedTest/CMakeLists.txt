cmake_minimum_required(VERSION 3.6)
project(SpeedTest)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Allow vscode to find compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS_RELEASE "-O0")
# Add executable target
add_executable(SpeedTest main.c)


# Specify the include directories
target_include_directories(SpeedTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../SpeedTest ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Add the source files to your target
target_sources(SpeedTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/sortAlgs.c)
