cmake_minimum_required(VERSION 3.21)
project(FamilyTree)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

enable_testing()
add_subdirectory(tests
                include
                )

add_executable(FamilyTree
        application/Family_Tree.cpp
        include/Menu.h
        include/LinkedList.h
        include/Person.h
        include/Node.h
        include/FileHandling.h
        )
