cmake_minimum_required(VERSION 3.2)
project(lib)

include_directories(reader)
include_directories(writer)
add_subdirectory(reader)
add_subdirectory(writer)

set(HEADER Code.h BinaryTree.h compression.h huffman.h OS_lib.h PrefixCodes.h Node.h)
set(SOURCE Code.cpp BinaryTree.cpp compression.cpp huffman.cpp OS_lib.cpp PrefixCodes.cpp Node.cpp)

add_library(lib STATIC ${SOURCE})
target_link_libraries(lib reader writer)