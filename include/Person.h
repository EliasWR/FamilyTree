#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "FileHandling.h"

class Person {
private:
    std::array<int,3> _birth{};
    std::array<int,3> _death{};
    std::string _firstName, _lastName;
    char _sex;

public:
    // Constructors
    Person (){}
    Person (std::string firstName):_firstName(firstName){}
    Person (std::string firstName, std::string lastName, std::array<int,3> birth, std::array<int,3> death, char sex):
            _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex){}

    //TODO Add bool isAlive to private and constructor.

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
    void setLastName (std::string firstName) {
        _lastName = firstName;
    }
    [[nodiscard]]std::array<int,3> getBirth () const {
        return _birth;
    }
    void setBirth (int year, int month, int day) {
        _birth[0] = year;
        _birth[1] = month;
        _birth[2] = day;
    }
    [[nodiscard]]std::array<int,3> getDeath () const {
        return _death;
    }
    void setDeath (int year, int month, int day) {
        _birth[0] = year;
        _birth[1] = month;
        _birth[2] = day;
    }
    [[nodiscard]]char getSex () const {
        return _sex;
    }
    void setSex (char sex) {
        _sex = sex;
    }

    void writePerson (XmlWriter writer){
        writer.writeString(_firstName);
        writer.writeString(_lastName);
    }
};

#endif //FAMILYTREE_PERSON_H
