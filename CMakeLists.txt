cmake_minimum_required(VERSION 3.27)
project(Language_Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Language_Cpp main.cpp
        SqList.h
        SeqList.h
        LinkedList.h
        LinkedList2.h
        SqStack.h
        LinkedStack.h
        SqCircularQueue.h
        LinkedQueue.h
        LinkedCircularQueue.h
        BTNode.h)
