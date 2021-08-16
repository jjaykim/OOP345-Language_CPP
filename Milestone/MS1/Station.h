//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 12, 2021
// Workshop:       Project 1
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Station.h

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds
{
  class Station
  {
    int m_id            { 0 }; // the id of the station
    std::string m_name  { "" }; // the name of the item handled by the station
    std::string m_desc  { "" }; // the description of the station
    size_t m_serial_num { 0u }; // the next serial number to be assigned to an item at this station
    size_t m_curr_items { 0u }; // the number of items currently in stock

    // Class Variables
    static size_t m_widthField;
    static size_t id_generator;

  public:
    Station(const std::string& src);

    // returns the name of the current Station object
    const std::string &getItemName() const;

    // returns the next serial number
    size_t getNextSerialNumber();

    // returns the remaining quantity of items
    size_t getQuantity() const;

    // subtracts 1 from the available quantity
    void updateQuantity();

    // display information about the current object
    void display(std::ostream &os, bool full) const;
  };
}
#endif // !SDDS_STATION_H