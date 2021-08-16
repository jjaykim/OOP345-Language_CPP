//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 12, 2021
// Workshop:       Project 1
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Station.cpp

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  // default constructor to intialize class variables to the 0
  size_t Station::m_widthField = 0u;
  size_t Station::id_generator = 0u;

  Station::Station(const std::string& src) {
    Utilities util;
    m_id       = ++Station::id_generator;
    bool more  = true;
    size_t pos = 0u;

    try {
      m_name = util.extractToken(src, pos, more);
      m_serial_num = stoi(util.extractToken(src, pos, more));
      m_curr_items = stoi(util.extractToken(src, pos, more));
      Station::m_widthField = max(util.getFieldWidth(), Station::m_widthField);
      m_desc = util.extractToken(src, pos, more);
    }
    catch (std::string err) {
      cout << err;
    }
  }

  const std::string& Station::getItemName() const {
    return m_name;
  }

  size_t Station::getNextSerialNumber() {
    ++m_serial_num;
    return m_serial_num - 1;
  }

  size_t Station::getQuantity() const {
    return m_curr_items;
  }

  void Station::updateQuantity() {
    m_curr_items == 0 ? m_curr_items = 0 : --m_curr_items;
  }

  void Station::display(std::ostream &os, bool full) const {
    os << "[" << right << setw(3) << setfill('0') << m_id << "]";
    os << " Item: " << left << setw(Station::m_widthField) << setfill(' ') << m_name;
    os << " [" << right << setw(6) << setfill('0') << m_serial_num << "]";

    if (full) {
      os << " Quantity: " << left << setw(Station::m_widthField) << setfill(' ') << m_curr_items;
      os << " Description: " << m_desc << endl;
    }
    else
      os << endl;
  }
}