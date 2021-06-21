
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
// Reservation.h

#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_

#include <iostream>
#include <string>

namespace sdds
{
  class Reservation
  {
    std::string m_id    { "" };
    std::string m_name  { "" };
    std::string m_email { "" };
    size_t m_numOfPpl   { 0u };
    size_t m_day        { 0u };
    size_t m_hour       { 0u };

  public:
    Reservation() {}
    Reservation(const std::string& res);
    friend std::ostream& operator<<(std::ostream& os, const Reservation& src);
  };
}
#endif // !SDDS_RESERVATION_H_
