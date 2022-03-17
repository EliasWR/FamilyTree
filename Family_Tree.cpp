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

    b.traverseUpwards([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });
    return 0;
}

