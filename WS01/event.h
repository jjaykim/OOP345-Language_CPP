//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           May 29, 2021
// Workshop:       Workshop1
//==============================================
// event.h

#ifndef EVENT_H
#define EVENT_H

// global varialbe that stores only positive integers.
extern size_t g_sysClock;

namespace sdds
{
  class Event
  {
    size_t e_Time  { 0 };
    char  *e_Desc  { nullptr };

  public:
    Event() {};
    ~Event();
    Event(const Event &src);
    Event &operator=(const Event &src);
    void display() const;
    void set(const char *_desc = nullptr);
  };
}

#endif // !event.h