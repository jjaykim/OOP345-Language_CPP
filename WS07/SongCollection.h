
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 15, 2021
// Workshop:       Workshop 7
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// SongCollection.h

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds
{
  struct Song {
    std::string m_artist {};
    std::string m_title  {};
    std::string m_album  {};
    std::string m_year   {};
    double      m_price  {};
    size_t      m_length {};
  };

  class SongCollection
  {
    std::vector<Song> m_song;
    size_t            m_total { 0u };

  public:
    SongCollection(const char *src);
    void display(std::ostream &out) const;

    // receives as a parameter the name of the field used to sort the collection of songs in ascending order.
    void sort(std::string src);

    // removes the token [None] from the album field
    void cleanAlbum();

    // find an artist's song with the same name as the artist received
    bool inCollection(std::string src) const;

    // copy an artist's song with the same name as the artist received
    std::list<Song> getSongsForArtist(std::string src) const;
  };
  std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H