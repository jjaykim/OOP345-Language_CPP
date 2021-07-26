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
// Utilities.cpp

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		// TODO: Add your code here to build a list of products
		//         using raw pointers
    for (auto i = 0u; i < desc.size(); ++i) {
      for (auto j = 0u; j < price.size(); ++j) {
        if (desc[i].code == price[j].code) {
          Product* temp = new Product(desc[i].desc, price[j].price);
          temp->validate();
          priceList += temp;

          delete temp;
          temp = nullptr;
        }
      }
    }

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		// TODO: Add your code here to build a list of products
		//         using smart pointers
    for (auto i = 0u; i < desc.size(); ++i) {
      for (auto j = 0u; j < price.size(); ++j) {
        if (desc[i].code == price[j].code) {
          unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
          temp->validate();
          priceList += temp;
        }
      }
    }

		return priceList;
	}
}