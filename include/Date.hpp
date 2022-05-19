#ifndef FAMILYTREE_DATE_HPP
#define FAMILYTREE_DATE_HPP

#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
private:
  int _day, _month, _year;
  int _presDay, _presMonth, _presYear;

public:
  /// @what Default constructor for Date class setting private variables initial value to 0
  /// @param N/A
  /// @returns N/A
  /// @usage Menu::greeting, Person::printPersonInfo
  /// @example Date d;
  Date()
      : _day(0), _month(0), _year(0), _presDay(0), _presMonth(0), _presYear(0){};
  /// @what Constructor for Date class initializing "_day", "_month", "_year"
  /// @param "int day", "int month", "int year" used for initializing private variables
  /// @returns N/A
  /// @usage Menu::greeting, Person::printPersonInfo
  /// @example Date d(01.01.2001);
  Date(int day, int month, int year)
      : _day(day), _month(month), _year(year){};

  /// @what Function for converting day, month and year integers to one date(string)
  /// @param N/A
  /// @returns "std::string date" containg the string of the date
  /// @usage N/A
  /// @example
  /// d.setDate(birthday);\n
  /// d.getDate();
  std::string const getDate() {
    std::string day = std::to_string(_day);
    std::string month = std::to_string(_month);
    std::string year = std::to_string(_year);

    std::string date;
    if (day.length() == 1) {
      date.append("0");
    }
    date.append(day);
    date.append(".");
    if (month.length() == 1) {
      date.append("0");
    }
    date.append(month);
    date.append(".");
    date.append(year);

    return date;
  }

  /// @what Function for splitting a date string to integers containing day, month and year
  /// @param N/A
  /// @returns N/A
  /// @usage Date::calculateAge
  /// @example d.setDate(birthday);
  void setDate(std::string dateString) {
    std::vector<int> v = {0, 0, 0};

    std::string delimiter = ".";
    int counter = 0;
    size_t pos = 0;
    std::string token;

    while ((pos = dateString.find(delimiter)) != std::string::npos) {
      token = dateString.substr(0, pos);
      v[ counter ] = std::stoi(token);
      dateString.erase(0, pos + delimiter.length());
      counter++;
    }
    v[ counter ] = std::stoi(dateString);
    _day = v[ 0 ];
    _month = v[ 1 ];
    _year = v[ 2 ];
  }

  /// @what Function getting current day using the time library
  /// @param N/A
  /// @returns std::string containing the current date in propper format
  /// @usage Menu::greeting, Person::printPersonInfo
  /// @example std::string date = d.getCurrentDate();
  std::string getCurrentDate() {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    _presDay = currentDay;
    _presMonth = currentMonth;
    _presYear = currentYear;

    std::string currentDate = std::to_string(currentDay) + "." + std::to_string(currentMonth) + "." + std::to_string(currentYear);
    return currentDate;
  }

  /// @what Function for calculating the age of a person or time from a date to another date
  /// @param "std::string birthDate", "std::string currentDate" as parameters for calculating time between them
  /// @returns N/A
  /// @usage Person::printPersonInfo
  /// @example
  /// Date d;\n
  /// d.calculateAge(_birth, d.getCurrentDate());
  void calculateAge(std::string birthDate, std::string currentDate) {
    setDate(birthDate);

    int day, month, year;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    year = _presYear - _year;
    if (_presMonth < _month) {
      year--;
      month = 12 - (_month - _presMonth);
    } else {
      month = _presMonth - _month;
    }
    if (_presDay < _day) {
      month--;
      day = daysInMonth[ _presMonth - 1 ] - (_day - _presDay);
    } else {
      day = _presDay - _day;
    }
    std::cout << "Age is " << year << " years and " << month << " months old.";
  }
};

#endif//FAMILYTREE_DATE_HPP
