cmake_minimum_required(VERSION 3.27)
project(Language_Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Language_Cpp main.cpp
        SqList_Header.h
        SeqList_Header.h
        LinkedList.h
        LinkedList2.h)
