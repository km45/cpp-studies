cmake_minimum_required(VERSION 3.7)
project(thread)

add_library(print src/print.cc)

add_executable(basic src/basic.cc)
target_link_libraries(basic print)

add_executable(argument src/argument.cc)
target_link_libraries(argument print)

add_executable(mutex src/mutex.cc)
