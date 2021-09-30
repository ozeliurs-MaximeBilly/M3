cmake_minimum_required(VERSION 3.0)
project(M3103)

set(CMAKE_CXX_STANDARD 14)

include_directories(M3103 headers sources)

add_executable(M3103 sources/main.cpp headers/CNode.hpp headers/CList.hpp headers/ListLRU.hpp headers/CRDTree.hpp headers/MaxTree.hpp)
