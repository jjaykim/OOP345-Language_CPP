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
// Autoshop.h

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
  class Autoshop
  {
    std::vector<Vehicle*> m_vehicles;

  public:
    Autoshop& operator +=(Vehicle* theVechicle);
    void display(std::ostream& out) const;
    ~Autoshop();

    template <typename T>
    void select(T test, std::list<const Vehicle *>& vehicles) {
      for (auto temp : m_vehicles) {
        if (test(temp))
          vehicles.push_back(temp);
      }
    }
  };
}
#endif // !SDDS_AUTOSHOP_H
