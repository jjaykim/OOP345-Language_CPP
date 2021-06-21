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
// ConfirmationSender.h

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
  class ConfirmationSender
  {
    const Reservation** m_ptrListOfRes { nullptr };
    size_t m_ptrNumOfRes { 0u };

  public:
    // Rule of FIVE
    ConfirmationSender() {}
    ConfirmationSender(const ConfirmationSender& src);
    ConfirmationSender& operator=(const ConfirmationSender& src);
    ConfirmationSender(ConfirmationSender&& src);
    ConfirmationSender& operator=(ConfirmationSender&& src);
    ~ConfirmationSender();

    ConfirmationSender &operator+=(const Reservation& res);
    ConfirmationSender &operator-=(const Reservation& res);

    friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
  };
}
#endif // !SDDS_CONFIRMATIONSENDER_H