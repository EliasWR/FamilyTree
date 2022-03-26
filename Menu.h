#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>
#include <limits>

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

    int mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Edit existing persons relations." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        int selectedNum;
        std::cin >> selectedNum;
        return selectedNum;
    }

    int editAttribute (){
        std::cout << "You can edit the following attributes" << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Edit existing persons relations." << std::endl;
        std::cout << "[5] Exit program." << std::endl;
        std::cout << "Enter your number followed by enter:";
        int selectedNum;
        std::cin >> selectedNum;
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Not a valid number. Enter a menu option: ";
            std::cin >> selectedNum;
        }
        std::cout << "Number is" <<selectedNum;
        return selectedNum;
    }

    int throwIntException (int userInput, int range){
        if (userInput < 1){

        } else if (userInput > range){}
        return userInput;
    }

    void mainCases (int currentState){
        _state = currentState;
        switch (_state){
            case 0:

                break;
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }

    void attributeCases (int currentState){
        _state = currentState;
        switch (_state){
            case 0:

                break;
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
