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
// Autoshop.cpp

#include <iostream>
#include <vector>
#include <list>
#include "Autoshop.h"

using namespace std;

namespace sdds
{
  Autoshop::~Autoshop() {
    for (Vehicle* temp : m_vehicles)
      delete temp;
  }

  Autoshop& Autoshop::operator+=(Vehicle *theVechicle) {
    m_vehicles.push_back(theVechicle);
    return *this;
  }

  void Autoshop::display(std::ostream &out) const {
    out << "--------------------------------" << endl;
    out << "| Cars in the autoshop!        |" << endl;
    out << "--------------------------------" << endl;

    for (auto itr = m_vehicles.begin(); itr != m_vehicles.end(); ++itr) {
      (*itr)->display(out);
      out << endl;
    }
    out << "--------------------------------" << endl;
  }
}