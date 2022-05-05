#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include "JsonFile.hpp"
#include "Date.hpp"
#include <iostream>

void printTree (std::shared_ptr<Node<Person>>& node) {
  int indent = 3;
  node->traverseDepth([ indent ](Node<Person> &f, int depth) {
    for (int i = 0; i < depth; ++i) {
      for (int j = 0; j < indent; ++j) {
        std::cout << " ";
      }
    }
    std::cout << f.getPerson().getFirstName() << " " << f.getPerson().getLastName() << std::endl;
  });
}

// Uncomment any implementation to testrun
int main() {
  /*
    // TODO Implementation of traversal

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
    // TODO oldReadPerson
    void readPerson (std::string fileName){
    std::string sex;
    std::array<std::string,3> birth{};
    std::array<std::string,3> death{};
    std::string year;
    std::ifstream inFile(fileName);
    inFile >> _firstName >> _lastName >> sex >> birth[0] >> birth[1] >>birth[2] >> death[0] >> death[1] >> death[2];
    for (int i = 0; i <= 2; i++){
        _birth[i] = std::atoi(birth[i].c_str());
        _death[i] = std::atoi(death[i].c_str());
    }
    _sex = sex[0];
}
   // TODO implementation reading from file
    Person p;
    p.readPerson(fileName);
    std::cout << p.getFirstName() << " " << p.getLastName();
    */

  // TODO Making nodes with person objects inside
  auto a = std::make_shared<Node<Person>>(Person("Gunnar", "Sonsteby"));
  a->add (Person("Erik", "Sonsteby"));
  a->add (Person("Anita", "Sonsteby"));
  a->add (Person("Hans", "Sonsteby"));
  a->add (Person("Lillian", "Sonsteby"));
/*
  // TODO Traversal with editing example
  Person p("Henrik", "Sonsteby");
  auto lambda1 = [p](Node<Person> &node) {node.add(p);};
  a->traverseDepth (lambda1,"Erik","Sonsteby");

  auto &myPerson = a->getPerson ();
  auto lambda = [](Person &p) {p.setFirstName("Elias");};
  a->traverseDepthSearch(a, "Gunnar", "Sonsteby", lambda);

    auto personFirstName = myPerson.getFirstName();
    auto personLastName = myPerson.getLastName();
    std::cout << personFirstName << " " << personLastName << " has successfully been changed." << std::endl;

    printTree(a);
*/
  // TODO Example of filewriting and traversal returning node
  /*
  nlohmann::json j;
  std::string fileName = "FamilyTree.json";
  JsonFile json(a, fileName);

  json.openFile();

  j = json.writePerson();
  json.jsonToFile(j);

  std::string s = j.dump(4);
  std::cout << s << std::endl;

  json.closeFile ();

  json.openFile();
  json.readFile();
*/
  // TODO Date handling example
/*
  std::string birthDate = "17.10.2000";
  std::string presDate = "03.05.2022";
  Date d(01,01,2001);
  d.setDate (birthDate);
  std::string str = d.getDate();
  std::cout << str << std::endl;
*/
  // Get current date

  //std::string currentDate = m.getCurrentDate();
  //d.setCurrentDate(currentDate);
  //d.calculateAge(birthDate, presDate);

  // TODO Initial read from file
  Menu<Person> m;
  m.greeting();
  while (!m.getExitMenu()) {
    m.mainScreen();
  }
  return 0;
}