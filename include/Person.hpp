#ifndef FAMILYTREE_PERSON_HPP
#define FAMILYTREE_PERSON_HPP

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include "json.hpp"

class Person {
private:
    std::string _firstName, _lastName, _birth, _death, _sex;

public:
    // Constructors
    Person (){}
    Person (std::string firstName, std::string lastName):_firstName(firstName), _lastName(lastName){}
    Person (std::string firstName, std::string lastName, std::string birth, std::string death, std::string sex):
            _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex){}

    // Getters and setters for private variables of Person class
    [[nodiscard]]std::string getFirstName() const {
        return _firstName;
    }
    void setFirstName (std::string firstName) {
        _firstName = firstName;
    }
    [[nodiscard]]std::string getLastName() const {
        return _lastName;
    }
    void setLastName (std::string lastName) {
        _lastName = lastName;
    }
    [[nodiscard]]std::string getBirth () const {
        return _birth;
    }
    void setBirth (std::string birth) {
        _birth = birth;
    }
    [[nodiscard]]std::string getDeath () const {
        return _death;
    }
    void setDeath (std::string death) {
        _death = death;
    }
    [[nodiscard]]std::string getSex () const {
        return _sex;
    }
    void setSex (std::string sex) {
        _sex = sex;
    }

    void printPersonInfo() {
        std::cout << _firstName << " " << _lastName;
        std::cout << "Is born ";
        for (int i:_birth){
            std::cout << i << ".";
        }
        std::cout << "Died at ";
        for (int i:_death) {
            std::cout << i << ".";
        }
        std::cout << "and is considered the sex ";
        std::cout << _sex;
    }
};

#endif//FAMILYTREE_PERSON_HPP
