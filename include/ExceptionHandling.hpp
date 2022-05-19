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

  /// @what Function for taking user input until user choses a valid option
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
  /// @returns N/A
  /// @Usage Menu::mainScreen, Main::editAttributes
  /// @example int input = ExceptionHandling::checkStateInput(v);
  static bool stringEmpty(const std::string &s) {
    bool isEmpty = s.empty();
    if (isEmpty) {
      std::cout << "You have not typed anything, please try again";
    }
    return isEmpty;
  }

  static void toUpper(std::string &s) {
    s[ 0 ] = std::toupper(s[ 0 ]);
  }

  static std::string checkSexInput(std::string s) {
    std::string m = "male";
    std::string f = "female";
    std::string o = "other";

    while ((s != m) && (s != f) && (s != o)) {
      std::cout << "You did not type in any of the given options for sex ['male', 'female' or 'other']. Please try again." << std::endl;
      std::cin >> s;
    }
    return s;
  }

  static bool checkDateLength(const std::string &dateString) {
    int desiredLength = 10;
    int stringLength = dateString.length();
    if ((stringLength == desiredLength) || (dateString == "0")) {
      return true;
    }
    std::cout << "You did not enter the date in the correct format [dd.mm.yyyy]. Please try again." << std::endl;
    return false;
  }

  static bool checkExitMenuInput(std::string input) {
    std::string b = "back";
    std::string e = "exit";

    while ((input != b) && (input != e)) {
      std::cout << "That was not one of your given options, please try again" << std::endl;
      std::cin >> input;
    }
    return true;
  }
};

#endif//FAMILYTREE_EXCEPTIONHANDLING_HPP
