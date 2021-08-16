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
// LineManager.h

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds
{
  class LineManager
  {
    std::vector<Workstation*> activeLine;                // the collection of workstations for the current assembly line
    size_t                    m_cntCustomerOrder { 0u }; // the total number of CustomerOrder objects
    Workstation*              m_firstStation; // points to the first active station on the current line
    // Workstation*              m_firstStation { nullptr}; // points to the first active station on the current line

  public:
    LineManager(const std::string &file, const std::vector<Workstation*>& stations);
    void linkStations();
    bool run(std::ostream &os);
    void display(std::ostream &os) const;
  };
}
#endif // !SDDS_LINEMANAGER_H