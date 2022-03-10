//
// Created by Elias Woie Refsdal on 08/03/2022.
//

#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _birth;
    std::string _death;
    char _sex;

public:
    // Getters and setters for private variables
    std::string getFirstName(){
        return _firstName;
    }
    void setFirstName (std::string firstName){
        _firstName = firstName;
    }
    std::string getLastName(){
        return _lastName;
    }
    void setLastName (std::string firstName){
        _lastName = firstName;
    }
    std::string getBirth (){
        return _birth;
    }
    void setBirth (std::string birth){
        _birth = birth;
    }
    std::string getDeath (){
        return _death;
    }
    void setBirth (std::string death){
        _death = death;
    }
    char getBirth (){
        return _sex;
    }
    void setBirth (char sex){
        _sex = sex;
    }
};

#endif //FAMILYTREE_PERSON_H
