//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include "Node.hpp"
#include "Person.hpp"
#include "json.hpp"
#include <iostream>

namespace nlohmann {
  template <class T>
  // Overloading the json functions from the nlohmann library
  void to_json (json& j, std::shared_ptr<Node<T>> n){
    throw std::runtime_error("Unknown type T");
  };

  void to_json (json& j, std::shared_ptr<Node<Person>> n) {
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

  template <class T>
  void from_json (json& j, std::shared_ptr<Node<T>> n){
    throw std::runtime_error("Unknown type T");
  };
}

template<class T>
class JsonFile {
private:
  const std::string _fileName;
  std::shared_ptr<Node<T>> &_rootNode;
  std::ofstream f;
  nlohmann::json j;
  std::string _firstName, _lastName, _birth, _death, _sex, _parentFirstName, _parentLastName;

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

  nlohmann::json readFile (nlohmann::json j) {
    std::ifstream file(_fileName);
    file >> j;
    return j;
  }

  nlohmann::json writePerson() {
    nlohmann::json personJson(_rootNode);
    return personJson;
  }

  void readPerson(const nlohmann::json &j, Person &p) {

  }

  Person personFromJson (nlohmann::json& j){
    if (j.contains("FirstName")) { _firstName = j.at("FirstName"); }
    if (j.contains("LastName")) { _lastName = j.at("LastName"); }
    if (j.contains("Birth")) { _birth = j.at("Birth"); }
    if (j.contains("Death")) { _death = j.at("Death"); }
    if (j.contains("Sex")) { _sex = j.at("Sex"); }

    Person person (_firstName, _lastName, _birth, _death, _sex);
    return person;
  }

  std::shared_ptr<Node<Person>> nodeFromJson (nlohmann::json& j, std::shared_ptr<Node<Person>> rootNode){
    Person person;

    if (rootNode->isEmpty()) {
      person = personFromJson (j);
      rootNode = std::make_shared<Node<Person>>(person);
    }

    if (j.contains("Children") && !j.at("Children").empty()) {
      if (j.contains("FirstName")) { _parentFirstName = j.at("FirstName"); }
      if (j.contains("LastName")) { _parentLastName = j.at("LastName"); }
      for (auto jsonChildNode : j.at("Children")) {
        person = personFromJson (jsonChildNode);
        auto lambda = [person] (Node<Person> &node){ node.add(person);};
        rootNode->traverseDepth(lambda, _parentFirstName, _parentLastName);
        nodeFromJson (jsonChildNode, rootNode);
      }
    }
    return rootNode;
  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
