#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
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

    void writePerson (XmlWriter &write){
        write.writeString(_firstName);
        write.writeString(_lastName);
        write.writeString(_sex);
        write.writeString(_birth[0]);
        write.writeString(_birth[1]);
        write.writeString(_birth[2]);
        write.writeString(_death[0]);
        write.writeString(_death[1]);
        write.writeString(_death[2]);
    }
    void readPerson (std::string fileName){
        std::string sex;
        std::array<std::string,3> birth{};
        std::array<std::string,3> death{};
        std::string year;
        std::ifstream inFile(fileName);
        inFile >> _firstName >> _lastName >> sex >> birth[0] >> birth[1] >>birth[2] >> death[0] >> death[1] >> death[2];
        for (int i = 0; i <= 2; i++){
            _birth[i] = std::atoi(birth[i].c_str());
            _death[i] = std::atoi(death[i].c_str());
        }
        _sex = sex[0];
    }
};

#endif //FAMILYTREE_PERSON_H
