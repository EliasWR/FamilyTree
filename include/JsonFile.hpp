//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <iostream>

template<class T>
class JsonFile {
private:
  const std::string _fileName;
  const Node<T> &_node;

public:
  explicit JsonFile(const Node<T> &t, std::string fileName)
      : _node(t), _fileName(fileName){
  }

  void openFile() {
    std::ofstream f;
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);
  }

  void closeFile(std::ofstream &f) {
    f.close();
  }

  void jsonToFile(std::ofstream &f, nlohmann::json &j) {
    f << j;
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
      {"birth", p.getBirth()},
      {"death", p.getDeath()},
      {"sex", p.getSex()}};
    return jsonPerson;
  }

  nlohmann::json writePerson() {
    Person p = _node.getPerson();
    auto personJson = personToJson (p);

}

void
readPerson(const nlohmann::json &j, Person &p) {
}
}
;

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
