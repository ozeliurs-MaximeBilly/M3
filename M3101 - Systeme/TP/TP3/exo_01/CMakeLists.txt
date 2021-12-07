cmake_minimum_required(VERSION 3.19)
project(exo_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(exo_01
        dirsignal/exo_01.cxx
        dirsignal/nsSysteme.cxx
        include/CExc.h
        include/nsSysteme.h)
