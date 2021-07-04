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
// SpellChecker.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
  SpellChecker::SpellChecker(const char* filename) {
    ifstream _readFile(filename);

    if (!_readFile) {
      throw "Bad file name!";
    }
    else {
      string _line  { "" };
      size_t _count { 0u };
      int _space    { 0u };

      while (_count < STR_SIZE && getline(_readFile, _line)) {
        _line.erase(0, _line.find_first_not_of(' '));
        _space = _line.find(' ');
        m_badWords[_count] = _line.substr(0, _space);
        _line.erase(0, _space);

        _line.erase(0, _line.find_first_not_of(' '));
        _space = _line.find(' ');
        m_goodWords[_count] = _line.substr(0, _space);
        ++_count;
      }
    }
  }

  void SpellChecker::operator()(std::string& text) {
    for (auto i = 0; i < STR_SIZE; ++i) {
      while(text.find(m_badWords[i]) != string::npos) {
        text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
        ++m_replaceCount[i];
      }
    }
  }

  void SpellChecker::showStatistics(std::ostream& out) const {
    out << "Spellchecker Statistics" << endl;

    for (auto i = 0u; i < STR_SIZE; ++i)
      out << setw(15) << std::right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << std::left << endl;
  }
}