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
// Pair.h

#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_

#include <iostream>

namespace sdds
{
  template<typename V, typename K>
  class Pair
  {
    K m_key;
    V m_value;

  public:
    Pair() : m_key(), m_value() {}
    Pair(const K &key, const V &value) : m_key(key), m_value(value) {}
    const V &value() const { return m_value; }
    const K &key() const { return m_key; }

    virtual void display(std::ostream &os) const {
      os << key() << " : " << value() << std::endl;
    }
  };

  template<typename V, typename K>
  std::ostream &operator<<(std::ostream &os, const Pair<V, K> &pair) {
    pair.display(os);
    return os;
  }
}
#endif  // !SDDS_PAIR_H_