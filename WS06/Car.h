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
// Car.h

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
  class Car : public Vehicle
  {
    std::string m_maker     {""};
    std::string m_condition {""};
    double m_topSpeed       {0.0};

  public:
    Car() {}
    Car(std::istream& in);
    std::string condition() const;
    double topSpeed() const;
    void display(std::ostream& out) const;
  };
}

#endif // !SDDS_CAR_H
