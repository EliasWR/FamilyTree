#ifndef FAMILYTREE_DATE_HPP
#define FAMILYTREE_DATE_HPP

#include "Menu.hpp"
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
  Date()
      : _day(0), _month(0), _year(0), _presDay(0), _presMonth(0), _presYear(0){};
  Date(int day, int month, int year)
      : _day(day), _month(month), _year(year){};

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

  void setDate(std::string dateString) {
    int day = 0;
    int month = 0;
    int year = 0;
    std::vector<int> v = {day, month, year};

    std::string delimiter = ".";
    int counter = 0;
    size_t pos = 0;
    std::string token;

    while ((pos = dateString.find(delimiter)) != std::string::npos) {
      token = dateString.substr(0, pos);
      v[counter] = std::stoi(token);
      dateString.erase(0, pos + delimiter.length());
      counter++;
    }
    v[counter] = std::stoi(dateString);
    _day = v[0];
    _month = v[1];
    _year = v[2];
  }

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
    std::cout << ", is " << year << " years and " << month << " months old";
  }
};

#endif//FAMILYTREE_DATE_HPP
