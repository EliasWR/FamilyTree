#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>
#include <limits>
#include <array>
#include "LinkedList.h"
#include <stdio.h>

// Indexing of persons
// singly linked list holding persons

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
    //Functions for testing user input
    static int checkInput (){
        int input;
        std::cin >> input;
        bool inList = false;
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Not a valid value. Enter a menu option: ";
            std::cin >> input;
        }
        std::cout << "You selected " << input << std::endl;
        return input;
    }

    static int checkCipherAndInput (int length){
        int input;
        std::cin >> input;
        bool rightSize = checkCipherCount(input,length);
        while ((std::cin.fail()) || (!rightSize)){
            rightSize = checkCipherCount(input,length);
            if (!rightSize){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Not a valid value. Try again: ";
                std::cin >> input;
            }
        }
        return input;
    }

    int checkInput (const std::vector<int>& list){
        int input;
        std::cin >> input;
        bool inList = false;
        while (std::cin.fail() || !inList){
            for (int i : list){
                if (i == input){
                    inList = true;
                    break;
                }
            }
            if (!inList){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Not a valid value. Enter a menu option: ";
                std::cin >> input;
            }
        }
        std::cout << "You selected " << input << std::endl;
        return input;
    }

    static bool checkCipherCount(int number, int cipher) {
        bool isCorrect = true;
        int count = 0;
        while(number!=0) {
            number /= 10;
            count ++;
        }
        if (count > cipher) {
            isCorrect = false;
        }
        return isCorrect;
    }

    static bool checkEmptyString(std::string s) {
        while (s.empty()) {
            std::cout<<"You have not typed anything, please try again";
        }
            return true;
    }
    static bool checkSexInput(char c) {

        char m, f, o;
        while (c != m or f or o) {
            std::cout << "You did not type in any of the given options for sex ['m', 'f' or 'o']";
        }
        return true;
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
        std::cout << "Died at "; // TODO This is where i left off
    }

    int mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Edit existing persons relations." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5};
        int input = checkInput (v);
        _state = input;
        return input;
    }

    int editAttribute (){
        std::cout << "You can edit the following attributes" << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Edit existing persons relations." << std::endl;
        std::cout << "[5] Exit program." << std::endl;
        std::cout << "Enter your number followed by enter:";
        std::vector<int> v {1,2,3,4,5};
        int input = checkInput (v);
        _state = input;
        return input;
    }

    Node<Person> createPerson (FamilyTree::singly_linked_list<Node<Person>>& list){
        int index;
        std::string firstName;
        std::string lastName;
        char sex;
        std::array<int,3> birth{};
        std::array<int,3> death{};
        int year;
        int month;
        int day;

        int yearLen = 4;
        int dayAndMonthLen = 2;

        std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
        std::cout << "Type of the attributes followed by enter." << std::endl;
        std::cout << "Please type the persons first name: ";
        std::cin >> firstName;
        checkEmptyString(firstName);
        std::cout << "Please type the persons last name: ";
        std::cin >> lastName;
        checkEmptyString(lastName);
        std::cout << "['m' for male, 'f' for female, 'o' for other]" << std::endl;
        std::cout << "Please enter the persons sex: ";
        std::cin >> sex;
        //TODO Check if sex is "m", "f" or "o"
        // Birth
        std::cout << "Please enter the date of birth below." << std::endl;
        std::cout << "Please enter year of birth[yyyy]: ";
        year = checkCipherAndInput(yearLen);
        birth[0] = year;
        std::cout << "Please enter month of birth[mm]: ";
        month = checkCipherAndInput(dayAndMonthLen);
        birth[1] = month;
        std::cout << "Please enter day of birth[dd]: ";
        day = checkCipherAndInput(dayAndMonthLen);
        birth[2] = day;
        /*
         * TODO Take input bool of _isAlive
         * TODO Make if statement around taking death input
         */
        // Death
        std::cout << "Please enter the date of death below." << std::endl;
        std::cout << "Please enter year of death[yyyy]: ";
        year = checkCipherAndInput(yearLen);
        _death[0] = _year;
        std::cout << "Please enter month of death[mm]: ";
        _month = checkCipherAndInput(_dayAndMonthLen);
        _death[1] = _month;
        std::cout << "Please enter day of death[dd]: ";
        _day = checkCipherAndInput(_dayAndMonthLen);
        _death[2] = _day;

        Node node(Person(_firstName, _lastName, _birth, _death, _sex));
        list.addLast(node);
        return node;
    }

    void removePerson (FamilyTree::singly_linked_list<Node<Person>>& list) {
        std::string firstname, lastname;
        std::cout<<"Please type the firstname of the person you want to remove from the Family Tree: ";
        std::cin>> firstname;
        std::cout<<"Please type the lastname of the person you want to remove from the Family Tree: ";
        std::cin>> lastname; // TODO tests for correct input

        // TODO remove a node from linked list with given key, need to ask Lars on thursday

    }

    void editRelation () {

    }

    void exitProgram () {
        std::cout<<"Thank you for using our Family Tree program! Good bye!";
    }

    // Functions for changing attributes

    void changeFirstName() {

    }

    void changeLastName() {

    }

    void changeBirthDate() {

    }

    void changeDeathDate() {

    }

    void changeSex() {

    }

    //functions for editing relations



    void mainScreenCases (FamilyTree::singly_linked_list<Node<Person>>& list){
        switch (_state){
            case 1: {
                createPerson(list);
                break;
            }

            case 2: {
                removePerson(list);
                break;
            }
            case 3: {
                editAttribute();
                attributeCases(editAttribute());
                break;
            }
            case 4: {
                editRelation();
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

    void attributeCases (int currentState) {
        _state = currentState;
        switch (_state){
            case 1:{
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            default: {
                std::cout << "That was not one of the menu options, please try again";
                break;
            }
        }
    }
};

#endif //FAMILYTREE_MENU_H
