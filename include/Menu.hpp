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
    std::array<int,3> _birth{};
    std::array<int,3> _death{};
    bool _isAlive;
    int _year = 0;
    int _month = 0;
    int _day = 0;
    int _yearLen = 4;
    int _dayAndMonthLen = 2;
    std::shared_ptr<Node<Person>> _rootNode;
    bool _firstPersonCreated = false;

public:
  Menu (){}

  void setState(int state) {
      _state = state;
  }

    [[nodiscard]] int getState() const {
        return _state;
    }

    void greeting () {
        std::cout << "                  " << "Welcome to 'FamilyTree'!"<< std::endl;
        std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
        std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;
    }

    void mainScreen (){
        std::cout << "You have the following options." << std::endl;
        std::cout << "[1] Add new person to tree." << std::endl;
        std::cout << "[2] Remove person from tree." << std::endl;
        std::cout << "[3] Edit existing persons attributes." << std::endl;
        std::cout << "[4] Show existing persons attributes." << std::endl;
        std::cout << "[5] Exit program" << std::endl;
        std::vector<int> v {1,2,3,4,5};
        int input = ExceptionHandling::checkInput(v);
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
        std::cout << "Enter your number followed by enter:";
        std::vector<int> v {1,2,3,4,5,6};
        int input = ExceptionHandling::checkInput (v);
        _state = input;
        return input;
    }

    //functions for main screen options
    void savePersonInfo (){

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
        std::cout << "Please enter the persons sex ['m' for male, 'f' for female, 'o' for other]" << std::endl;
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


    int exitProgram () {
        char b = 'b';
        char e = 'e';
        char input;

        std::cout << "Are you sure you want to exit the program";
        std::cin>>input;
        ExceptionHandling::checkUserInput(input);

        std::cout << "To return to the main menu, type 'b'" << std::endl;
        std::cout << "To exit program, type 'e'" << std::endl;
        std::cin>>input;
        ExceptionHandling::checkUserInput(input);

        if (input == b) {
            mainScreen();
        }
        std::cout<<"Thank you for using our Family Tree program! Good bye!";
        return 0;
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

    std::string getCurrentDate () {
      std::string currentDate;
      ExceptionHandling e;
      bool dateStr = false;
      while (!dateStr) {
        std::cin >> currentDate;
        dateStr = e.checkDateLength(currentDate);
      }
      return currentDate;
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
        int newYear;
        int newMonth;
        int newDay;

        std::array<int,3> newBirthDate{};
        std::cout << "Now please enter the new year of birth of the person you chose [yyyy]" << std::endl;
        std::cin >> newYear;
        newYear = ExceptionHandling::checkCipherAndInput(_yearLen);
        std::cout << "Now please enter the new month of birth of the person you chose [mm]" <<std::endl;
        std::cin >> newMonth;
        newMonth = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);
        std::cout << "Now please enter the new day of birth of the person you chose [dd]" <<std::endl;
        std::cin >> newDay;
        newDay = ExceptionHandling::checkCipherAndInput(_dayAndMonthLen);

        auto lambda = [newYear, newMonth, newDay](Person &p){p.setBirth(newYear, newMonth, newDay);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
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
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void changeSex() {
        getUserInputFirstName();
        getUserInputLastName();
        char newSex;

        std::cout << "Now please enter the new sex of the person you chose ['m' for male, 'f' for female, or 'o' for other]" << std::endl;
        std::cin >> newSex;
        ExceptionHandling::checkSexInput();

        auto lambda = [newSex](Person &p){p.setSex(newSex);};
        _rootNode->traverseDepthSearch(_rootNode, getUserInputFirstName(), getUserInputLastName(), lambda);
    }

    void mainScreenCases (){
        switch (_state) {
            case 1: {
                if(!_firstPersonCreated) {
                    savePersonInfo();
                    createFirstPerson();
                    _firstPersonCreated = true;
                }
                savePersonInfo();
                createGeneralPerson();
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
