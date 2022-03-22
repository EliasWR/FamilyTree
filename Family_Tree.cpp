//
// Created by Elias Woie Refsdal on 07/03/2022.
// Due delivery 7th of April

#include <iostream>
#include "Person.h"
#include "Node.h"
#include "Menu.h"

int main () {
    Node a(Person(1, "Fili"));
    Node b(Person(2, "Erik"));
    Node c(Person(3, "Anita"));
    Node d(Person(4, "Hans"));
    Node e(Person(5, "Lillian"));

    auto &myPerson = a.getPerson();
    myPerson.setFirstName("Filip");

    std::cout << d.isLeaf() << std::endl;

    a.add(b);
    a.add(c);
    b.add(d);
    b.add(e);

    std::cout << "Printing tree with root: " << myPerson.getFirstName();
    a.traverseDepthFirst([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    b.traverseUpwards([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });


    return 0;
}

