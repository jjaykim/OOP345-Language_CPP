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
// SpellChecker.h

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds
{
  const int STR_SIZE = 6;
  class SpellChecker
  {
    std::string m_badWords[STR_SIZE]  {};
    std::string m_goodWords[STR_SIZE] {};
    size_t m_replaceCount[STR_SIZE]   {};

  public:
    SpellChecker() {}
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
  };
}
#endif // !SDDS_SPELLCHECKER_H