cmake_minimum_required(VERSION 3.2)
project(reader)

set(HEADER reader.h)
set(SOURCE reader.cpp)

add_library(reader STATIC ${SOURCE})