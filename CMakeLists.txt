cmake_minimum_required(VERSION 3.5)
project(binary_add_up)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)