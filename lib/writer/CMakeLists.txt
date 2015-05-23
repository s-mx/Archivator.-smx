cmake_minimum_required(VERSION 3.2)
project(writer)

set(HEADER writer.h)
set(SOURCE writer.cpp)

add_library(writer STATIC ${SOURCE})