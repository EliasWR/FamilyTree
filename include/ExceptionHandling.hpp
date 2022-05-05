#ifndef FAMILYTREE_EXCEPTIONHANDLING_HPP
#define FAMILYTREE_EXCEPTIONHANDLING_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <array>
#include <vector>
#include <cctype>

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

    static int checkCipherAndInput (int length){
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

    static std::string checkUpperCase(std::string s) {
        if (!isupper(s[0])) {
            s[0]=toupper(s[0]);
        }
        return s;
    }

    static char checkSexInput() {
        char m = 'm';
        char f = 'f';
        char o = 'o';
        char c;
        std::cin >> c;

        while ((c != m) && (c != f) && (c != o)) {
            std::cout << "You did not type in any of the given options for sex ['m', 'f' or 'o']";
            std::cin >> c;
        }
        return c;
    }

    static bool checkDateLength (std::string dateString){
      int desiredLength = 10;
      int stringLength = dateString.length ();
      if (stringLength == desiredLength){
        return true;
      }
      return false;
    }

    static bool checkUserInput(char input) {
        char a = 'a';
        char e = 'e';

        while ((input != a) && (input != e)) {
            std::cout << "That was not one of your given options, please try again" << std::endl;
            std::cin>> input;
        }
        return true;
    }
};








#endif //FAMILYTREE_EXCEPTIONHANDLING_HPP
