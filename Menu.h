#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>
#include <limits>
#include <array>
#include "LinkedList.h"

// Indexing of persons
// singly linked list holding persons

class Menu {
private:
    int _state = 0;
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
        while (std::cin.fail() or !rightSize){
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
        while (std::cin.fail() or !inList){
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

    void getPersonInfo (Node<Person>& node) {
        Person person = node.getPerson();
        int index = person.getIndex();
        std::string firstName = person.getFirstName();
        std::string lastName = person.getLastName();
        std::array <int,3> birth = person.getBirth();
        std::array <int,3> death = person.getDeath();
        char sex = person.getSex();
        std::cout << firstName << " " << lastName;
        std::cout << "Is born ";
        for (int i:birth){
            std::cout << i << " ";
        }
        std::cout << "Died at ";
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

    static Node<Person> createPerson (FamilyTree::singly_linked_list<Node<Person>>& list){
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
        std::cout << "Please type the persons last name: ";
        std::cin >> lastName;
        std::cout << "['m' for male, 'f' for female, 'o' for other]" << std::endl;
        std::cout << "Please enter the persons sex: ";
        std::cin >> sex;
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
        // Death
        std::cout << "Please enter the date of death below." << std::endl;
        std::cout << "Please enter year of death[yyyy]: ";
        year = checkCipherAndInput(yearLen);
        death[0] = year;
        std::cout << "Please enter month of death[mm]: ";
        month = checkCipherAndInput(dayAndMonthLen);
        death[1] = month;
        std::cout << "Please enter day of death[dd]: ";
        day = checkCipherAndInput(dayAndMonthLen);
        death[2] = day;

        index = list.getSize();
        Node node(Person(index, firstName, lastName, birth, death, sex));
        list.addLast(node);
        return node;
    }

    void mainCases (){
        switch (_state){
            case 1: {
                break;
            }

            case 2: {
                break;
            }
            default: {
                std::cout << "That is not one of your menu options";
                mainScreen();
                break;
            }
        }
    }

    void attributeCases (int currentState){
        _state = currentState;
        switch (_state){
            case 1:{
                break;
            }
            case 2: {
                break;
            }
            default: {
                break;
            }
        }
    }
};

#endif //FAMILYTREE_MENU_H
