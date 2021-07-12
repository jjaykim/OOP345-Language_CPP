//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 9, 2021
// Workshop:       Workshop6
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Car.cpp

#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;

namespace sdds
{
  Car::Car(istream& in) {
    auto removeSpace = [](string& src) {
      bool exit = false;

      while(!exit) {
        if (src[0] == ' ')
          src.erase(0, src.find_first_not_of(' '));
        else if (src[src.length() - 1] == ' ')
          src.erase(src.find_last_not_of(' ') + 1);
        else
          exit = true;
      }

      return src;
    };

    string str = "";

    // get maker
    getline(in, str, ',');
    m_maker = removeSpace(str);

    // get condition
    getline(in, str, ',');
    removeSpace(str);

    if (str.empty() || str == "n")
      m_condition = "new";
    else if (str == "b")
      m_condition = "broken";
    else if (str == "u")
      m_condition = "used";
    else
      throw "Invalid record!";

    // get speed
    getline(in, str, ',');
    try {
      m_topSpeed = stod(removeSpace(str));
    }
    catch (...) {
      throw "Invalid record!";
    }
  }

  std::string Car::condition() const {
    return m_condition;
  }

  double Car::topSpeed() const {
    return m_topSpeed;
  }

  void Car::display(std::ostream &out) const {
    out << "| " << setw(10)  << m_maker;
    out << " | " << left << setw(6) << condition();
    out << " | " << right << setw(6) << setprecision(2) << fixed << topSpeed() << " |";
  }
}