//
// Created by Elias Woie Refsdal on 08/03/2022.
//

#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string _firstName, _lastName, _birth, _death;
    char _sex;


public:
    // Constructors
    Person (){}
    Person (std::string firstName, std::string lastName, std::string birth, std::string death, char sex):
            _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex) {}

    // Getters and setters for private variables of Person class
    std::string getFirstName() const {
        return _firstName;
    }
    void setFirstName (std::string firstName) {
        _firstName = firstName;
    }
    std::string getLastName() const {
        return _lastName;
    }
    void setLastName (std::string firstName) {
        _lastName = firstName;
    }
    std::string getBirth () const {
        return _birth;
    }
    void setBirth (std::string birth) {
        _birth = birth;
    }
    std::string getDeath () const {
        return _death;
    }
    void setDeath (std::string death) {
        _death = death;
    }
    char getSex () const {
        return _sex;
    }
    void setSex (char sex) {
        _sex = sex;
    }
    // Destructor
    ~Person(){

    }
};

#endif //FAMILYTREE_PERSON_H
