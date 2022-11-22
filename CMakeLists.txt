cmake_minimum_required(VERSION 3.23)
project(cpp_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_algorithms main.cpp)
add_executable(singly_linked_list linked_list/src/singly_linked_list.cpp linked_list/include/singly_linked_list.h)

