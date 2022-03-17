//
// Created by Elias Woie Refsdal on 07/03/2022.
//


#include <iostream>
#include "Person.h"
#include "Node.h"

int main () {
    Node a(Person(1, "Filip"));
    Node b(Person(2, "Erik"));
    Node c(Person(3, "Anita"));
    Node d(Person(4, "Hans"));
    Node e(Person(5, "Lillian"));

    auto &myPerson = a.getPerson();
    myPerson.setFirstName("FilipNEW");
    a.add(b);
    //std::cout << myPerson.getFirstName() << std::endl;
    a.traverseDepthFirst([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    // Pointers are not valid because folder objects are located on the stack. Get destructed when out of scope.
    /*
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
*/
    return 0;
}

