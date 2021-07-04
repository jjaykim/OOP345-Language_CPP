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
// Book.h

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds
{
  class Book
  {
    std::string b_author      { "" };
    std::string b_title       { "" };
    std::string b_country     { "" };
    size_t b_year             { 0 };
    double b_price            { 0.0 };
    std::string b_description { "" };

  public:
    Book() {}
    Book(const std::string& strBook);
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();

    template <typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(b_description);
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& src);
  };
}

#endif // !SDDS_BOOK_H