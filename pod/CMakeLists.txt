cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(pod)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wno-error=missing-field-initializers
)

add_library(fundamental fundamental.cc)
add_library(standard_layout standard_layout.cc)
add_library(trivial trivial.cc)
