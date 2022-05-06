//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <iostream>

namespace nlohmann {
  template <class T>
  // Overloading the to_json function from the nlohmann library
  void to_json(json& j, std::shared_ptr<Node<T>> n){
    throw std::runtime_error("Unknown type T");
  };

  void to_json(json& j, std::shared_ptr<Node<Person>> n) {
    Person p = n->getPerson();
    j = json{
        {"FirstName", p.getFirstName()},
        {"LastName", p.getLastName()},
        {"Birth", p.getBirth()},
        {"Death", p.getDeath()},
        {"Sex", p.getSex()},
        {"Children", n->getChildren()}
    };
  }

  void from_Json(json& j, std::shared_ptr<Node<Person>> n){
    Person p = n->getPerson();
    std::string firstName;
    std::string lastName;
    std::string birth;
    std::string death;
    char sex;


    firstName = j.at("FirstName");
    j.at("LastName").get_to(lastName);
    j.at("Birth").get_to(birth);
    j.at("Death").get_to(death);
    j.at("Sex").get_to(sex);

    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setBirth(birth);
    p.setDeath(death);
    p.setSex(sex);
  }
}

template<class T>
class JsonFile {
private:
  const std::string _fileName;
  std::shared_ptr<Node<T>> &_rootNode;
  std::ofstream f;
  nlohmann::json j;

public:
  explicit JsonFile(std::shared_ptr<Node<T>> &t, std::string fileName)
      : _rootNode(t), _fileName(fileName) {
  }

  void openFile() {
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);
  }

  void closeFile() {
    f.close();
  }

  void jsonToFile(nlohmann::json &j) {
    f << j.dump(4);
  }

  void readFile() {
    std::ifstream i(_fileName);
    nlohmann::json j;
    i >> j;
  }

  void readFile (nlohmann::json j) {
    std::ifstream file(_fileName);
    file >> j;
  }
// TODO Not used, remove
  /*
  nlohmann::json personToJson(const Person &p) {
    nlohmann::json jsonPerson{
      {"FirstName", p.getFirstName()},
      {"LastName", p.getLastName()},
      {"Birth", p.getBirth()},
      {"Death", p.getDeath()},
      {"Sex", p.getSex(),"\n"}};
    return jsonPerson;
  }
*/
  nlohmann::json writePerson() {
    nlohmann::json personJson(_rootNode);
    return personJson;
  }

  void readPerson(const nlohmann::json &j, Person &p) {

  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
