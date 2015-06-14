cmake_minimum_required(VERSION 3.2)
project(lib)

set(HEADER Code.h BinaryTree.h compression.h huffman.h OS_lib.h PrefixCodes.h Node.h writer.h reader.h)
set(SOURCE Code.cpp BinaryTree.cpp compression.cpp huffman.cpp OS_lib.cpp PrefixCodes.cpp Node.cpp writer.cpp reader.cpp)

add_library(lib STATIC ${HEADER} ${SOURCE})