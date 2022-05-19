#ifndef FAMILYTREE_EXCEPTIONHANDLING_HPP
#define FAMILYTREE_EXCEPTIONHANDLING_HPP

#include <array>
#include <cctype>
#include <exception>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct ExceptionHandling {
  /// @what Default constructor for ExceptionHandling class
  /// @param N/A
  /// @returns N/A
  /// @Usage N/A
  /// @example ExceptionHandling e;
  ExceptionHandling() = default;

  /// @what Function for taking user input until user chooses a valid option
  /// @param "const std::vector<int> &list" for checking against user options
  /// @returns "int input" after checks and input is a valid value
  /// @Usage Menu::mainScreen, Main::editAttributes
  /// @example int input = ExceptionHandling::checkStateInput(v);
  static int checkStateInput(const std::vector<int> &list) {
    int input;
    std::cin >> input;
    bool inList = false;
    while (std::cin.fail() || !inList) {
      for (int i: list) {
        if (i == input) {
          inList = true;
          break;
        }
      }
      if (!inList) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You did not type a given option. Please try again." << std::endl;
        std::cin >> input;
      }
    }
    return input;
  }

  /// @what Function checking if string is empty
  /// @param "const std::string &s" passing string by reference to check if it is empty
  /// @returns "bool isEmpty" true if string is empty, false if not
  /// @Usage Menu::createPerson, Main::getNameInput
  /// @example while (ExceptionHandling::stringEmpty(lastName)) {std::cin lastName}
  static bool stringEmpty(const std::string &s) {
    bool isEmpty = s.empty();
    if (isEmpty) {
      std::cout << "You have not typed anything, please try again";
    }
    return isEmpty;
  }

  /// @what Function turning first letter of string to uppercase
  /// @param "std::string &s" passing string by reference and changing first letter to uppercase
  /// @returns N/A
  /// @Usage Menu::createPerson, Main::getNameInput
  /// @example ExceptionHandling::toUpper(firstName);
  static void toUpper(std::string &s) {
    s[ 0 ] = std::toupper(s[ 0 ]);
  }

  /// @what Function turning first letter of string to uppercase
  /// @param "std::string &s" passing string by reference and matching by options
  /// @returns N/A
  /// @Usage Menu::createPerson, Main::changeGender
  /// @example
  /// std::cin >> gender;\n
  /// ExceptionHandling::checkGenderInput(gender);
  static void checkGenderInput(std::string &gender) {
    std::string m = "male";
    std::string f = "female";
    std::string o = "other";

    while ((gender != m) && (gender != f) && (gender != o)) {
      std::cout << "You did not type in any of the given options for gender ['male', 'female' or 'other']. Please try again." << std::endl;
      std::cin >> gender;
    }
  }

  /// @what Function for checking date length
  /// @param "const std::string &dateString" passing string by \n
  ///         const reference and checking length of string
  /// @returns bool false if the format was wrong and returning true if date is the desired format
  /// @Usage Menu::getDate
  /// @example
  /// std::string date; \n
  /// while (!ExceptionHandling::checkDateLength(date)) {std::cin >> date;}
  static bool checkDateLength(const std::string &dateString) {
    int desiredLength = 10;
    int stringLength = dateString.length();
    if ((stringLength == desiredLength) || (dateString == "0")) {
      return true;
    }
    std::cout << "You did not enter the date in the correct format [dd.mm.yyyy]. Please try again." << std::endl;
    return false;
  }
  /// @what Function for checking desired exit menu input
  /// @param "std::string &input" passing string by reference in order to take input until valid
  /// @returns N/A
  /// @Usage Menu::exitProgram
  /// @example
  /// std::cin >> input; \n
  /// ExceptionHandling::checkExitMenuInput(input);
  static void checkExitMenuInput(std::string &input) {
    std::string b = "back";
    std::string e = "exit";

    while ((input != b) && (input != e)) {
      std::cout << "That was not one of your given options, please try again" << std::endl;
      std::cin >> input;
    }
  }
};

#endif//FAMILYTREE_EXCEPTIONHANDLING_HPP
