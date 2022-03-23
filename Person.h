//
// Created by Elias Woie Refsdal on 08/03/2022.
//

#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    int _index;
    std::vector<int> _birth, _death;
    std::string _firstName, _lastName;
    char _sex;

public:

    // Constructors
    //
    Person (){}
    Person (int index, std::string firstName):_index(index), _firstName(firstName){}
    Person (std::string firstName, std::string lastName, std::vector<int> birth, std::vector<int> death, char sex):
            _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex) {}

    // Getters and setters for private variables of Person class
    int getIndex() const {
        return _index;
    }
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
    std::vector<int> getBirth () const {
        return _birth;
    }
    void setBirth (int year, int month, int day) {
        _birth[0] = year;
        _birth[1] = month;
        _birth[2] = day;
    }
    std::vector<int> getDeath () const {
        return _death;
    }
    void setDeath (int year, int month, int day) {
        _birth[0] = year;
        _birth[1] = month;
        _birth[2] = day;
    }
    char getSex () const {
        return _sex;
    }
    void setSex (char sex) {
        _sex = sex;
    }

    /*
     * TODO Add date handling method for returning three integers with day, month and year of death // Check
     * TODO Add file reading class
     * TODO Add menu class
     * TODO Exception handling
     * TODO Tests for code
     * TODO Big O notation on traversal algorithms
     * TODO Fjerne autogenererte notater øverst og legge til kandidatnr i ReadMe
     * TODO Linked list with bubble sort
     */
};

#endif //FAMILYTREE_PERSON_H
