#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>
#include <limits>
#include "LinkedList.h"

extern int numOfPersons = 0; // TODO Uncertain if this is implemented correctly
auto nodeList = FamilyTree::singly_linked_list<Node<Person>>();

class Menu {
private:
    int _state = 0;
public:
    void setState(int state){
        _state = state;
    }
    int getState() const {
        return _state;
    }
    void greeting (){
        std::cout << "                  " << "Welcome to 'FamilyTree'!"<< std::endl;
        std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
        std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;
    }
    int checkInput (std::vector<int> list){
        int input;
        std::cin >> input;
        bool inList = false;
        while (std::cin.fail() or !inList){
            for (int i = 0; i < list.size(); i++){
                if (list[i] == input){
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
        std::cout << "You selected " << input;
        return input;
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
        return input;
    }

    void mainCases (int currentState){
        _state = currentState;
        switch (_state){
            case 1: {
                int index;
                std::string firstName;
                std::string lastName;
                char sex;
                std::vector<int> birth;
                std::vector<int> death;
                std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
                std::cout << "Enter each of the attributes followed by enter." << std::endl;
                std::cout << "Please enter the persons first name: ";
                std::cin >> firstName;
                std::cout << "Please enter the persons last name: ";
                std::cin >> lastName;
                std::cout << "['m' for male, 'f' for female, 'o' for other]";
                std::cout << "Please enter the persons sex: ";
                std::cin >> sex;
                std::cout << "Please enter the date of birth below.";
                std::cout << "Please enter year of birth[yyyy]: ";
                std::cin >> birth[0];
                // TODO Check if int
                std::cout << "Please enter month of birth[mm]: ";
                std::cin >> birth[1];
                // TODO Check if int
                std::cout << "Please enter day of birth[dd]: ";
                std::cin >> birth[2];
                // TODO Check if int
                numOfPersons++;
                index = numOfPersons;

                Node node(Person(index, firstName, lastName, birth, death, sex));
                nodeList.addLast(node);
                break;
            }
            case 2: {
                int a = 0;
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
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }
};

#endif //FAMILYTREE_MENU_H
