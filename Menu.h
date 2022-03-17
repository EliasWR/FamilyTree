//
// Created by Elias Woie Refsdal on 17/03/2022.
//

#ifndef FAMILYTREE_MENU_H
#define FAMILYTREE_MENU_H

#include <iostream>

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



};

#endif //FAMILYTREE_MENU_H
