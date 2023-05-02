PROJECT(factorial)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(factorial main.c)

