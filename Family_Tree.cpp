//
// Created by Elias Woie Refsdal on 07/03/2022.
//


#include <iostream>
#include "Person.h"
#include "Node.h"

int main () {
    Node c("C"); // Pointers are not valid because folder objects are located on the stack. Get destructed when out of scope.
    Node bar("bar"); // It works when defined in main, but not as a method in class.
    Node baz ("baz"); // If we want to define it as a class method we need to allocate it on the heap with shared pointers.
    Node right("right");
    Node fubar("fubar");
    Node f1( "f1");

    c.add(bar);
    bar.add(baz);
    bar.add(fubar);

    baz.traverseUpwards([](Node* f) {
        std::cout << f->getName() << std::endl;
    });

    c.traverseDepthFirst([](Node* f) {

        std::cout <<f -> getName() <<std::endl;
    });

    return 0;
}

