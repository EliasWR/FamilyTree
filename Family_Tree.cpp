//
// Created by Elias Woie Refsdal on 07/03/2022.
// Due delivery 7th of April

#include <iostream>
#include "Person.h"
#include "Node.h"
#include "Menu.h"
#include "LinkedList.h"

template <class T>
void bubbleSort (std::vector<T> &list){
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < list.size(); i++){
            if (list[i-1] > list[i]){
                std::swap(list[i-1], list[i]);
                swapped = true;
            }
        }
    }while (swapped);
}

int main () {
    // Making nodes with person objects inside
    Node a(Person(1, "Fili"));
    Node b(Person(2, "Erik"));
    Node c(Person(3, "Anita"));
    Node d(Person(4, "Hans"));
    Node e(Person(5, "Lillian"));

    // Implementation of fetching person
    auto &myPerson = a.getPerson();
    myPerson.setFirstName("Filip");

    // Implementation of node tests
    std::cout << d.isLeaf() << std::endl;

    // Adding relations
    a.add(b);
    a.add(c);
    b.add(d);
    b.add(e);

    // Implementation of traversal
    std::cout << "Printing tree with root: " << myPerson.getFirstName() << std::endl;
    a.traverseDepthFirst([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    b.traverseUpwards([](Node* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    // Implementation of singly linked list
    auto list = FamilyTree::singly_linked_list<std::string>();

    list.addLast("Tore");
    list.addLast("Per");
    list.addLast("Conny");

    std::cout << list << std::endl;

    std::cout << list.removeFirst() << std::endl;

    std::cout << list << std::endl;

    list.insert(0, "Olav");

    list.insert(list.size() - 1, "Birgitte");

    list.addFirst("Ole");

    std::cout << list << std::endl;

    // List to be bubble sorted
    std::vector<int> numbers = {2,1,4,3,5};

    // Implementation of bubble sort
    bubbleSort(numbers);
    for (auto i : numbers){
        std::cout << i << std::endl;
    }

    return 0;
}

