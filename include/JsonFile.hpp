//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include <iostream>
#include "json.hpp"
#include "Person.hpp"
#include "Node.hpp"

template <class T>
class JsonFile {
private:
  const std::string _fileName = "FamilyTree.json";
public:
  void openFile (std::ofstream& f) {
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);
  }

  void closeFile (std::ofstream& f){
    f.close();
  }

  void jsonToFile (std::ofstream& f, nlohmann::json& j){
    f << j;
  }

  void readFile () {
    std::ifstream i(_fileName);
    nlohmann::json j;
    i >> j;
  }

  void writeJsonToFile(nlohmann::json j){

  }

  nlohmann::json writePerson (Node<Person> node){
    Person p = node.getPerson();

    std::shared_ptr<T> person = node.getParent();
    nlohmann::json_pointer parent = person;



    nlohmann::json writer =
    {
        {
         {"FirstName", p.getFirstName()},
         {"LastName", p.getLastName()},
         {"birth", p.getBirth()},
         {"death", p.getDeath()},
         {"sex", p.getSex()}
        }

      };
    return writer;
  }

  void readPerson (const nlohmann::json& j, Person& p){

  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
