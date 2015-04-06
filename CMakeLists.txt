cmake_minimum_required(VERSION 3.1)

project(Archivator.-smx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp lib/compression.h lib/compression.cpp lib/huffman.cpp lib/huffman.h lib/reader.cpp lib/reader.h
                 lib/writer.cpp lib/writer.h)
add_executable(Archivator ${SOURCE_FILES} lib/Node.cpp lib/Node.h lib/BinaryTree.cpp lib/BinaryTree.h lib/PrefixCodes.cpp lib/PrefixCodes.h lib/Code.cpp lib/Code.h)