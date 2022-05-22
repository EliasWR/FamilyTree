#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include <iostream>

/// Node test
/// Tests whether a Node can be made and edited
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

///Person test
///Tests creatingPerson and retrieving name
TEST_CASE("CreatePerson") {
  std::string initFirstName = "Espen";
  std::string initLastName = "Olsen";

  Person a = {initFirstName, initLastName};

  std::string personFirstName = a.getFirstName();
  std::string personLastName = a.getLastName();

  bool firstName = (personFirstName == initFirstName);
  bool lastName = (personLastName == initLastName);
  bool result = (firstName && lastName);

  REQUIRE(result);
}
/// Node and filewriting test
/// Tests whether a Node can be made, edited, written to file and then retrieved
TEST_CASE("ReadAndWriteFile") {
  std::string firstName = "Gunnar";
  std::string lastName = "Sonsteby";

  auto a = std::make_shared<Node<Person>>(Person(firstName, lastName));
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

  auto &myPerson = a->getPerson();

  auto personFirstName = myPerson.getFirstName();
  auto personLastName = myPerson.getLastName();

  bool testFirstName = (firstName == personFirstName);
  bool testLastName = (lastName == personLastName);
  bool result = (testFirstName && testLastName);

  REQUIRE(result);
}
