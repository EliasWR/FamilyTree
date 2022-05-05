#ifndef FAMILYTREE_MENU_HPP
#define FAMILYTREE_MENU_HPP

#include <iostream>
#include <limits>
#include <array>
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
    char _sex = '0';
    std::string _birth;
    std::string _death;
    bool _isAlive;
    std::shared_ptr<Node<Person>> _rootNode = nullptr;
    bool _exitMenu = false;

public:
  Menu (){}

  void setState(int state) {
      _state = state;
  }

  [[nodiscard]] int getState() const {
    return _state;
  }

  void setExitMenu (bool exitMenu) {
    _exitMenu = exitMenu;
  }

  [[nodiscard]] bool getExitMenu (){
    return _exitMenu;
  }

    void greeting () {
        std::cout << "                  " << "Welcome to 'FamilyTree'!"<< std::endl;
        std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
        std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;
    }

    void feedback (){
      std::cout << "Operation was successfully executed"<< std::endl << std::endl;
    }

    void mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Show existing persons attributes." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5};
        int input = ExceptionHandling::checkIntAndList(v);
        _state = input;
        mainScreenCases();
    }

    int editAttributes (){
        std::cout << "You can edit the following information of your family tree" << std::endl;
        std::cout << "[1] Edit existing persons firstname" << std::endl;
        std::cout << "[2] Edit existing persons lastname" <<std::endl;
        std::cout << "[3] Edit existing persons birthday" << std::endl;
        std::cout << "[4] Edit exising persons day of death" << std::endl;
        std::cout << "[5] Edit existing persons sex" << std::endl;
        std::cout << "[6] Exit program." << std::endl;
        std::cout << "Enter your number followed by enter:"<< std::endl;
        std::vector<int> v {1,2,3,4,5,6};
        int input = ExceptionHandling::checkIntAndList(v);
        _state = input;
        return input;
    }

    //functions for main screen options
    void savePersonInfo (){

        // Firstname
        std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
        std::cout << "Type of the attributes followed by enter." << std::endl;
        std::cout << "Please type the persons first name: "<< std::endl;
        std::cin >> _firstName;
        ExceptionHandling::checkUpperCase(_firstName);
        ExceptionHandling::checkEmptyString(_firstName);

        // Lastname
        std::cout << "Please type the persons last name: "<< std::endl;
        std::cin >> _lastName;
        ExceptionHandling::checkEmptyString(_lastName);
        ExceptionHandling::checkUpperCase(_lastName);

        // Sex
        std::cout << "Please enter the persons sex ['m' for male, 'f' for female, 'o' for other]" << std::endl;
        std::cin >> _sex;
        ExceptionHandling::checkSexInput();

        // Birth
        std::cout << "Now please enter the date of birth in the following format[dd.mm.yyyy]" << std::endl;
        _birth = getDate();

        // Death
        std::cout << "Now please enter the date of birth in the following format[dd.mm.yyyy]" << std::endl;
        _birth = getDate();
    }


    void createFirstPerson() {
      _rootNode = std::make_shared<Node<Person>>(Person(_firstName, _lastName, _birth, _death, _sex));
  }

  void createGeneralPerson() {
      Person p(_firstName, _lastName, _birth, _death, _sex);
      auto lambda1 = [p](Node<Person> &node) {node.add(p);};
      _rootNode->traverseDepth (lambda1,getUserInputFirstName(),getUserInputLastName());
  }


    void getPersonInfo () {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();
        auto lambda = [](Person p) { p.printPersonInfo(); };
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    }

    void exitProgram () {
        char a = 'a';
        char e = 'e';
        char input;

        std::cout << "Are you sure you want to exit the program?"<< std::endl;
        std::cout << "To return to the main menu, type 'b'" << std::endl;
        std::cout << "To exit program, type 'e'" << std::endl;
        std::cin>>input;
        ExceptionHandling::checkUserInput(input);

        if (input == a) {
            mainScreen();
        }
        else if (input == e){
          std::cout << "Thank you for using our Family Tree program! Good bye!" << std::endl;
          _exitMenu = true;
        }
        else{
          std::cout << "Your input could not be interpreted, terminating program." << std::endl;
          _exitMenu = true;
        }
    }

    // Functions for changing attributes

    std::string getUserInputFirstName() {
        std::string traversalFirstName;

        std::cout<< "Please enter the firstname of the person [Firstname]"<<std::endl;
        std::cin>>traversalFirstName;
        ExceptionHandling::checkUpperCase(traversalFirstName);
        ExceptionHandling::checkEmptyString(traversalFirstName);
        return traversalFirstName;
    }

    std::string getUserInputLastName() {
        std::string traversalLastName;

        std::cout<< "Please enter the lastname of the person [Lastname]"<< std::endl;
        std::cin>> traversalLastName;
        ExceptionHandling::checkUpperCase(traversalLastName);
        ExceptionHandling::checkEmptyString(traversalLastName);
        return traversalLastName;
    }

    std::string getDate () {
      std::string date;
      ExceptionHandling e;
      bool dateStr = false;
      while (!dateStr) {
        std::cin >> date;
        dateStr = e.checkDateLength(date);
      }
      return date;
    }

    void changeFirstName() {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();
        std::string newFirstName;

        std::cout<< "Now please enter the new firstname of the person you chose " << std::endl;
        std::cin>> newFirstName;
        ExceptionHandling::checkUpperCase(newFirstName);
        ExceptionHandling::checkEmptyString(newFirstName);

        auto lambda = [newFirstName](Person &p){p.setFirstName(newFirstName);};
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        }

    void changeLastName() {
        getUserInputFirstName();
        getUserInputLastName();

        std::string newLastName;
        std::cout << "Now please enter the new lastname of the person you chose " <<std::endl;
        std::cin >> newLastName;
        ExceptionHandling::checkUpperCase(newLastName);
        ExceptionHandling::checkEmptyString(newLastName);

        auto lambda = [newLastName](Person &p){p.setLastName(newLastName);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeBirthDate() {
        getUserInputFirstName();
        getUserInputLastName();

        std::cout << "Now please enter the birth of the person in following format [dd.mm.yyyy]" << std::endl;
        std::string newBirthDate = getDate();

        auto lambda = [newBirthDate](Person &p){p.setBirth(newBirthDate);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeDeathDate() {
        getUserInputFirstName();
        getUserInputLastName();

        std::cout << "Now please enter the death of the person in following format [dd.mm.yyyy]" << std::endl;
        std::string newBirthDate = getDate();

        auto lambda = [newBirthDate](Person &p){p.setDeath(newBirthDate);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeSex() {
        getUserInputFirstName();
        getUserInputLastName();
        char newSex;

        std::cout << "Now please enter the new sex of the person you chose. [m] for male, [f] for female, or [o] for other." << std::endl;
        std::cin >> newSex;
        ExceptionHandling::checkSexInput();

        auto lambda = [newSex](Person &p){p.setSex(newSex);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void mainScreenCases (){
        switch (_state) {
            case 1: {
              if(_rootNode == nullptr) {
                    savePersonInfo();
                    createFirstPerson();
                    feedback();
                }
                else {
                  savePersonInfo();
                  createGeneralPerson();
                }
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
                editAttributes();
                break;
            }
        }
    }
};

#endif//FAMILYTREE_MENU_HPP
