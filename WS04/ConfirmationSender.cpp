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
// ConfirmationSender.cpp

#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
  ConfirmationSender::ConfirmationSender(const ConfirmationSender &src) {
    *this = src;
  }

  ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
    if (this != &src) {
      if (m_ptrListOfRes) {
        delete[] m_ptrListOfRes;
        m_ptrListOfRes = nullptr;
      }

      m_ptrNumOfRes = src.m_ptrNumOfRes;
      m_ptrListOfRes = new const Reservation*[m_ptrNumOfRes];

      for (auto i = 0u; i < m_ptrNumOfRes; ++i)
        m_ptrListOfRes[i] = src.m_ptrListOfRes[i];
    }

    return *this;
  }

  ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
    *this = std::move(src);
  }

  ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
    if (this != &src) {
      if (m_ptrListOfRes) {
        delete[] m_ptrListOfRes;
        m_ptrListOfRes = nullptr;
      }

      m_ptrListOfRes = src.m_ptrListOfRes;
      m_ptrNumOfRes = src.m_ptrNumOfRes;

      src.m_ptrListOfRes = nullptr;
      src.m_ptrNumOfRes = 0u;
    }

    return *this;
  }

  ConfirmationSender::~ConfirmationSender() {
    if (m_ptrListOfRes) {
      delete[] m_ptrListOfRes;
      m_ptrListOfRes = nullptr;
    }
  }

  ConfirmationSender& ConfirmationSender::operator+=(const Reservation &res) {
    bool _flag = false;

    for (auto i = 0u; i < m_ptrNumOfRes && !_flag; ++i) {
      if (m_ptrListOfRes[i] == &res)
        _flag = true;
    }

    if (!_flag) {
      const Reservation** _temp = new const Reservation*[m_ptrNumOfRes + 1u];

      for (auto i = 0u; i < m_ptrNumOfRes; ++i)
        _temp[i] = m_ptrListOfRes[i];

      _temp[m_ptrNumOfRes] = &res;

      if (m_ptrListOfRes) {
        delete[] m_ptrListOfRes;
        m_ptrListOfRes = nullptr;
      }

      m_ptrListOfRes = _temp;
      m_ptrNumOfRes++;
    }

    return *this;
  }

  // // first way
  // ConfirmationSender& ConfirmationSender::operator-=(const Reservation &res) {
  //   bool _flag = false;

  //   for (auto i = 0u; i < m_ptrNumOfRes && !_flag; ++i) {
  //     if (m_ptrListOfRes[i] == &res) {
  //       m_ptrListOfRes[i] = nullptr;

  //       for (auto j = i; j < m_ptrNumOfRes - 1u; ++j) {
  //         m_ptrListOfRes[j] = m_ptrListOfRes[j + 1];
  //       }

  //       m_ptrListOfRes[m_ptrNumOfRes - 1] = nullptr;
  //       m_ptrNumOfRes--;
  //       _flag = true;
  //     }
  //   }

  //   return *this;
  // }

  //! REVIEW: the size of m_ptrListOfRes is the same in first and second way.
  //! REVIEW: The first way is to use an algorithm that pulls an empty space one by one from next
  //! REVIEW: The second way
  //! REVIEW: 1. create temporary object with the value will be resized
  //! REVIEW: 2. save the adresses
  //! REVIEW: 3. resize the member object
  //! REVIEW: 4. save the value of temporary object

  // second way
  ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res) {
    size_t _count = 0u;

    for (auto i = 0u; i < m_ptrNumOfRes; ++i) {
      if (m_ptrListOfRes[i] == &res) {
        m_ptrListOfRes[i] = nullptr;
        _count++;
      }
    }

    if (_count > 0) {
      const Reservation** _temp = new const Reservation*[m_ptrNumOfRes - _count];

      for (auto i = 0u, j = 0u; i < m_ptrNumOfRes; ++i) {
        if (m_ptrListOfRes[i])
          _temp[j++] = m_ptrListOfRes[i];
      }

      delete[] m_ptrListOfRes;
      m_ptrListOfRes = nullptr;
      m_ptrNumOfRes -= _count;

      m_ptrListOfRes = _temp;

    }

    return *this;
  }

  std::ostream &operator<<(std::ostream &os, const ConfirmationSender &src)
  {
    os << "--------------------------" << endl;
    os << "Confirmations to Send" << endl;
    os << "--------------------------" << endl;

    if (src.m_ptrNumOfRes == 0u)
    {
      os << "There are no confirmations to send!" << endl;
    }
    else
    {
      for (auto i = 0u; i < src.m_ptrNumOfRes; ++i)
        os << *src.m_ptrListOfRes[i];
    }

    os << "--------------------------" << endl;

    return os;
  }
  }