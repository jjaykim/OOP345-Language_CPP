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
// Reservation.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds
{
  Reservation::Reservation(const std::string &res) {
    std::string _temStr = res;
    size_t _temIdx = 0u;

    // ID
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(':');
    m_id = _temStr.substr(0, _temIdx);
    m_id.erase(m_id.find_last_not_of(' ') + 1);
    _temStr.erase(0, _temIdx + 1);

    // NAME
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(',');
    m_name = _temStr.substr(0, _temIdx);
    m_name.erase(m_name.find_last_not_of(' ') + 1);
    _temStr.erase(0, _temIdx + 1);

    // EMAIL
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(',');
    m_email = _temStr.substr(0, _temIdx);
    m_email.erase(m_email.find_last_not_of(' ') + 1);
    _temStr.erase(0, _temIdx + 1);

    // PARTY_SIZE
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(',');
    m_numOfPpl = std::stoi(_temStr.substr(0, _temIdx));
    _temStr.erase(0, _temIdx + 1);

    // DAY
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(',');
    m_day = std::stoi(_temStr.substr(0, _temIdx));
    _temStr.erase(0, _temIdx + 1);

    // HOUR
    _temStr.erase(0, _temStr.find_first_not_of(' '));
    _temIdx = _temStr.find(',');
    m_hour = std::stoi(_temStr.substr(0, _temIdx));
    _temStr.erase(0, _temIdx + 1);
  }

  std::ostream &operator<<(std::ostream &os, const Reservation &src)
  {
    std::string _typeOfMeal = "";
    std::string _typeOfPpl = src.m_numOfPpl == 1 ? " person." : " people.";

    os << "Reservation " << std::setw(10) << src.m_id << ": " << std::setw(20) << src.m_name << "  ";
    os << std::setw(20) << std::left << "<" + src.m_email + ">" << std::right << "    ";

    if (src.m_hour >= 6 && src.m_hour <= 9) { _typeOfMeal = "Breakfast"; }
    else if (src.m_hour >= 11 && src.m_hour <= 15) { _typeOfMeal = "Lunch"; }
    else if (src.m_hour >= 17 && src.m_hour <= 21) { _typeOfMeal = "Dinner"; }
    else { _typeOfMeal = "Drinks"; }

    os << _typeOfMeal << " on day " << src.m_day << " @ " << src.m_hour << ":00 for " << src.m_numOfPpl << _typeOfPpl << endl;

    return os;
  }
}
