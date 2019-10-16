cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(alignment)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wno-error=missing-field-initializers
)

add_executable(alignment src/main.cpp)
