//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include <iostream>
#include "json.hpp"
#include "Person.hpp"
#include "Node.hpp"

class JsonFile {
private:
  const std::string _fileName = "FamilyTree.json";
public:
  void openFile () {
    std::ofstream f;
    f.open(_fileName, std::ios_base::trunc | std::ios_base::out);

  }

  void readFile () {
    std::ifstream i(_fileName);
    nlohmann::json j;
    i >> j;
  }

  void writeJsonToFile(nlohmann::json j){

  }
/*
  Node<Person> readPerson (){

    Node<Person> a ();
    return a;
  }
*/
  void writePerson (nlohmann::json &writer, Person p){
    writer["FirstName"] = p.getFirstName();
    writer["LastName"] = p.getLastName();
    writer["birth"] = p.getBirth();
    writer["death"] = p.getDeath();
    writer["sex"] = p.getSex();
  }

};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
