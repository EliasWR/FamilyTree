#ifndef FAMILYTREE_MENU_HPP
#define FAMILYTREE_MENU_HPP

#include <iostream>
#include <limits>
#include <array>
#include "LinkedList.hpp"
#include "ExceptionHandling.hpp"
#include "Node.hpp"



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
    Node<Person> _node;
    Node<Person> _rootNode;

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

    int mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Show existing persons attributes." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5};
        int input = ExceptionHandling::checkInput(v);
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
        int input = ExceptionHandling::checkInput (v);
        _state = input;
        return input;
    }

    //functions for main screen options
    Node<Person> createPerson (){

        // Firstname
        std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
        std::cout << "Type of the attributes followed by enter." << std::endl;
        std::cout << "Please type the persons first name: ";
        std::cin >> _firstName;
        ExceptionHandling::checkUpperCase(_firstName);
        ExceptionHandling::checkEmptyString(_firstName);

        // Lastname
        std::cout << "Please type the persons last name: ";
        std::cin >> _lastName;
        ExceptionHandling::checkEmptyString(_lastName);
        ExceptionHandling::checkUpperCase(_lastName);

        // Sex
        std::cout << "Please enter the persons sex ['m' for male, 'f' for female, 'o' for other]" << std::endl;;
        std::cin >> _sex;
        ExceptionHandling::checkSexInput();

        // Birth
        std::cout << "Please enter the date of birth below." << std::endl;
        std::cout << "Please enter year of birth[yyyy]: ";
        _year = ExceptionHandling::checkCipherAndInput(_yearLen);
        _birth[0] = _year;
        std::cout << "Please enter month of birth[mm]: ";
        _month = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        _birth[1] = _month;
        std::cout << "Please enter day of birth[dd]: ";
        _day = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        _birth[2] = _day;

        // Death
        std::cout << "Please enter the date of death below." << std::endl;
        std::cout << "Please enter year of death[yyyy]: ";
        _year = ExceptionHandling::checkCipherAndInput(_yearLen);
        _death[0] = _year;
        std::cout << "Please enter month of death[mm]: ";
        _month = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        _death[1] = _month;
        std::cout << "Please enter day of death[dd]: ";
        _day = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        _death[2] = _day;

        Node node(Person(_firstName, _lastName, _birth, _death, _sex));

        // TODO add relation

        return node;
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


    void exitProgram () {
        char e = 'e';
        char b = 'b';
        char a;

        std::cout<<"Are you sure yo want to exit the program? If yes, type 'e'. If no type 'b'."<<std::endl;
        std::cin>>a;
        while ((a != e) && (a != b)) {
            std::cout << "Sorry but that was not one of the given options ['e' or 'b']. Please try again"<<std::endl;
            std::cin>>a;
        }
        if (a == b) {
            mainScreen();
        }
        std::cout<<"Thank you for using our Family Tree program! Good bye!";
    }

    // Functions for changing attributes

    std::string getUserInputFirstName() {
        std::cout<< "Please enter the firstname of the person you would like to edit [Firstname]"<<std::endl;
        std::cin>>_firstName;
        ExceptionHandling::checkUpperCase(_firstName);
        ExceptionHandling::checkEmptyString(_firstName);
        return _firstName;
    }

    std::string getUserInputLastName() {
        std::cout<< "Please enter the lastname of the person you would like to edit [Lastname]"<< std::endl;
        std::cin>> _lastName;
        ExceptionHandling::checkUpperCase(_lastName);
        ExceptionHandling::checkEmptyString(_firstName);
        return _lastName;
    }

    void changeFirstName() {
        getUserInputFirstName();
        getUserInputLastName();

        std::string newFirstName;
        std::cout<< "Now please enter the new firstname of the person you chose " << std::endl;
        std::cin>> newFirstName;
        ExceptionHandling::checkUpperCase(newFirstName);
        ExceptionHandling::checkEmptyString(newFirstName);

        auto lambda = [newFirstName](Person &p){p.setFirstName(newFirstName);};
        _node.traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);

        }

    void changeLastName() {
        getUserInputFirstName();
        getUserInputLastName();

        std::string newLastName;
        std::cout << "Now please enter the new lastname of the person you chose " <<std::endl;
        std::cin>> newLastName;
        ExceptionHandling::checkUpperCase(newLastName);
        ExceptionHandling::checkEmptyString(newLastName);

        auto lambda = [newLastName](Person &p){p.setLastName(newLastName);};
        _node.traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeBirthDate() {
        getUserInputFirstName();
        getUserInputLastName();
        int newYear;
        int newMonth;
        int newDay;

        std::array<int,3> newBirthDate{};
        std::cout << "Now please enter the new year of birth of the person you chose [yyyy]" << std::endl;
        std::cin>> newYear;
        newYear = ExceptionHandling::checkCipherAndInput(_yearLen);
        std::cout << "Now please enter the new month of birth of the person you chose [mm]" <<std::endl;
        std::cin >> newMonth;
        newMonth = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        std::cout << "Now please enter the new day of birth of the person you chose [dd]" <<std::endl;
        std::cin >> newDay;
        newDay = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);

        auto lambda = [newYear, newMonth, newDay](Person &p){p.setBirth(newYear, newMonth, newDay);};
        _node.traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeDeathDate() {
        getUserInputFirstName();
        getUserInputLastName();
        int newYear;
        int newMonth;
        int newDay;

        std::array<int,3> newDeathDate{};

        std::cout << "Now please enter the new year of death of the person you chose [yyyy]" << std::endl;
        std::cin >> newYear;
        newYear = ExceptionHandling::checkCipherAndInput(_yearLen);
        std::cout << "Now please enter the new month of death of the person you chose [mm]" << std::endl;
        std::cin >> newMonth;
        newMonth = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        std::cout << "Now please enter the new day of the death of the person you chose [dd]" << std::endl;
        std::cin >> newDay;
        newDay = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);

        auto lambda = [newYear, newMonth, newDay](Person &p){p.setDeath(newYear, newMonth, newDay);};
        _node.traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeSex() {
        getUserInputFirstName();
        getUserInputLastName();

        char newSex;
        std::cout << "Now please enter the new sex of the person you chose ['m' for male, 'f' for female, or 'o' for other]" << std::endl;
        std::cin >> newSex;
        ExceptionHandling::checkSexInput();

        auto lambda = [newSex](Person &p){p.setSex(newSex);};
        _node.traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    //functions for editing relations



    void mainScreenCases (FamilyTree::singly_linked_list<Node<Person>>& list){
        switch (_state){
            case 1: {
                createPerson(list);
                mainScreen();
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
                getPersonInfo();
                mainScreen();
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
                mainScreen();
                break;
            }
            case 2: {
                changeLastName();
                mainScreen();
                break;
            }
            case 3: {
                changeBirthDate();
                mainScreen();
                break;
            }
            case 4: {
                changeDeathDate();
                mainScreen();
                break;
            }
            case 5: {
                changeSex();
                mainScreen();
                break;
            }
            case 6: {
                exitProgram();
                break;
            }
            default: {
                std::cout << "That was not one of the menu options, please try again";
                editAttributes();
                break;
            }
        }
    }
};

#endif//FAMILYTREE_MENU_HPP
