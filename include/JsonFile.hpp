//
// Created by Elias Woie Refsdal on 25/04/2022.
//

#include <iostream>
#include "json.hpp"
#include "Person.hpp"

class JsonFile {
private:
public:
  void writePerson (nlohmann::json &writer, Person p){
    writer["FirstName"] = p.getFirstName;
    writer["LastName"] = p.getLastName();
    writer["birth"] = p.getBirth();
    writer["death"] = p.getDeath();
    writer["sex"] = p.getSex();
  }
};

#ifndef FAMILYTREE_JSONFILE_HPP
#define FAMILYTREE_JSONFILE_HPP

#endif//FAMILYTREE_JSONFILE_HPP
