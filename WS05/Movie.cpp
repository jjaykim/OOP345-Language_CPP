//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           June 27, 2021
// Workshop:       Workshop5
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Movie.cpp

#include <iostream>
#include <iomanip>
#include "Movie.h"

using namespace std;

namespace sdds
{
  const std::string& Movie::title() const {
    return m_title;
  }

  Movie::Movie(const std::string& strMovie) {
    if (!strMovie.empty()) {
      string _tempStr = strMovie;
      int _tempIdx = 0u;

      auto removeSpace = [=](string &src) {
        if (src[0] == ' ')
          src.erase(0, src.find_first_not_of(' '));
        else
          src.erase(src.find_last_not_of(' ') + 1);
      };

      removeSpace(_tempStr);
      _tempIdx = _tempStr.find(',');
      m_title = _tempStr.substr(0, _tempIdx);
      removeSpace(m_title);
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      _tempIdx = _tempStr.find(',');
      m_year = std::stoi(_tempStr.substr(0, _tempIdx));
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      removeSpace(_tempStr);
      m_description = _tempStr;
    }
  }

  std::ostream &operator<<(std::ostream &os, const Movie &src) {
    os << setw(40) << std::right << src.m_title << " | ";
    os << std::left << setw(4) << src.m_year << " | " << src.m_description << endl;

    return os;
  }
}