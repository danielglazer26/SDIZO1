cmake_minimum_required(VERSION 3.17)
project(SDIZO1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(SDIZO1 main.cpp Table.cpp Table.h DoubleLinkedList.cpp DoubleLinkedList.h Heap.cpp Heap.h TreeBST.cpp TreeBST.h LoadFile.cpp LoadFile.h Tests.cpp Tests.h)