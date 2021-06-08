//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           Jun 5, 2021
// Workshop:       Workshop2
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// timedEvents.h

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <string>

namespace sdds
{
  class TimedEvents
  {
    // predefines the maximum number of event objects
    enum { MAX_NUMBER = 10 };
    size_t t_CurRecord { 0u };

    std::chrono::steady_clock::time_point t_startTime;
    std::chrono::steady_clock::time_point t_endTime;

    struct Event {
      std::string e_name;
      std::string e_UnitTime;
      std::chrono::steady_clock::duration e_durationEvent;
      Event() : e_name(""), e_UnitTime("") {}
    } t_event[MAX_NUMBER];

  public:
    TimedEvents(){}

    void startClock();
    void stopClock();
    void addEvent(const char *src);

    friend std::ostream &operator<<(std::ostream &os, const TimedEvents &src);
  };
}
#endif //! SDDS_TIMEDEVENTS_H