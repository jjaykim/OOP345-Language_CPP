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
// SongCollection.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <iterator>
#include "SongCollection.h"

using namespace std;

namespace sdds
{
  SongCollection::SongCollection(const char* src) {
    ifstream readfile(src);
    Song     new_song;
    string   one_line;

    auto extract_data = [](string &src, int idx) {
      string result = src.substr(0, idx);

      src = src.substr(idx);
      result.erase(0, result.find_first_not_of(' '));
      result.erase(result.find_last_not_of(' ') + 1);

      return result;
    };

    if (!readfile)
      cout << "Error: Bad file name!" << endl;
    else {
      while(getline(readfile, one_line)) {
        new_song.m_title = extract_data(one_line, 25);
        new_song.m_artist = extract_data(one_line, 25);
        new_song.m_album = extract_data(one_line, 25);
        new_song.m_year = extract_data(one_line, 5);
        new_song.m_length = stoi(extract_data(one_line, 5));
        new_song.m_price = stod(extract_data(one_line, 5));

        m_total += new_song.m_length;

        m_song.push_back(new_song);
      }
    }
  }

  void SongCollection::sort(std::string src)
  {

    if (src == "title")
      std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& anotherSong) {
        return theSong.m_title < anotherSong.m_title;
      });

    else if (src == "album")
      std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& anotherSong) {
        return theSong.m_album < anotherSong.m_album;
      });

    else if (src == "length")
      std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& anotherSong) {
        return theSong.m_length < anotherSong.m_length;
      });

    else
      cout << "Error: Invalid input!" << endl;
  }

  void SongCollection::cleanAlbum() {
    for_each(m_song.begin(), m_song.end(), [](Song& theSong) {
      theSong.m_album = theSong.m_album == "[None]" ? "" : theSong.m_album;
    });
  }

  bool SongCollection::inCollection(std::string src) const
  {
    return any_of(m_song.begin(), m_song.end(), [src](const Song& theSong) {
      return theSong.m_artist == src;
    });
  }

  std::list<Song> SongCollection::getSongsForArtist(std::string src) const
  {
    std::list<Song> result;

    copy_if(m_song.begin(), m_song.end(), back_inserter(result), [src](const Song& theSong) {
      return theSong.m_artist == src;
    });

    return result;
  }

  void SongCollection::display(std::ostream& out) const {
    size_t hour = m_total / 3600;
    size_t min  = (m_total % 3600) / 60;
    size_t sec  = (m_total % 3600) % 60;

    for_each(m_song.begin(), m_song.end(), [&out](const Song& theSong) {
      out << theSong << endl;
    });

    out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
    out << "|" << right << setw(78) << setfill(' ') << "Total Listening Time: ";
    out << hour << ":" << min << ":" << sec << " |" << endl;
  }

  std::ostream &operator<<(std::ostream& out, const Song& theSong) {
    out << "| " << left << setw(20) << setfill(' ') << theSong.m_title;
    out << " | " << setw(15) << setfill(' ') << theSong.m_artist;
    out << " | " << setw(20) << setfill(' ') << theSong.m_album;
    out << " | " << right << setw(6) << theSong.m_year;
    out << " | " << theSong.m_length / 60 << ":";
    out << setw(2) << setfill('0') << theSong.m_length % 60;
    out << " | " << fixed << setprecision(2) << theSong.m_price << " |";

    return out;
  }
}