#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include "JsonFile.hpp"
#include "Date.hpp"
#include "json.hpp"
#include <iostream>

// Node.hpp tests
// Tests werther a Node can be made and edited

TEST_CASE("NodeChangePerson"){
  std::string initFirstName = "Gunnar";
  std::string initLastName = "Sønsteby";
  std::string newFirstName = "Fredrik";

  auto a = std::make_shared<Node<Person>>(Person(initFirstName, initLastName));
  auto &myPerson = a->getPerson ();
  auto lambda = [newFirstName](Person &p) {p.setFirstName(newFirstName);};
  a->traverseDepthSearch(a, initFirstName, initLastName, lambda);

  auto personFirstName = myPerson.getFirstName();
  auto personLastName = myPerson.getLastName();

  bool firstName = (newFirstName == personFirstName);
  bool lastName = (initLastName == personLastName);
  bool result = firstName && lastName;
  REQUIRE (result);
}

/*
TEST_CASE("Traversal"){
  std::string firstName1 = "Gunnar";
  std::string lastName1 = "Sønsteby";
  std::string firstName2 = "Erik";
  std::string lastName2 = "Sønsteby";
  std::string nameFound;

  auto a = std::make_shared<Node<Person>>(Person(firstName1, lastName1));
  a->add (Person(firstName2, lastName2));

  auto &myPerson = a->getPerson ();
  auto lambda = [nameFound](Person &p) {p.getFirstName();};
  a->traverseDepthSearch(a, firstName2, firstName2, lambda);
}
*/
// Date.hpp tests
TEST_CASE("DisplayAge"){

}

// Menu tests
TEST_CASE(){

}
