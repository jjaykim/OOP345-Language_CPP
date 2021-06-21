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

#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds
{
  Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
    m_numOfRes = cnt;
    m_listOfRes = new Reservation[m_numOfRes];

    for (auto i = 0u; i < m_numOfRes; ++i) {
      m_listOfRes[i] = *reservations[i];
    }
  }

  Restaurant::Restaurant(const Restaurant& src) {
    *this = src;
  }

  Restaurant& Restaurant::operator=(const Restaurant& src) {
    if (this != &src) {
      if (m_listOfRes) {
        delete[] m_listOfRes;
        m_listOfRes = nullptr;
      }

      if (src.m_numOfRes > 0) {
        m_numOfRes = src.m_numOfRes;

        // deep copy
        m_listOfRes = new Reservation[m_numOfRes];

        for (auto i = 0u; i < m_numOfRes; ++i)
          m_listOfRes[i] = src.m_listOfRes[i];
      }
    }

    return *this;
  }

  Restaurant::Restaurant(Restaurant&& src) {
    *this = std::move(src);
  }

  Restaurant& Restaurant::operator=(Restaurant&& src) {
    if (this != &src) {
      if (m_listOfRes) {
        delete[] m_listOfRes;
        m_listOfRes = nullptr;
      }

      // shallow copy
      m_numOfRes = src.m_numOfRes;
      m_listOfRes = src.m_listOfRes;

      src.m_numOfRes = 0u;
      src.m_listOfRes = nullptr;
    }

    return *this;
  }

  Restaurant::~Restaurant()
  {
    if (m_listOfRes) {
      delete[] m_listOfRes;
      m_listOfRes = nullptr;
    }
  }

  size_t Restaurant::size() const {
    return m_numOfRes;
  }



  std::ostream& operator<<(std::ostream &os, const Restaurant &src) {
    static int _counter = 0;
    os << "--------------------------" << endl;
    os << "Fancy Restaurant (" << ++_counter << ")" << endl;
    os << "--------------------------" << endl;

    if (src.m_numOfRes == 0u)
      os << "This restaurant is empty!" << endl;
    else {
      for (auto i = 0u; i < src.m_numOfRes; ++i)
        os << src.m_listOfRes[i];
    }

    os << "--------------------------" << endl;

    return os;
  }
}