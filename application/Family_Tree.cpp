#include <iostream>
#include "Person.hpp"
#include "Node.hpp"
#include "Menu.hpp"
#include "LinkedList.hpp"
#include "FileHandling.hpp"
#include "FileHandling.cpp"

int globalVar = 3;

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

// Uncomment any implementation to testrun
int main () {
    /*
    // Making nodes with person objects inside
    Node a(Person(1, "Gunnar"));
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
    a.traverseDepth([](Node<Person>* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });
    std::cout << "------------------"<< std::endl;
    b.traverseUpwards([](Node<Person>* f) {
        std::cout << f->getPerson().getFirstName() << std::endl;
    });
    // Implementation of singly linked list
    auto list = FamilyTree::singly_linked_list<Node<Person>>();

    list.addLast(a);
    list.addLast(b);
    list.addLast(c);

    std::cout << list << std::endl;

    std::cout << list.removeFirst() << std::endl;

    std::cout << list << std::endl;

    list.insert(0, d);

    list.insert(list.size() - 1, e);

    list.addFirst(a);

    std::cout << list << std::endl;
*/
    /*
    // List to be bubble-sorted
    std::vector<int> numbers = {2,1,4,3,5};

    // Implementation of bubble sort
    bubbleSort(numbers);
    for (auto i : numbers){
        std::cout << i << std::endl;
    }
    */
    /*
    // Implementation of filewriting for XML
    XmlWriter xml;
    std::string name = "FamilyTreeInformation1.xml";

    if (xml.open(name)) {
        xml.writeOpenTag("testTag");
        xml.writeStartElementTag("testEle1");
        xml.writeString("This is my first tag string!");
        xml.writeEndElementTag();

        xml.writeOpenTag("testTag2");
        xml.writeStartElementTag("testEle2");
        xml.writeAttribute("testAtt=\"TestAttribute\"");
        xml.writeString("I sometimes amaze myself.");
        xml.writeEndElementTag();

        xml.writeOpenTag("testTag3");
        xml.writeStartElementTag("testEle3");
        xml.writeAttribute("testAtt2=\"TestAttrib2\"");
        xml.writeString("Though i'm sure someone can make something even better");
        xml.writeEndElementTag();

        xml.writeCloseTag();
        xml.writeCloseTag();
        xml.writeCloseTag();

        xml.close();
        std::cout << "Success!\n";
    } else {
        std::cout << "Error opening file.\n";
    }

    system("pause");
    */
    // Implementation of writing to file
    /*
    Person person1("Per", "Sandberg",{1990,01,01}, {2021, 01, 01}, 'm');
    Person person2("Ola", "Nordmann", {2000,01,01}, {2020, 01, 01}, 'm');

    XmlWriter xml;
    std::string fileName = "FamilyTreeInformation1.xml"; // TODO File only opens if it does not already exist
    if (xml.open(fileName)) {
        //xml.writeOpenTag("PersonsTag");
        person1.writePerson(xml);
        //person2.writePerson(xml);
        xml.close();
        std::cout << "Success!\n";
    } else {
        std::cout << "Error opening file.\n";
    }
    // implementation reading from file
    Person person1("Per", "Sandberg",{1990,01,01}, {2021, 01, 01}, 'm');
    Person person2("Ola", "Nordmann", {2000,01,01}, {2020, 01, 01}, 'm');

    XmlWriter xml;
    std::string fileName = "FamilyTreeInformation1.xml"; // TODO File only opens if it does not already exist
    if (xml.open(fileName)) {
        //xml.writeOpenTag("PersonsTag");
        person1.writePerson(xml);
        //person2.writePerson(xml);
        xml.close();
        std::cout << "Success!\n";
    } else {
        std::cout << "Error opening file.\n";
    }
    // implementation reading from file
    Person p;
    // TODO exclude header
    p.readPerson(fileName);
    std::cout << p.getFirstName() << " " << p.getLastName();
    return 0;


    // Implementation of menu
    Menu menu;
    menu.mainScreen();
    menu.mainScreenCases ();
    // Lage ny nodeList
    FamilyTree::singly_linked_list<Node<Person>> list;
    Menu::createPerson (list);
    std::cout << list << std::endl;
    */
    // Making nodes with person objects inside
    Node a(Person("Gunnar", "Sønsteby"));
    Node b(Person("Erik", "Sønsteby"));
    Node c(Person("Anita", "Sønsteby"));
    Node d(Person("Hans", "Sønsteby"));
    Node e(Person("Lillian", "Sønsteby"));

    // Adding relations
    a.add(b);
    a.add(c);
    b.add(d);
    b.add(e);

    int indent = globalVar;
    a.traverseDepth([indent](Node<Person>* f, int depth) {
        for (int i = 0; i < depth;++i){
            for (int j = 0; j < indent; ++j){
                std::cout << " ";
            }
        }
        std::cout << f->getPerson().getFirstName() << std::endl;
    });

    /*
    auto myPerson = a.getPerson ();
    a.traverseDepthSearch(a, "Gunnar", "Sønsteby", [](&myPerson) {myPerson.setFirstName()}){};

    auto personFirstName = myPerson.getFirstName();
    auto personLastName = myPerson.getLastName();
    std::cout << personFirstName << " " << personLastName << " has successfully been changed." << std::endl;
    */
}