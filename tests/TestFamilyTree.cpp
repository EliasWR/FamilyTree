#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Date.hpp"
#include "JsonFile.hpp"
#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <iostream>

// Node.hpp tests
// Tests whether a Node can be made and edited

TEST_CASE("NodeChangePerson") {
  std::string initFirstName = "Gunnar";
  std::string initLastName = "Sonsteby";
  std::string newFirstName = "Fredrik";

  auto a = std::make_shared<Node<Person>>(Person(initFirstName, initLastName));
  auto &myPerson = a->getPerson();
  auto lambda = [ newFirstName ](Person &p) {
    p.setFirstName(newFirstName);
  };
  a->traverseDepthSearch(a, initFirstName, initLastName, lambda);

  auto personFirstName = myPerson.getFirstName();
  auto personLastName = myPerson.getLastName();

  bool firstName = (newFirstName == personFirstName);
  bool lastName = (initLastName == personLastName);
  bool result = firstName && lastName;
  REQUIRE(result);
}

TEST_CASE("CreatePerson") {
  std::string initFirstName = "Espen";
  std::string initLastName = "Olsen";

  Person a = {initFirstName, initLastName};

  std::string personFirstName = a.getFirstName();
  std::string personLastName = a.getLastName();

  bool firstname = (personFirstName == initFirstName);
  bool lastname = (personLastName == initLastName);
  REQUIRE(firstname && lastname);
}
/*
TEST_CASE("ReadAndWriteFile") {
  auto a = std::make_shared<Node<Person>>(Person("Gunnar", "Sonsteby"));
  a->add(Person("Erik", "Sonsteby"));
  a->add(Person("Anita", "Sonsteby"));
  a->add(Person("Hans", "Sonsteby"));
  a->add(Person("Lillian", "Sonsteby"));

  Person p("Henrik", "Sonsteby");
  auto lambda1 = [ p ](Node<Person> &node) {
    node.add(p);
  };
  a->traverseDepth(lambda1, "Erik", "Sonsteby");

  Menu<Person> m;
  m.saveNodes(a);
  m.getSavedNodes();
  m.printTree();
}
*/