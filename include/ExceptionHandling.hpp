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

  ExceptionHandling() = default;

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

  static bool checkEmptyString(const std::string &s) {
    while (s.empty()) {
      std::cout << "You have not typed anything, please try again";
    }
    return true;
  }

  static void checkUpperCase(std::string &s) {
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
