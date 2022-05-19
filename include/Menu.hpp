#ifndef FAMILYTREE_MENU_HPP
#define FAMILYTREE_MENU_HPP

#include "Date.hpp"
#include "ExceptionHandling.hpp"
#include "JsonFile.hpp"
#include "Node.hpp"
#include <array>
#include <iostream>
#include <limits>

// Indexing of persons
// singly linked list holding persons
template<class T>
class Menu {
private:
  int _state = 0;
  std::shared_ptr<Node<Person>> _rootNode = nullptr;
  const std::string _fileName = "FamilyTree.json";

public:
  Menu() {
  }

  void setState(int state) {
    _state = state;
  }

  [[nodiscard]] int getState() const {
    return _state;
  }

  void greeting() {
    getSavedNodes();
    Date date;
    std::cout << "                  "
              << "Welcome to 'FamilyTree'!" << std::endl;
    std::cout << "                  "
              << "Todays date is: " << date.getCurrentDate() << std::endl;
    std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
    std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;

    if (_rootNode == nullptr) {
      std::cout << "To start the program you need to add your first person, whom is the root of your tree and the start of your heritage!" << std::endl;
      Person person = createPerson();
      createFirstPerson(person);
    } else {
      std::cout << std::endl;
    }
  }

  void getSavedNodes() {
    nlohmann::json j;
    auto emptyNode = std::make_shared<Node<Person>>();
    JsonFile json(emptyNode, _fileName);

    if (!json.isEmpty()) {
      json.closeFile();
      j = json.readFile(j);

      auto node = json.nodeFromJson(j, emptyNode);
      _rootNode = node;
      std::cout << "You can continue building your tree where you left off: " << std::endl;
      printTree(node);
    } else {
      json.closeFile();
    }
  }

  void saveNodes(std::shared_ptr<Node<Person>> rootNode) {
    nlohmann::json j;
    std::string fileName = "FamilyTree.json";
    JsonFile json(rootNode, fileName);

    json.closeFile();
    json.openFile();

    j = json.nodesToJson();
    json.jsonToFile(j);

    json.closeFile();
  }

  void createFirstPerson(Person &p) {
    _rootNode = std::make_shared<Node<Person>>(p);
  }

  void feedback() {
    std::cout << "Operation was successfully executed" << std::endl
              << std::endl;
  }

  void mainScreen() {
    std::cout << "You have the following options." << std::endl;
    std::cout << "[1] Add new person to tree." << std::endl;
    std::cout << "[2] Empty a person's attributes." << std::endl;
    std::cout << "[3] Edit existing persons attributes." << std::endl;
    std::cout << "[4] Show existing persons attributes." << std::endl;
    std::cout << "[5] Show all existing persons in your family tree." << std::endl;
    std::cout << "[9] Exit program." << std::endl;
    std::cout << "Enter your number followed by enter:" << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5, 6, 9};
    int input = ExceptionHandling::checkStateInput(v);
    _state = input;
    mainScreenCases();
  }

  void editAttributes() {
    std::cout << "You can edit the following information of your family tree" << std::endl;
    std::cout << "[1] Edit existing persons firstname" << std::endl;
    std::cout << "[2] Edit existing persons lastname" << std::endl;
    std::cout << "[3] Edit existing persons birthday" << std::endl;
    std::cout << "[4] Edit exising persons day of death" << std::endl;
    std::cout << "[5] Edit existing persons sex" << std::endl;
    std::cout << "[6] Go back to main menu." << std::endl;
    std::cout << "[9] Exit program." << std::endl;
    std::cout << "Enter your number followed by enter:" << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5, 6, 9};
    int input = ExceptionHandling::checkStateInput(v);
    _state = input;
    editAttributeCases();
  }

  //functions for main screen options
  Person createPerson() {
    // Firstname
    std::string firstName, lastName, sex, birth, death;
    std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
    std::cout << "Type the attributes followed by enter." << std::endl
              << std::endl;
    std::cout << "Please type the persons first name: " << std::endl;
    std::cout << "If the person has multiple firstnames, use '-' between them" << std::endl;
    std::cin >> firstName;
    while (ExceptionHandling::stringEmpty(firstName)) {
      std::cin >> firstName;
    }
    ExceptionHandling::toUpper(firstName);

    // Lastname
    std::cout << "Please type the persons last name: " << std::endl;
    std::cout << "If the person has multiple lastnames, use '-' between them" << std::endl;
    std::cin >> lastName;
    while (ExceptionHandling::stringEmpty(lastName)) {
      std::cin >> lastName;
    }
    ExceptionHandling::toUpper(lastName);

    // Sex
    std::cout << "Please enter the persons sex ['male', 'female' or 'other']" << std::endl;
    std::cin >> sex;
    while (ExceptionHandling::stringEmpty(sex)) {
      std::cin >> sex;
    }
    ExceptionHandling::toUpper(sex);

    // Birth
    std::cout << "Now please enter the date of birth in the following format[dd.mm.yyyy]" << std::endl;
    birth = getDate();

    // Death
    std::cout << "Now please enter the date of death in the following format[dd.mm.yyyy]" << std::endl;
    std::cout << "If the person you are adding, is alive, enter '0'" << std::endl;
    death = getDate();
    Person person(firstName, lastName, birth, death, sex);
    return person;
  }

  void createGeneralPerson(Person &p) {
    std::cout << "You need to enter the name of your persons parent" << std::endl;
    std::cout << "Please enter the firstname of the parent [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the parent [Lastname]" << std::endl;
    std::string b = getNameInput();
    auto lambda = [ p ](Node<Person> &node) {
      node.add(p);
    };
    _rootNode->traverseDepth(lambda, a, b);
    feedback();
  }

  void printPerson() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    auto lambda = [](Person p) {
      p.printPersonInfo();
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
  }

  void printTree(std::shared_ptr<Node<Person>> &node) {
    int indent = 3;
    node->traverseDepth([ indent ](Node<Person> &f, int depth) {
      for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < indent; ++j) {
          std::cout << " ";
        }
      }
      std::cout << f.getPerson().getFirstName() << " " << f.getPerson().getLastName() << std::endl;
    });
    feedback();
  }

  void emptyPerson() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string firstName = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string lastName = getNameInput();

    auto lambda = [](Person &p) {
      p.setFirstName("Empty");
      p.setLastName("Empty");
      p.setBirth("00.00.0000");
      p.setDeath("00.00.0000");
      p.setSex("other");
    };
    _rootNode->traverseDepthSearch(_rootNode, firstName, lastName, lambda);
  }

  void exitProgram() {
    std::string input;

    std::cout << "Are you sure you want to exit the program?" << std::endl;
    std::cout << "To return to the main menu, type 'back'" << std::endl;
    std::cout << "To exit program, type 'exit'" << std::endl;
    std::cin >> input;
    ExceptionHandling::checkExitMenuInput(input);

    if (input == "back") {
      _state = 1;
    } else if (input == "exit") {
      std::cout << "Thank you for using our Family Tree program! Good bye!" << std::endl;
      _state = 9;
      saveNodes(_rootNode);
    } else {
      std::cout << "Your input could not be interpreted, going back to program." << std::endl;
      _state = 1;
    }
  }

  // Functions for getting user input
  std::string getNameInput() {
    std::string name;
    std::cin >> name;
    while (ExceptionHandling::stringEmpty(name)) {
      std::cin >> name;
    }
    ExceptionHandling::toUpper(name);
    return name;
  }

  std::string getDate() {
    std::string date;
    while (!ExceptionHandling::checkDateLength(date)) {
      std::cin >> date;
    }
    return date;
  }

  void changeFirstName() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    std::cout << "Now please enter the new firstname of the person you chose " << std::endl;
    std::string newFirstName = getNameInput();

    auto lambda = [ newFirstName ](Person &p) {
      p.setFirstName(newFirstName);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new firstname of your person is now ";
    std::cout << newFirstName << std::endl;
  }

  void changeLastName() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    std::cout << "Now please enter the new lastname of the person you chose " << std::endl;
    std::string newLastName = getNameInput ();

    auto lambda = [ newLastName ](Person &p) {
      p.setLastName(newLastName);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new lastname of your person is now ";
    std::cout << newLastName << std::endl;
  }

  void changeBirthDate() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();

    std::cout << "Now please enter the new birthdate of the person in following format [dd.mm.yyyy]" << std::endl;
    std::string newBirthDate = getDate();

    auto lambda = [ newBirthDate ](Person &p) {
      p.setBirth(newBirthDate);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new birthdate of the person is now ";
    std::cout << newBirthDate << std::endl;
  }

  void changeDeathDate() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();

    std::cout << "Now please enter the new date of death of the person in following format [dd.mm.yyyy]" << std::endl;
    std::string newDeathDate = getDate();

    auto lambda = [ newDeathDate ](Person &p) {
      p.setDeath(newDeathDate);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new date of death of the person is now ";
    std::cout << newDeathDate << std::endl;
  }

  void changeSex() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    std::string newSex;

    std::cout << "Now please enter the new sex of the person you chose ['male', 'female' or 'other']." << std::endl;
    std::cin >> newSex;
    ExceptionHandling::checkSexInput(newSex);

    auto lambda = [ newSex ](Person &p) {
      p.setSex(newSex);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new sex of the person you chose is now ";
    std::cout << newSex << std::endl;
  }

  void mainScreenCases() {
    switch (_state) {
      case 1: {
        Person p = createPerson();
        createGeneralPerson(p);
        break;
      }

      case 2: {
        emptyPerson();
        break;
      }
      case 3: {
        editAttributes();
        break;
      }
      case 4: {
        printPerson();
        break;
      }
      case 5: {
        printTree(_rootNode);
        break;
      }
      case 9: {
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

  void editAttributeCases() {
    switch (_state) {
      case 1: {
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
        break;
      }
      case 9: {
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
