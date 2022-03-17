//
// Created by Elias Woie Refsdal on 07/03/2022.
//


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
    a.add(b);
    a.add(c);
    b.add(d);
    b.add(e);

    a.traverseDepthFirst([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });
    std::cout << d.isLeaf() << std::endl;
    b.traverseUpwards([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    return 0;
}

