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
// Racecar.cpp

#include <iostream>
#include <string>
#include "Racecar.h"

using namespace std;

namespace sdds
{
  Racecar::Racecar(std::istream& in) : Car(in) {
    string str;
    getline(in, str);

    m_booster = stod(str);
  }

  void Racecar::display(std::ostream &out) const {
    Car::display(out);
    out << "*";
  }

  double Racecar::topSpeed() const {
    return Car::topSpeed() * (1 + m_booster);
  }
}