// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 16, 2021
// Workshop:       Project 1
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Element.h

#ifndef SDDS_ELEMENT_H
#define SDDS_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sdds
{
  // ~~~~ Description Struct ~~~~
  struct Description {
		unsigned code;
		std::string desc;

		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream& os) const {
			os << std::setw(FWC) << code
				 << std::setw(FWD) << desc
				 << std::endl;
		}
	};

  // ~~~~ Price Struct ~~~~
  struct Price {
		unsigned code;
		double price;

		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				 << price << std::endl;
		}
	};

  // ~~~~ Product Struct ~~~~
	struct Product {
		std::string   m_desc  {};
		double        m_price {};
		int           m_id    {};
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool   Trace;

		Product() {
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}

		Product(const std::string& str, double p) {
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}

		Product(const Product& other) {
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}

		~Product() {
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		// TODO: add a function here to validate the price
    void validate() const {
      if (m_price < 0.0)
        throw std::string("*** Negative prices are invalid ***");
    }

		void display(std::ostream& os) const {
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif