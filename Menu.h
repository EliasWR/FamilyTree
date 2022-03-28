#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>
#include <limits>
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

    bool checkCipherCount(int number, int cipher) { //Lagde en input test for year/birth osv for å sjekke om det er riktig mengde siffer.
        int count;
        while(number!=0) {
            number /= 10;
            count ++;
        }
        if (count != cipher) {std::cout<<"An incorrect number of ciphers has been inputted, please try again.";}
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

    static Node<Person> createPerson (FamilyTree::singly_linked_list<Node<Person>> list){
        int index;
        std::string firstName;
        std::string lastName;
        char sex;
        std::vector<int> birth;
        std::vector<int> death;
        int year;
        int month;
        int day;

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
        std::cin >> year;
        birth.push_back(year); // TODO Check if input is valid

        std::cout << "Please enter month of birth[mm]: ";
        std::cin >> month;
        birth.push_back(month); // TODO Check if input is valid

        std::cout << "Please enter day of birth[dd]: ";
        std::cin >> day;
        birth.push_back(day); // TODO Check if input is valid
        // Death
        std::cout << "Please enter the date of death below." << std::endl;
        std::cout << "Please enter year of death[yyyy]: ";
        std::cin >> year;
        death.push_back(year); // TODO Check if input is valid
        std::cout << "Please enter month of death[mm]: ";
        std::cin >> month;
        death.push_back(month); // TODO Check if input is valid
        std::cout << "Please enter day of death[dd]: ";
        std::cin >> day;
        death.push_back(day); // TODO Check if input is valid
        index = list.getSize();
        Node node(Person(index, firstName, lastName, birth, death, sex));
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
