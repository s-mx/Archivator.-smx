cmake_minimum_required(VERSION 3.1)

project(Archivator.-smx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

include_directories(lib)
add_subdirectory(lib)

set(SOURCE main.cpp)

add_executable(main main.cpp)
target_link_libraries(main lib)