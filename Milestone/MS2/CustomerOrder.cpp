//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 12, 2021
// Workshop:       Project 2
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// CustomerOrder.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  size_t CustomerOrder::m_widthField = 0u;

  CustomerOrder::CustomerOrder(const std::string& src)
  {
    Utilities util;
    bool more    = true;
    size_t pos   = 0u;
    size_t idx   = 0u;

    try {
      m_name = util.extractToken(src, pos, more);
      m_product = util.extractToken(src, pos, more);
      m_cntItem = std::count(src.begin(), src.end(), util.getDelimiter()) - 1;

      if (m_cntItem)
        m_lstItem = new Item*[m_cntItem];

      while (more && m_cntItem) {
        m_lstItem[idx] = new Item(util.extractToken(src, pos, more));
        ++idx;
      }

      CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
    }
    catch (std::string err) {
      cout << err;
    }
  }

  CustomerOrder::CustomerOrder(const CustomerOrder& src) {
    throw false;
  }

  CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
    *this = std::move(src);
  }

  CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
    if (this != &src) {
      if (m_lstItem) {
        for (auto i = 0u; i < m_cntItem; ++i)
          delete m_lstItem[i];

        delete[] m_lstItem;
      }

      m_name    = src.m_name;
      m_product = src.m_product;
      m_cntItem = src.m_cntItem;
      m_lstItem = src.m_lstItem;

      src.m_name    = "";
      src.m_product = "";
      src.m_cntItem = 0u;
      src.m_lstItem = nullptr;
    }

    return *this;
  }

  CustomerOrder::~CustomerOrder() {
    if (m_lstItem) {
      for (auto i = 0u; i < m_cntItem; ++i)
        delete m_lstItem[i];

      delete[] m_lstItem;
      m_lstItem = nullptr;
    }
  }

  bool CustomerOrder::isFilled() const {
    bool result = true;

    for (auto i = 0u; i < m_cntItem; ++i)
      !m_lstItem[i]->m_isFilled ? result = false : result = true;

    return result;
  }

  bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    bool result = false;

    for (auto i = 0u; i < m_cntItem; ++i)
      m_lstItem[i]->m_itemName == itemName ? result = false : result = true;

    return result;
  }

  void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for (auto i = 0u; i < m_cntItem; ++i) {
      if (m_lstItem[i]->m_itemName == station.getItemName()) {
        if (station.getQuantity()) {
          station.updateQuantity();
          m_lstItem[i]->m_isFilled = true;
          m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
          os << "    Filled ";
        }
        else
          os << "    Unable to fill ";

        os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
      }
    }
  }

  void CustomerOrder::display(std::ostream& os) const {
    os << m_name << " - " << m_product << endl;

    for (auto i = 0u; i < m_cntItem; ++i) {
      os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
      os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName;
      os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
    }
  }
}