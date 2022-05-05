//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <iostream>

namespace nlohmann {
  template <class T>
  void to_json(json& j, std::shared_ptr<Node<T>> n){
    throw std::runtime_error("Unknown type T");
  };

  void to_json(json& j, std::shared_ptr<Node<Person>> n) {
    Person p = n->getPerson();
    j = json{
        {"FirstName", p.getFirstName()},
        {"LastName", p.getLastName()},
        {"birth", p.getBirth()},
        {"death", p.getDeath()},
        {"sex", p.getSex()},
        {"Children", n->getChildren()}
    };
  }
}


template<class T>
class JsonFile {
private:
  const std::string _fileName;
  std::shared_ptr<Node<T>> &_node;
  std::ofstream f;
  nlohmann::json j;

public:
  explicit JsonFile(std::shared_ptr<Node<T>> &t, std::string fileName)
      : _node(t), _fileName(fileName) {
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

  void writeJsonToFile(nlohmann::json j) {

  }

  nlohmann::json personToJson(const Person &p) {
    nlohmann::json jsonPerson{
      {"FirstName", p.getFirstName()},
      {"LastName", p.getLastName()},
      {"Birth", p.getBirth()},
      {"Death", p.getDeath()},
      {"Sex", p.getSex(),"\n"}};
    return jsonPerson;
  }

  nlohmann::json writePerson() {
    nlohmann::json personJson(_node);
    return personJson;
  }

  void readPerson(const nlohmann::json &j, Person &p) {

  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
