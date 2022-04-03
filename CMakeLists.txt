cmake_minimum_required(VERSION 3.21)
project(FamilyTree)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(FamilyTree
        Family_Tree.cpp Menu.h LinkedList.h Person.h Node.h FileHandling.h FileHandling.cpp)
