//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 29, 2021
// Workshop:       Project 3
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Utilities.h

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds
{
  class Utilities
  {
    size_t m_widthField { 1u }; //  specifies the length of the token extracted

    // Class Variables
    static char m_delimiter;    // separates the tokens in any given std::string object

  public:
    // sets the field width of the current object
    void setFieldWidth(size_t newWidth);

    // returns the field width of the current object
    size_t getFieldWidth() const;

    // extracts a token from string str referred to by the first parameter
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

    // Class Functions
    // sets the m_delimiter to the received delimiter
    static void setDelimiter(char newDelimiter);

    // returns the delimiter
    static char getDelimiter();
  };
}
#endif // !SDDS_UTILITIES_H