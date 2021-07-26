// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 20, 2021
// Workshop:       Workshop 8
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// List.h

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds
{
  template <typename T>
  class List
  {
    std::vector<T> list;
	public:
		List() { }

		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");

      while (file) {
        T e;

        if (e.load(file))
          list.push_back(T(e));
      }
		}

		size_t size() const { return list.size(); }

		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
    void operator+=(const std::unique_ptr<T>& src) {
      list.push_back(*src);
    }

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
    void operator+=(const T* src) {
      list.push_back(*src);
    }

		void display(std::ostream& os) const {
      os << std::fixed << std::setprecision(2);
      for (auto& e : list)
        e.display(os);
    }
	};

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const List<T>& l) {
    l.display(os);
    return os;
	}
}
#endif