#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "LinkedList.hpp"
#include "Menu.hpp"
#include "Node.hpp"
#include "Person.hpp"
#include "JsonFile.hpp"
#include "Date.hpp"
#include "json.hpp"
#include <iostream>

// Node.hpp tests
// Tests werther a Node can be made and edited
/*
TEST_CASE("NodeChangePerson"){
  std::string initFirstName = "Gunnar";
  std::string initLastName = "Sønsteby";
  std::string newFirstName = "Fredrik";

  auto a = std::make_shared<Node<Person>>(Person(initFirstName, initLastName));
  auto myPerson = a->getPerson ();
  auto lambda = [newFirstName](Person &p) {p.setFirstName(newFirstName);};
  a->traverseDepthSearch(a, newFirstName, initLastName, lambda);

  auto personFirstName = myPerson.getFirstName();
  auto personLastName = myPerson.getLastName();

  bool firstName = (newFirstName == personFirstName);
  bool lastName = (initLastName == personLastName);
  REQUIRE (firstName && lastName);
}
*/
/*
TEST_CASE("Traversal"){
  auto a = std::make_shared<Node<Person>>(Person("Gunnar", "Sønsteby"));
  a->add (Person("Erik", "Sønsteby"));

}
TEST_CASE("Traversal"){

}
// Date.hpp tests
TEST_CASE("DisplayAge"){

}

// Menu tests
TEST_CASE(){

}
*/