#ifndef FAMILYTREE_PERSON_H
#define FAMILYTREE_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <array>

class Person {
private:
    int _index;
    std::vector<int> _birth, _death;                    // TODO Resize vector or use fixed array with size 3
    std::string _firstName, _lastName;
    char _sex;
    //std::array<int,3> a = {yyyy,mm,dd}

public:
    // Constructors
    Person (){}
    Person (int index, std::string firstName):_index(index), _firstName(firstName){}
    Person (int index, std::string firstName, std::string lastName, std::vector<int> birth, std::vector<int> death, char sex):
            _index(index), _firstName(firstName), _lastName(lastName), _birth(birth), _death(death), _sex(sex){}

    // Getters and setters for private variables of Person class
    [[nodiscard]]int getIndex() const {
        return _index;
    }
    void setIndex (int index){
        _index = index;
    }
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
    [[nodiscard]]std::vector<int> getBirth () const {
        return _birth;
    }
    void setBirth (int year, int month, int day) {
        _birth[0] = year;
        _birth[1] = month;
        _birth[2] = day;
    }
    [[nodiscard]]std::vector<int> getDeath () const {
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
};

#endif //FAMILYTREE_PERSON_H
