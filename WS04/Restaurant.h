//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           June 20, 2021
// Workshop:       Workshop4
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Restaurant.cpp

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
  class Restaurant
  {
    Reservation* m_listOfRes { nullptr }; // composition with Reservation class
    size_t m_numOfRes  { 0u };

  public:
    // Rule of FIVE
    Restaurant(const Reservation* reservations[], size_t cnt);
    Restaurant(const Restaurant& src);
    Restaurant& operator=(const Restaurant& src);
    Restaurant(Restaurant&& src);
    Restaurant& operator=(Restaurant&& src);
    ~Restaurant();

    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, const Restaurant& src);
  };
}
#endif // !SDDS_RESTAURANT_H