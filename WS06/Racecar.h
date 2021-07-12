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
// Racecar.h

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds
{
  class Racecar : public Car
  {
    double m_booster {};

  public:
    Racecar(std::istream &in);
    void display(std::ostream &out) const;
    double topSpeed() const;
  };
}
#endif // !SDDS_RACECAR_H
