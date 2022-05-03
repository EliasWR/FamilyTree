//
// Created by Elias Woie Refsdal on 03/05/2022.
//

#ifndef FAMILYTREE_DATE_HPP
#define FAMILYTREE_DATE_HPP

#include <iostream>
#include <sstream>

class Date {
private:
  int _day, _month, _year;

public:
  Date () : _day(0), _month(0), _year(0) {};
  Date (int day, int month, int year) : _day(day), _month(month), _year(year){};

  std::string getDate () {
    std::string day = std::to_string(_day);
    std::string month = std::to_string(_month);
    std::string year = std::to_string(_year);

    // TODO får inn punktum og 0
    std::string date;
    if (day.length() == 1){
      date.append("0");
    }
    date.append(day);
    date.append(".");
    if (month.length() == 1){
      date.append("0");
    }
    date.append(month);
    date.append(".");
    date.append(year);

    return date;
  }

  void stringToInt (std::string dateString){
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
};


#endif//FAMILYTREE_DATE_HPP
