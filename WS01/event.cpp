//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           May 29, 2021
// Workshop:       Workshop1
//==============================================
// event.cpp

#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

using namespace std;

size_t g_sysClock = 0;

namespace sdds
{
  Event::~Event()
  {
    if (e_Desc != nullptr) {
      delete[] e_Desc;
      e_Desc = nullptr;
    }
  }

  Event::Event(const Event &src)
  {
    *this = src; // call copy assignment
  }

  Event& Event::operator=(const Event &src)
  {
    // check for self assignment
    if (this != &src) {
      this->e_Time = src.e_Time;

      if (src.e_Desc != nullptr && src.e_Desc[0] != '\0') {
        this->e_Desc = new char[strlen(src.e_Desc) + 1];
        strcpy(this->e_Desc, src.e_Desc);
      }
    }

    return *this;
  }

  void Event::display() const {
    // remains in memory for the lifetime of the program
    static size_t _counter = 1;
    unsigned int hh = 0u, mm = 0u, ss = 0u;

    hh = e_Time / 3600;
    mm = e_Time / 60 % 60;
    ss = e_Time % 60;

    // COUNTER is a field of size 2
    cout << setw(2) << setfill(' ') << _counter++ << ". ";

    if (e_Desc == nullptr || e_Desc[0] == '\0')
      cout << "| No Event |" << endl;
    else {
      cout << setw(2) << setfill('0') << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << " => " << e_Desc << endl;
    }
  }

  void Event::set(const char *_desc) {
    // prepare to overwrite with other descriptions
    if (e_Desc != nullptr) {
      delete[] e_Desc;
      e_Desc = nullptr;
    }

    if (_desc != nullptr && _desc[0] != '\0') {
      e_Desc = new char[strlen(_desc) + 1];
      strcpy(e_Desc, _desc);
      e_Time = ::g_sysClock;
    }
    else
      e_Time = 0;
  }
}