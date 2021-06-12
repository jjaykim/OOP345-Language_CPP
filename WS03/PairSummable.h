//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           June 11, 2021
// Workshop:       Workshop3
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// PairSummable.h

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds
{
  template<typename V, typename K>
  class PairSummable : public Pair<V, K>
  {
    static V initial;
    static size_t m_fieldWidth;

  public:
    PairSummable() : Pair<V, K>() {}

    PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
      if (key.size() > m_fieldWidth)
        m_fieldWidth = key.size();
    }

    bool isCompatibleWith(const PairSummable<V, K> &b) const { return this->key() == b.key(); }

    PairSummable& operator+=(const PairSummable& src) {
      // if condition met, adds the value of the parameter object to the value of the current object
      if (isCompatibleWith(src))
        *this = PairSummable(this->key(), this->value() + src.value());

      return *this;
    }

    void display(std::ostream& os) const override {
      os << std::left << std::setw(m_fieldWidth);
      Pair<V, K>::display(os);
      os << std::right;
    }
  };

  template<>
  PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src) {
    if (this->value() == "")
      *this = PairSummable(this->key(), src.value());
    else
      *this = PairSummable(this->key(), this->value() + ", " + src.value());

    return *this;
  }

  // uniform initialization
  template<typename V, typename K>
  V PairSummable<V, K>::initial {};

  template<typename V, typename K>
  size_t PairSummable<V, K>::m_fieldWidth { 0u };
}
#endif // !SDDS_PAIRSUMMABLE_H