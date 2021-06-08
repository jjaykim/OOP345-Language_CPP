//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           Jun 5, 2021
// Workshop:       Workshop2
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// StringSet.h

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <string>

namespace sdds
{
  class StringSet
  {
    size_t s_CurRecord { 0u };
    std::string *s_str { nullptr };

  public:
    StringSet() {}
    StringSet(const char *_filename);           // 1-argument constructor
    ~StringSet();
    StringSet(const StringSet &src);            // copy constructor
    StringSet &operator=(const StringSet &src); // copy assignment
    StringSet(StringSet &&src);                 // move constructor
    StringSet &operator=(StringSet &&src);      // move assignment

    size_t size() const;
    std::string operator[](size_t) const;
  };
}
#endif //! SDDS_STRINGSET_H