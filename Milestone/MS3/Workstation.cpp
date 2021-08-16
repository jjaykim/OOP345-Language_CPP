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
// Workstation.cpp

#include "Workstation.h"

using namespace std;

namespace sdds
{
  std::deque<CustomerOrder> pending;
  std::deque<CustomerOrder> completed;
  std::deque<CustomerOrder> incomplete;

  void Workstation::fill(std::ostream& os) {
    if (!m_orders.empty())
      m_orders.front().fillItem(*this, os);
  }

  bool Workstation::attemptToMoveOrder() {
    bool move_result = false;

    if (!m_orders.empty()) {
      if (m_orders.front().isItemFilled(getItemName())) {
        if (m_pNextStation)
          *m_pNextStation += std::move(m_orders.front());
        else if (!m_orders.front().isFilled())
          incomplete.push_back(std::move(m_orders.front()));
        else
          completed.push_back(std::move(m_orders.front()));

        move_result = true;
        m_orders.pop_front();
      }
      else if (this->getQuantity() <= 0) {
        if (m_pNextStation)
          *m_pNextStation += std::move(m_orders.front());
        else
          incomplete.push_back(std::move(m_orders.front()));

        move_result = true;
        m_orders.pop_front();
      }
    }

    return move_result;
  }

  void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
  }

  Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
  }

  void Workstation::display(std::ostream &os) const {
    if (m_pNextStation)
      os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
    else
      os << getItemName() << " --> " << "End of Line" << endl;
  }

  Workstation& Workstation::operator+=(CustomerOrder &&newOrder) {
    m_orders.push_back(move(newOrder));
    return *this;
  }
}
