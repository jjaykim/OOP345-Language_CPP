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
// Book.cpp

#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds
{
  const std::string& Book::title() const {
    return b_title;
  }

  const std::string& Book::country() const {
    return b_country;
  }

  const size_t& Book::year() const {
    return b_year;
  }

  double& Book::price() {
    return b_price;
  }

  Book::Book(const std::string &strBook) {
    string _tempStr = strBook;
    int _tempIdx = 0u;

    auto removeSpace = [=](string& src) {
       if (src[0] == ' ')
        src.erase(0, src.find_first_not_of(' '));
      else
        src.erase(src.find_last_not_of(' ') + 1);
    };

    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    b_author = _tempStr.substr(0, _tempIdx);
    removeSpace(b_author);
    _tempStr.erase(0, _tempIdx + 1);


    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    b_title = _tempStr.substr(0, _tempIdx);
    removeSpace(b_title);
    _tempStr.erase(0, _tempIdx + 1);

    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    b_country = _tempStr.substr(0, _tempIdx);
    removeSpace(b_country);
    _tempStr.erase(0, _tempIdx + 1);

    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    b_price = std::stod(_tempStr.substr(0, _tempIdx));
    _tempStr.erase(0, _tempIdx + 1);

    removeSpace(_tempStr);
    _tempIdx = _tempStr.find(',');
    b_year = std::stoi(_tempStr.substr(0, _tempIdx));
    _tempStr.erase(0, _tempIdx + 1);

    removeSpace(_tempStr);
    removeSpace(_tempStr);
    b_description = _tempStr;
  }

  std::ostream& operator<<(std::ostream& os, const Book& src) {
    os << setw(20) << std::right << src.b_author << " | ";
    os << setw(22) << src.title() << " | ";
    os << setw(5) << src.country() << " | ";
    os << setw(4) << src.year() << " | ";
    os << setw(6) << fixed << setprecision(2) << src.b_price << " | ";
    os << std::left << src.b_description << endl;

    return os;
  }
}