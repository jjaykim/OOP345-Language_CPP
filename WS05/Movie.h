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
// Movie.h

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
  class Movie
  {
    std::string m_title       { "" };
    size_t m_year             { 0u };
    std::string m_description { "" };

  public:
    Movie(){}
    const std::string &title() const;
    Movie(const std::string& strMovie);

    template <typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(m_title);
      spellChecker(m_description);
    }

    friend std::ostream& operator<<(std::ostream& os, const Movie& src);
  };
}
#endif // !SDDS_MOVIE_H