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
  std::ofstream f;

public:
  explicit JsonFile(const Node<T> &t, std::string fileName)
      : _node(t), _fileName(fileName) {
  }

  void openFile() {
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);
  }

  void closeFile() {
    f.close();
  }

  void jsonToFile(nlohmann::json &j) {
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
    nlohmann::json personJson = personToJson(p);
    return personJson;
  }

  void readPerson(const nlohmann::json &j, Person &p) {

  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
