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
    std::string _sex;
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
        std::cout << "To start the program you need to add your first person, whom is the root of your tree and the start of your heritage!" << std::endl << std::endl;
        createFirstPerson();
        savePersonInfo();
    }
    void createFirstPerson() {
        _rootNode = std::make_shared<Node<Person>>(Person(_firstName, _lastName, _birth, _death, _sex));
    }

    void feedback (){
      std::cout << "Operation was successfully executed"<< std::endl << std::endl;
    }

    void mainScreen () {
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Show existing persons attributes." << std::endl;
        std::cout << "[5] Show all existing persons in your family tree!." << std::endl;
        std::cout << "[6] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5,6};
        int input = ExceptionHandling::checkIntAndList(v);
        _state = input;
        mainScreenCases();
    }

    void editAttributes () {
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
        editAttributeCases();
    }

    //functions for main screen options
    void savePersonInfo (){

        // Firstname
        std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
        std::cout << "Type the attributes followed by enter." << std::endl << std::endl;
        std::cout << "Please type the persons first name: "<< std::endl;
        std::cout << "If the person has multiple firstnames, use '-' between them" << std::endl;
        std::cin >> _firstName;
        ExceptionHandling::checkUpperCase(_firstName);
        ExceptionHandling::checkEmptyString(_firstName);

        // Lastname
        std::cout << "Please type the persons last name: "<< std::endl;
        std::cout << "If the person has multiple lastnames, use '-' between them" << std::endl;
        std::cin >> _lastName;
        ExceptionHandling::checkEmptyString(_lastName);
        ExceptionHandling::checkUpperCase(_lastName);

        // Sex
        std::cout << "Please enter the persons sex ['male', 'female' or 'other']" << std::endl;
        std::cin >> _sex;
        ExceptionHandling::checkEmptyString(_sex);
        ExceptionHandling::checkSexInput(_sex);

        // Birth
        std::cout << "Now please enter the date of birth in the following format[dd.mm.yyyy]" << std::endl;
        _birth = getDate();

        // Death
        std::cout << "Now please enter the date of death in the following format[dd.mm.yyyy]" << std::endl;
        std::cout << "If the person you are adding, is alive, enter '0'" << std::endl;
        _death = getDate();
    }

  void createGeneralPerson() {
      std::cout << "You need to enter the name of your persons parent" <<std::endl;
      std::string a = getUserInputFirstName();
      std::string b = getUserInputLastName();
      Person p(_firstName, _lastName, _birth, _death, _sex);
      auto lambda1 = [p](Node<Person> &node) {node.add(p);};
      _rootNode->traverseDepth (lambda1, a, b);
      feedback();
  }

    void getPersonInfo () {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();
        auto lambda = [](Person p) { p.printPersonInfo(); };
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        feedback();
    }

    void printTree (std::shared_ptr<Node<Person>>& node) {
        int indent = 3;
        node->traverseDepth([ indent ](Node<Person> &f, int depth) {
            for (int i = 0; i < depth; ++i) {
                for (int j = 0; j < indent; ++j) {
                    std::cout << " ";
                }
            }
            std::cout << f.getPerson()->getFirstName() << " " << f.getPerson()->getLastName() << std::endl;
        });
        feedback();
    }

    void exitProgram () {
        std::string input;

        std::cout << "Are you sure you want to exit the program?"<< std::endl;
        std::cout << "To return to the main menu, type 'back'" << std::endl;
        std::cout << "To exit program, type 'exit'" << std::endl;
        std::cin>>input;
        ExceptionHandling::checkUserInput(input);

        if (input == "back") {
            mainScreen();
        }
        else if (input == "exit"){
          std::cout << "Thank you for using our Family Tree program! Good bye!" << std::endl;
          _exitMenu = true;
        }
        else {
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
      bool dateStr = false;
      while (!dateStr) {
        std::cin >> date;
        dateStr = ExceptionHandling::checkDateLength(date);
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
        std::cout << "The new firstname of your person is now ";
        std:: cout << newFirstName << std::endl;
        feedback();
        }

    void changeLastName() {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();

        std::string newLastName;
        std::cout << "Now please enter the new lastname of the person you chose " <<std::endl;
        std::cin >> newLastName;
        ExceptionHandling::checkUpperCase(newLastName);
        ExceptionHandling::checkEmptyString(newLastName);

        auto lambda = [newLastName](Person &p){p.setLastName(newLastName);};
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        std::cout << "The new lastname of your person is now ";
        std::cout << newLastName << std::endl;
        feedback();
    }

    void changeBirthDate() {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();

        std::cout << "Now please enter the new birthdate of the person in following format [dd.mm.yyyy]" << std::endl;
        std::string newBirthDate = getDate();

        auto lambda = [newBirthDate](Person &p){p.setBirth(newBirthDate);};
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        std::cout << "The new birthdate of the person is now ";
        std::cout << newBirthDate << std::endl;
        feedback();

    }

    void changeDeathDate() {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();

        std::cout << "Now please enter the new date of death of the person in following format [dd.mm.yyyy]" << std::endl;
        std::string newDeathDate = getDate();

        auto lambda = [newDeathDate](Person &p){p.setDeath(newDeathDate);};
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        std::cout << "The new date of death of the person is now ";
        std::cout << newDeathDate << std::endl;
        feedback();
    }

    void changeSex() {
        std::string a = getUserInputFirstName();
        std::string b = getUserInputLastName();
        std::string newSex;

        std::cout << "Now please enter the new sex of the person you chose ['male', 'female' or 'other']." << std::endl;
        std::cin >> newSex;
        ExceptionHandling::checkSexInput(newSex);

        auto lambda = [newSex](Person &p){p.setSex(newSex);};
        _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
        std::cout << "The new sex of the person you chose is now ";
        std::cout << newSex << std::endl;
        feedback();
    }

    void mainScreenCases (){
        switch (_state) {
            case 1: {
                savePersonInfo();
                createGeneralPerson();
                break;
            }

            case 2: {
                break;
            }
            case 3: {
                editAttributes();
                break;
            }
            case 4: {
                getPersonInfo();
                break;
            }
            case 5: {
                printTree(_rootNode);
                break;
            }
            case 6: {
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

    void editAttributeCases () {
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
