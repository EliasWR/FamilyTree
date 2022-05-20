#ifndef FAMILYTREE_PERSON_HPP
#define FAMILYTREE_PERSON_HPP

#include "Date.hpp"
#include <iostream>
#include <string>

class Person {
private:
  std::string _firstName, _lastName, _birth, _death, _gender;

public:
  /// @what Constructor for Person
  /// @param N/A
  /// @returns N/A
  /// @usage JsonFile::NodeFromJson
  /// @example Person p;
  Person() = default;

  /// @what Constructor for Person initializing firstname, lastname
  /// @param "std::string firstName" and "std::string lastName" \n
  ///         initializing only firstname and lastname of person
  /// @returns N/A
  /// @usage testFamilyTree.cpp
  /// @example Person p (firstName, lastName);
  Person(std::string firstName, std::string lastName)
      : _firstName(std::move(firstName)), _lastName(std::move(lastName)) {
  }

  /// @what Constructor for Person initializing all attributes of person
  /// @param strings initializing all variables
  /// @returns N/A
  /// @usage JsonFile::personFromJson, Menu::createPerson
  /// @example Person p (firstName, lastName, birth, death, gender
  /// );
  Person(std::string firstName, std::string lastName, std::string birth, std::string death, std::string gender)
      : _firstName(std::move(firstName)), _lastName(std::move(lastName)), _birth(std::move(birth)), _death(std::move(death)), _gender(std::move(gender)) {
  }

  /// Getters and setters for private variables of Person class
  [[nodiscard]] std::string getFirstName() const {
    return _firstName;
  }
  void setFirstName(std::string firstName) {
    _firstName = std::move(firstName);
  }
  [[nodiscard]] std::string getLastName() const {
    return _lastName;
  }
  void setLastName(std::string lastName) {
    _lastName = std::move(lastName);
  }
  [[nodiscard]] std::string getBirth() const {
    return _birth;
  }
  void setBirth(std::string birth) {
    _birth = std::move(birth);
  }
  [[nodiscard]] std::string getDeath() const {
    return _death;
  }
  void setDeath(std::string death) {
    _death = std::move(death);
  }
  [[nodiscard]] std::string getGender() const {
    return _gender;
  }
  void setGender(std::string gender) {
    _gender = std::move(gender);
  }

  /// @what Function for printing all persons attributes
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::printPerson
  /// @example p.printPersonInfo();
  void printPersonInfo() {
    std::cout << _firstName << " " << _lastName << " is born on the " << _birth;
    if (_death != "0") {
      std::cout << ", and died at " << _death << ".";
    } else {
      std::cout << ", and is alive." << std::endl;
    }
    Date d;
    d.getCurrentDate();
    std::cout << _firstName << " " << _lastName << " is ";
    d.calculateAge(_birth);
    std::cout << std::endl << _firstName << " " << _lastName << " is considered a " << _gender << "." << std::endl << std::endl;
  }
};

#endif//FAMILYTREE_PERSON_HPP
