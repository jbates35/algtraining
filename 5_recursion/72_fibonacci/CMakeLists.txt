PROJECT(fibSequence)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

set(CMAKE_C_STANDARD 99)

add_executable(fibSequence main_memoization.c)

target_compile_features(fibSequence PRIVATE c_std_99)
