#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include "Date.hpp"
#include <iostream>

// Uncomment any implementation to testrun
int main() {
 /*
  auto a = std::make_shared<Node<Person>>(Person("Gunnar", "Sonsteby"));
  a->add (Person("Erik", "Sonsteby"));
  a->add (Person("Anita", "Sonsteby"));
  a->add (Person("Hans", "Sonsteby"));
  a->add (Person("Lillian", "Sonsteby"));

  Person p("Henrik", "Sonsteby");
  auto lambda1 = [p](Node<Person> &node) {node.add(p);};
  a->traverseDepth (lambda1,"Erik","Sonsteby");

  nlohmann::json j;
  std::string fileName = "FamilyTree.json";
  JsonFile json(a, fileName);

  json.openFile();

  j = json.writePerson();
  json.jsonToFile(j);

  std::string s = j.dump(4);
  std::cout << s << std::endl;

  json.closeFile ();

  j = json.readFile(j);
  auto emptyNode = std::make_shared<Node<Person>> ();
  auto b = json.nodeFromJson(j, emptyNode);

  Menu<Person> m;
  m.printTree(b);
*/

 Menu<Person> m;

  m.greeting();
  while (m.getState() != 9) {
    m.mainScreen();
  }

  return 0;
}