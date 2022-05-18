#ifndef FAMILYTREE_EXCEPTIONHANDLING_HPP
#define FAMILYTREE_EXCEPTIONHANDLING_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <array>
#include <vector>
#include <cctype>
#include <string>

struct ExceptionHandling {

    ExceptionHandling(){}

    static int checkInput () {
        int input;
        std::cin >> input;
        bool inList = false;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Not a valid value. Enter a menu option: ";
            std::cin >> input;
        }
        std::cout << "You selected " << input << std::endl;
        return input;
    }

    static int checkCipherAndInput(int length){
        int input;
        std::cin >> input;
        bool rightSize = checkCipherCount(input,length);
        while ((std::cin.fail()) || (!rightSize)){
            rightSize = checkCipherCount(input,length);
            if (!rightSize){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Not a valid value. Try again: ";
                std::cin >> input;
            }
        }
        return input;
    }
// TODO Rename and refactor
    static int checkIntAndList(const std::vector<int>& list){
        int input;
        std::cin >> input;
        bool inList = false;
        while (std::cin.fail() || !inList){
            for (int i : list){
                if (i == input){
                    inList = true;
                    break;
                }
            }
            if (!inList){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Not a valid value. Enter a menu option: ";
                std::cin >> input;
            }
        }
        return input;
    }

    static bool checkCipherCount(int number, int cipher) {
        bool isCorrect = true;
        int count = 0;
        while(number!=0) {
            number /= 10;
            count ++;
        }
        if (count > cipher) {
            isCorrect = false;
        }
        return isCorrect;
    }

    static bool checkEmptyString(std::string s) {
        while (s.empty()) {
            std::cout<<"You have not typed anything, please try again";
        }
        return true;
    }

    static void checkUpperCase(std::string &s) {
        s[0]=std::toupper(s[0]);
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

    static bool checkDateLength (std::string dateString){
      int desiredLength = 10;
      int stringLength = dateString.length ();
      if ((stringLength == desiredLength) || (dateString == "0")){
        return true;
      }
      std::cout << "You did not enter the date in the correct format [dd.mm.yyyy]. Please try again." << std::endl;
      return false;
    }

    static bool checkUserInput(std::string input) {
        std::string b = "back";
        std::string e = "exit";

        while ((input != b) && (input != e)) {
            std::cout << "That was not one of your given options, please try again" << std::endl;
            std::cin>> input;
        }
        return true;
    }

};








#endif //FAMILYTREE_EXCEPTIONHANDLING_HPP
