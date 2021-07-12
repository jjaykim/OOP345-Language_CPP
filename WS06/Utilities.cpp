//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 9, 2021
// Workshop:       Workshop6
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Utilities.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"

using namespace std;

namespace sdds
{
  Vehicle* createInstance(std::istream& in) {
    string str = "";
    char type  = '\0';
    char comma = '\0';

    getline(in, str);
    str.erase(0, str.find_first_not_of(' '));
    stringstream sstr(str);
    sstr >> type >> comma;


    if (sstr) {

      switch(type) {
        case 'c':
        case 'C':
          return new Car(sstr);
          break;

        case 'r':
        case 'R':
          return new Racecar(sstr);
          break;

        default:
          str = type;
          throw "Unrecognized record type: [" + str + "]";
      }
    }
    return nullptr;
  }
}