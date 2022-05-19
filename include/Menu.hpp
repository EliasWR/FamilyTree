#ifndef FAMILYTREE_MENU_HPP
#define FAMILYTREE_MENU_HPP

#include "Date.hpp"
#include "ExceptionHandling.hpp"
#include "JsonFile.hpp"
#include "Node.hpp"
#include <vector>
#include <iostream>
#include <limits>

template<class T>
class Menu {
private:
  int _state = 0;
  std::shared_ptr<Node<Person>> _rootNode = nullptr;
  const std::string _fileName = "FamilyTree.json";

public:
  /// @what Default constructor for Menu
  /// @param N/A
  /// @returns N/A
  /// @usage Family_Tree::main
  /// @example Menu<Person> m;
  Menu() = default;

  /// Getter for private variable _state of Menu class
  void setState(int state) {
    _state = state;
  }

  /// Setter for private variable _state of Menu class
  [[nodiscard]] int getState() const {
    return _state;
  }

  /// @what Greeter for programs starting screen. \n
  /// Fetching saved data and creating first person if needed
  /// @param N/A
  /// @returns N/A
  /// @usage Family_Tree::main
  /// @example m.greeting();
  void greeting() {
    Date date;
    std::cout << "                  "
              << "Welcome to 'FamilyTree'!" << std::endl;
    std::cout << "                  "
              << "Today's date is: " << date.getCurrentDate() << std::endl;
    std::cout << "In this program you can make and modify a family tree of your own" << std::endl;
    std::cout << "To navigate this program you type the number of your desired command followed by enter." << std::endl;
    getSavedNodes();
    createFirstPerson();
  }

  /// @what Fetching saved information from file
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::greeting
  /// @example getSavedNodes();
  void getSavedNodes() {
    nlohmann::json j;
    auto emptyNode = std::make_shared<Node<Person>>();
    JsonFile json(emptyNode, _fileName);

    if (!json.isEmpty()) {
      json.closeFile();
      j = json.readFile(j);

      _rootNode = json.nodeFromJson(j, emptyNode);
      std::cout << "You can continue building your tree where you left off: " << std::endl;
      printTree();
    } else {
      json.closeFile();
    }
  }

  /// @what Saving nodes to file from tree-structure
  /// @param "std::shared_ptr<Node<Person>> rootNode" Is needed to traverse each node
  /// @returns N/A
  /// @usage Menu::exitProgram
  /// @example saveNodes(_rootNode);
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

  /// @what Function for creating first person if none exists in tree
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::greeting
  /// @example createFirstPerson();
  void createFirstPerson() {
    if (_rootNode == nullptr) {
      std::cout << "To start the program you need to add your first person, whom is the root of your tree and the start of your heritage!" << std::endl;
      Person person = createPerson();
      _rootNode = std::make_shared<Node<Person>>(person);
    } else {
      std::cout << std::endl;
    }
  }

  /// @what Function for printing main screen options and getting \n
  /// desired user input. Input is used to set state and case.
  /// @param N/A
  /// @returns N/A
  /// @usage Family_Tree::main
  /// @example
  ///  Menu<Person> m; \n
  ///  while (m.getState() != 9) { \n
  ///    m.mainScreen();}
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

  /// @what Function for printing the options for editing attributes and \n
  ///       getting desired user input. Input is used to set state and case.
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example editAttributes();
  void editAttributes() {
    std::cout << "You can edit the following information of your family tree" << std::endl;
    std::cout << "[1] Edit existing persons firstname" << std::endl;
    std::cout << "[2] Edit existing persons lastname" << std::endl;
    std::cout << "[3] Edit existing persons birthday" << std::endl;
    std::cout << "[4] Edit exising persons day of death" << std::endl;
    std::cout << "[5] Edit existing persons gender" << std::endl;
    std::cout << "[6] Go back to main menu." << std::endl;
    std::cout << "[9] Exit program." << std::endl;
    std::cout << "Enter your number followed by enter:" << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5, 6, 9};
    int input = ExceptionHandling::checkStateInput(v);
    _state = input;
    editAttributeCases();
  }

  /// @what Function for creating person with user input.
  /// @param N/A
  /// @returns Person that can later be added to node
  /// @usage Menu::mainScreenCases, Menu::createFirstPerson
  /// @example Person person = createPerson();
  Person createPerson() {
    /// Firstname
    std::string firstName, lastName, gender, birth, death;
    std::cout << "Now you can add a new person with 5 attributes to your family tree." << std::endl;
    std::cout << "Type the attributes followed by enter." << std::endl << std::endl;
    std::cout << "Please type the persons first name: " << std::endl;
    std::cout << "If the person has multiple firstnames, use '-' between them" << std::endl;
    std::cin >> firstName;
    while (ExceptionHandling::stringEmpty(firstName)) {
      std::cin >> firstName;
    }
    ExceptionHandling::toUpper(firstName);

    /// Lastname
    std::cout << "Please type the persons last name: " << std::endl;
    std::cout << "If the person has multiple lastnames, use '-' between them" << std::endl;
    std::cin >> lastName;
    while (ExceptionHandling::stringEmpty(lastName)) {
      std::cin >> lastName;
    }
    ExceptionHandling::toUpper(lastName);

    /// Gender
    std::cout << "Please enter the persons gender ['male', 'female' or 'other']" << std::endl;
    std::cin >> gender;
    ExceptionHandling::checkGenderInput(gender);

    /// Birth
    std::cout << "Now please enter the date of birth in the following format[dd.mm.yyyy]" << std::endl;
    birth = getDate();

    /// Death
    std::cout << "Now please enter the date of death in the following format[dd.mm.yyyy]" << std::endl;
    std::cout << "If the person you are adding, is alive, enter '0'" << std::endl;
    death = getDate();
    Person person(firstName, lastName, birth, death, gender);
    return person;
  }

  /// @what Function for creating general person from person passed in parameter
  /// @param "Person &p" passed by reference to add to a node
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example
  ///     Person p = createPerson(); \n
  ///     createGeneralPerson(p);
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
    std::cout << "Operation was successfully executed" << std::endl
              << std::endl;
  }

  /// @what Function for printing persons information and attributes
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example printPerson();
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

  /// @what Function for printing tree and all persons from rootNode
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example printTree();
  void printTree() {
    int indent = 3;
    _rootNode->traverseDepth([ indent ](Node<Person> &f, int depth) {
      for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < indent; ++j) {
          std::cout << " ";
        }
      }
      std::cout << f.getPerson().getFirstName() << " " << f.getPerson().getLastName() << std::endl;
    });
    std::cout << "Operation was successfully executed" << std::endl
              << std::endl;
  }

  /// @what Function for emptying person in node
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example emptyPerson();
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
      p.setGender("other");
    };
    _rootNode->traverseDepthSearch(_rootNode, firstName, lastName, lambda);
  }

  /// @what Function for exiting program and while loop in main.\n
  /// Checks the input until a desired answer is received
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases, Menu::editAttributes
  /// @example exitProgram();
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

  /// @what Function for getting user input as string
  /// @param N/A
  /// @returns str::string
  /// @usage Menu::mainScreenCases
  /// @example getNameInput();
  std::string getNameInput() {
    std::string name;
    std::cin >> name;
    while (ExceptionHandling::stringEmpty(name)) {
      std::cin >> name;
    }
    ExceptionHandling::toUpper(name);
    return name;
  }

  /// @what Function for getting date input with desired length.
  /// @param N/A
  /// @returns "std::string date" is being returned in the desired length and format
  /// @usage Menu::createPerson
  /// @example getDate();
  std::string getDate() {
    std::string date;
    std::cin >> date;
    while (!ExceptionHandling::checkDateLength(date)) {
      std::cin >> date;
    }
    return date;
  }
  /// @what Function for changing existing persons first name using traverseDepthSearch();
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::changeAttributeCases
  /// @example changeFirstName();
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
  /// @what Function for changing existing persons last name using traverseDepthSearch();
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::changeAttributeCases
  /// @example changeLastName();
  void changeLastName() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    std::cout << "Now please enter the new lastname of the person you chose " << std::endl;
    std::string newLastName = getNameInput();

    auto lambda = [ newLastName ](Person &p) {
      p.setLastName(newLastName);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new lastname of your person is now ";
    std::cout << newLastName << std::endl;
  }

  /// @what Function for changing existing persons birth using traverseDepthSearch();
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::changeAttributeCases
  /// @example changeBirthDate();
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
  /// @what Function for changing existing persons death using traverseDepthSearch();
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::changeAttributeCases
  /// @example changeDeathDate();
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
  /// @what Function for changing existing persons gender using traverseDepthSearch();
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::changeAttributeCases
  /// @example m.changeGender();
  void changeGender() {
    std::cout << "Please enter the firstname of the person [Firstname]" << std::endl;
    std::string a = getNameInput();
    std::cout << "Please enter the lastname of the person [Lastname]" << std::endl;
    std::string b = getNameInput();
    std::string newGender;

    std::cout << "Now please enter the new gender of the person you chose ['male', 'female' or 'other']." << std::endl;
    std::cin >> newGender;
    ExceptionHandling::checkGenderInput(newGender);

    auto lambda = [ newGender ](Person &p) {
      p.setGender(newGender);
    };
    _rootNode->traverseDepthSearch(_rootNode, a, b, lambda);
    std::cout << "The new gender of the person you chose is now ";
    std::cout << newGender << std::endl;
  }

  /// @what Function for switch cases in main menu. Keeps track of states.
  /// @param N/A
  /// @returns N/A
  /// @usage Family_tree.cpp::main
  /// @example mainScreenCases();
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
        printTree();
        break;
      }
      case 9: {
        exitProgram();
        break;
      }
      default: {
        std::cout << "That was not one of your menu options, please try again";
        break;
      }
    }
  }

  /// @what Function for switch cases in edit attributes menu. Keeps track of states.
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::mainScreenCases
  /// @example editAttributeCases();
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
        changeGender();
        break;
      }
      case 6: {
        std::cout << "Returning to main menu." << std::endl;
        break;
      }
      case 9: {
        exitProgram();
        break;
      }
      default: {
        std::cout << "That was not one of the menu options, please try again";
        break;
      }
    }
  }
};

#endif//FAMILYTREE_MENU_HPP
