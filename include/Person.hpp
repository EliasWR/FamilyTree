#ifndef FAMILYTREE_PERSON_HPP
#define FAMILYTREE_PERSON_HPP

#include "Date.hpp"
#include <iostream>
#include <string>

class Person {
private:
  std::string _firstName, _lastName, _birth, _death, _sex;

public:
  /// @what Constructor for Person
  /// @param N/A
  /// @returns N/A
  /// @Usage JsonFile::NodeFromJson
  /// @example Person p;
  Person() = default;

  /// @what Constructor for Person initializing firstname, lastname
  /// @param "std::string firstName" and "std::string lastName" \n
  ///         initializing only firstname and lastname of person
  /// @returns N/A
  /// @Usage testFamilyTree.cpp
  /// @example Person p (firstName, lastName);
  Person(std::string firstName, std::string lastName)
      : _firstName(firstName), _lastName(lastName) {
  }

  /// @what Constructor for Person initializing all attributes of person
  /// @param strings initializing all variables
  /// @returns N/A
  /// @Usage JsonFile::personFromJson, Menu::createPerson
  /// @example Person p (firstName, lastName, birth, death, sex);
  Person(std::string firstName, std::string lastName, std::string birth, std::string death, std::string sex)
      : _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex) {
  }

  /// Getters and setters for private variables of Person class
  [[nodiscard]] std::string getFirstName() const {
    return _firstName;
  }
  void setFirstName(std::string firstName) {
    _firstName = firstName;
  }
  [[nodiscard]] std::string getLastName() const {
    return _lastName;
  }
  void setLastName(std::string lastName) {
    _lastName = lastName;
  }
  [[nodiscard]] std::string getBirth() const {
    return _birth;
  }
  void setBirth(std::string birth) {
    _birth = birth;
  }
  [[nodiscard]] std::string getDeath() const {
    return _death;
  }
  void setDeath(std::string death) {
    _death = death;
  }
  [[nodiscard]] std::string getSex() const {
    return _sex;
  }
  void setSex(std::string sex) {
    _sex = sex;
  }

  /// @what Function for printing all persons attributes
  /// @param N/A
  /// @returns N/A
  /// @Usage Menu::printPerson
  /// @example p.printPersonInfo();
  void printPersonInfo() {
    std::cout << _firstName << " " << _lastName;
    std::cout << " is born on the ";
    std::cout << _birth;

    if (_death != "0") {
      std::cout << ", died at ";
      std::cout << _death;
    } else {
      std::cout << ", is alive";
    }
    Date d;
    d.calculateAge(_birth, d.getCurrentDate());
    std::cout << "";

    std::cout << " and is a ";
    std::cout << _sex;
    std::cout << "." << std::endl;
  }
};

#endif//FAMILYTREE_PERSON_HPP
