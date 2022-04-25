#ifndef FAMILYTREE_MENU_HPP
#define FAMILYTREE_MENU_HPP

#include <iostream>
#include <limits>
#include <array>
#include "LinkedList.hpp"
#include <cstdio>
#include <cctype>
#include "ExceptionHandling.hpp"


// Indexing of persons
// singly linked list holding persons
template <class T>
class Menu {
private:
    int _state = 0;
    std::string _firstName;
    std::string _lastName;
    char _sex;
    std::array<int,3> _birth{};
    std::array<int,3> _death{};
    bool _isAlive;
    int _year;
    int _month;
    int _day;
    int _yearLen = 4;
    int _dayAndMonthLen = 2;

public:
    void setState(int state){
        _state = state;
    }
    [[nodiscard]] int getState() const {
        return _state;
    }
    void greeting (){
        std::cout << "                  " << "Welcome to 'FamilyTree'!"<< std::endl;
        std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
        std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;
    }

    void getPersonInfo (Node<Person>& node) {
        Person person = node.getPerson();
        std::string firstName = person.getFirstName();
        std::string lastName = person.getLastName();
        std::array <int,3> birth = person.getBirth();
        std::array <int,3> death = person.getDeath();
        char _sex = person.getSex();
        std::cout << firstName << " " << lastName;
        std::cout << "Is born ";
        for (int i:birth){
            std::cout << i << ".";
        }
        std::cout << "Died at ";
        for (int i:death) {
            std::cout << i << ".";
        }
        std::cout << "and is considered the sex ";
        std::cout << _sex;
    }

    int mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Edit existing persons relations." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5};
        int input = checkInput(v);
        _state = input;
        return input;
    }

    int editAttributes (){
        std::cout << "You can edit the following information of your family tree" << std::endl;
        std::cout << "[1] Edit existing persons firstname" << std::endl;
        std::cout << "[2] Edit existing persons lastname" <<std::endl;
        std::cout << "[3] Edit existing persons birthday" << std::endl;
        std::cout << "[4] Edit exising persons day of death" << std::endl;
        std::cout << "[5] Edit existing persons sex" << std::endl;
        std::cout << "[6] Exit program." << std::endl;
        std::cout << "Enter your number followed by enter:";
        std::vector<int> v {1,2,3,4,5,6};
        int input = checkInput (v);
        _state = input;
        return input;
    }

    //functions for main screen options
    Node<Person> createPerson (){

        std::array<int,3> birth{};
        std::array<int,3> death{};

        // Firstname
        std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
        std::cout << "Type of the attributes followed by enter." << std::endl;
        std::cout << "Please type the persons first name: ";
        std::cin >> _firstName;
        checkUpperCase(_firstName);
        checkEmptyString(_firstName);

        // Lastname
        std::cout << "Please type the persons last name: ";
        std::cin >> _lastName;
        checkEmptyString(_lastName);
        checkUpperCase(_lastName);

        // Sex
        std::cout << "Please enter the persons sex ['m' for male, 'f' for female, 'o' for other]" << std::endl;;
        std::cin >> _sex;
        checkSexInput();

        // Birth
        std::cout << "Please enter the date of birth below." << std::endl;
        std::cout << "Please enter year of birth[yyyy]: ";
        _year = checkCipherAndInput(_yearLen);
        _birth[0] = _year;
        std::cout << "Please enter month of birth[mm]: ";
        _month = checkCipherAndInput(_dayAndMonthLen);
        _birth[1] = _month;
        std::cout << "Please enter day of birth[dd]: ";
        _day = checkCipherAndInput(_dayAndMonthLen);
        _birth[2] = _day;

        // Death
        std::cout << "Please enter the date of death below." << std::endl;
        std::cout << "Please enter year of death[yyyy]: ";
        _year = checkCipherAndInput(_yearLen);
        _death[0] = _year;
        std::cout << "Please enter month of death[mm]: ";
        _month = checkCipherAndInput(_dayAndMonthLen);
        _death[1] = _month;
        std::cout << "Please enter day of death[dd]: ";
        _day = checkCipherAndInput(_dayAndMonthLen);
        _death[2] = _day;

        Node node(Person(_firstName, _lastName, _birth, _death, _sex));

        // TODO add relation

        return node;
    }

    void exitProgram () {
        std::cout<<"Thank you for using our Family Tree program! Good bye!";
        //TODO exit program in a proper way
    }

    // Functions for changing attributes

    std::string getUserInputFirstName() {
        std::cout<< "Please enter the firstname of the person you would like to edit [Firstname]"<<std::endl;
        std::cin>>_firstName;
        checkUpperCase(_firstName);
        checkEmptyString(_firstName);
        return _firstName;
    }

    std::string getUserInputLastName() {
        std::cout<< "Please enter the lastname of the person you would like to edit [Lastname]"<< std::endl;
        std::cin>> _lastName;
        checkUpperCase(_lastName);
        checkEmptyString(_firstName);
        return _lastName;
    }

    void changeFirstName(std::function<void(Node<T> *)> root) {
        getUserInputFirstName();
        getUserInputLastName();

        std::string newFirstName;
        std::cout<< "Now please enter the new firstname of the person you chose " << std::endl;
        std::cin>> newFirstName;
        checkUpperCase(newFirstName);
        checkEmptyString(newFirstName);

        // TODO implement TDS function when ready

        }

    void changeLastName() {
        getUserInputFirstName();
        getUserInputLastName();

        std::string newLastName;
        std::cout << "Now please enter the new lastname of the person you chose " <<std::endl;
        std::cin>> newLastName;
        checkUpperCase(newLastName);
        checkEmptyString(newLastName);

        // TODO implement TDS function when ready
    }

    void changeBirthDate() {
        getUserInputFirstName();
        getUserInputLastName();

        std::array<int,3> newBirthDate{};
        std::cout << "Now please enter the new year of birth of the person you chose [yyyy]" << std::endl;
        _birth[0] = _year;
        _year = checkCipherAndInput(_yearLen);
        std::cout << "Now please enter the new month of birth of the person you chose [mm]" <<std::endl;
        _birth[1] = _month;
        _month = checkCipherAndInput(_dayAndMonthLen);
        std::cout << "Now please enter the new day of birth of the person you chose [dd]" <<std::endl;
        _birth[2] = _day;
        _day = checkCipherAndInput(_dayAndMonthLen);

        newBirthDate[_birth[2], _birth[1], _birth[0]];

        // TODO implement TDS function when ready
    }

    void changeDeathDate() {
        getUserInputFirstName();
        getUserInputLastName();

        std::array<int,3> newDeathDate{};

        std::cout << "Now please enter the new year of death of the person you chose [yyyy]" << std::endl;
        _death[0] = _year;
        _year = checkCipherAndInput(_yearLen);
        std::cout << "Now please enter the new month of death of the person you chose [mm]" << std::endl;
        _death[1] = _month;
        _month = checkCipherAndInput(_dayAndMonthLen);
        std::cout << "Now please enter the new day of the death of the person you chose [dd]" << std::endl;
        _death[2] = _day;
        _day = checkCipherAndInput(_dayAndMonthLen);

        newDeathDate[_death[2], _death[1], _death[0]];

        // TODO implement TDS function when ready
    }

    void changeSex() {
        getUserInputFirstName();
        getUserInputLastName();

        char newSex;
        std::cout << "Now please enter the new sex of the person you chose ['m' for male, 'f' for female, or 'o' for other]" << std::endl;
        std::cin >> newSex;
        checkSexInput();

        // TODO implement TDS function when ready
    }

    //functions for editing relations



    void mainScreenCases (FamilyTree::singly_linked_list<Node<Person>>& list){
        switch (_state){
            case 1: {
                createPerson(list);
                break;
            }

            case 2: {
                break;
            }
            case 3: {
                editAttributes();
                editAttributeCases(editAttributes());
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                exitProgram();
                break;
            }
            default: {
                std::cout << "That was not one of your menu options, please try again";
                mainScreen();
                break;
            }
        }
    }

    void editAttributeCases (int currentState) {
        _state = currentState;
        switch (_state){
            case 1:{
                changeFirstName();
                break;
            }
            case 2: {
                changeLastName();
                break;
            }
            case 3: {
                changeBirthDate();
                break;
            }
            case 4: {
                changeDeathDate();
                break;
            }
            case 5: {
                changeSex();
                break;
            }
            case 6: {
                exitProgram();
                break;
            }
            default: {
                std::cout << "That was not one of the menu options, please try again";
                break;
            }
        }
    }
};

#endif//FAMILYTREE_MENU_HPP
