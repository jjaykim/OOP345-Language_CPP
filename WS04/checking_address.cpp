#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Reservation {
  string id = "";
  string name = "";
  string email = "";
  int ppl = 0;
  int day = 0;
  int hour = 0;

public:
  Reservation(){}
  Reservation(const string& res) {
    string src = res;
    int idx = 0;

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(':');
    id = src.substr(0, idx);
    id.erase(id.find_last_not_of(' ') + 1);
    src.erase(0, idx + 1);

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(',');
    name = src.substr(0, idx);
    name.erase(name.find_last_not_of(' ') + 1);
    src.erase(0, idx + 1);

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(',');
    email = src.substr(0, idx);
    email.erase(email.find_last_not_of(' ') + 1);
    src.erase(0, idx + 1);

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(',');
    ppl = std::stoi(src.substr(0, idx));
    src.erase(0, idx + 1);

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(',');
    day = std::stoi(src.substr(0, idx));
    src.erase(0, idx + 1);

    src.erase(0, src.find_first_not_of(' '));
    idx = src.find(',');
    hour = std::stoi(src.substr(0, idx));
    src.erase(0, idx + 1);
  }

  friend std::ostream &operator<<(std::ostream &os, const Reservation &src) {
    string _typeOfMeal = "";
    std::string _typeOfPpl = src.ppl == 1 ? " person." : " people.";

    os << "Reservation " << std::setw(10) << src.id << ": " << std::setw(20) << src.name << "  ";
    os << std::setw(20) << std::left << "<" + src.email + ">" << std::right << "    ";

    if (src.hour >= 6 && src.hour <= 9) { _typeOfMeal = "Breakfast"; }
    else if (src.hour >= 11 && src.hour <= 15) { _typeOfMeal = "Lunch"; }
    else if (src.hour >= 17 && src.hour <= 21) { _typeOfMeal = "Dinner"; }
    else { _typeOfMeal = "Drinks"; }

    os << _typeOfMeal << " on day " << src.day << " @ " << src.hour << ":00 for " << src.ppl << _typeOfPpl << endl;

    return os;
  }
};


class Restaurant {
  Reservation* res = nullptr;
  size_t idx = 0u;

public:
  Restaurant(const Reservation* reservations[], size_t cnt) {
    idx = cnt;
    res = new Reservation[idx];

    for (auto i = 0u; i < idx; ++i) {
      res[i] = *reservations[i];
      cout << endl << endl << "Test: " << endl;
      cout << "===================================" << endl;
      cout << &res[i] << "    " << res[i] << endl;
      cout << reservations[i] << "    " << *reservations[i] << endl;
      cout << "===================================" << endl;

      // ???????????? ?????? ??????
    }
  }
  ~Restaurant() {
    delete[] res;
  }
};

class Confirm {
  const Reservation** _res {nullptr};
  size_t _idx {0u};

public:
  Confirm() {}
  Confirm(const Reservation& src, size_t cnt) {
    _idx = cnt;
    _res = new const Reservation*[_idx];

    // for (auto i = 0u; i < _idx; ++i) {
      const Reservation** temp = new const Reservation*[1];
      temp[0] = &src;

      // _res = temp; // ?????? ????????? ?????????
      // *_res = *temp;  // ?????? ?????? ?????????
      _res[0] = temp[0];  // ?????? ?????? ??????

      cout << endl << "==== CHECK1 ==== " << endl;
      cout << &_res << " " << &temp << endl;     // ????????? ?????? (??????????????????)
      cout << _res[0] << " " << temp[0] << endl; // ???????????? ?????? (??? ?????? ?????? ???)
      cout << *_res[0] << " " << *temp[0] << endl; // ??? ??????

      cout << endl << "==== CHECK2 ==== " << endl;
      delete[] temp;
      temp = nullptr;
      cout << &_res << " " << temp << endl; // temp ?????? ?????????
      cout << *_res[0] << "  " << _res[0] << endl;  //temp??? ?????? ????????? ??????(src??? ??????????????????)
      // cout << *_res[0] << " " << *temp[0] << endl;

      cout << endl << "==== CHECK3 ==== " << endl;
      // _res[i] = src[i];                                // ??? ?????? ????????? ??????[3]
      // cout << (*_res)[i] << "    " << *src[i] << endl; // ??? ?????? ?????????...[3]
      // cout << &(*_res) << "    " << &src << endl;    // ????????? ?????? ?????? [3]

      // _res[0] = &src; // ?????? ?????? [1]
      cout << *_res[0] << "    " << src << endl; // ??? ?????? (temp??? src?????? ?????? res?????? ??????)
      cout << *_res << "    " << &src << endl; // ???????????? ?????? (*_res = _res[0])
    // }


    // cout << endl << "==== CHECK ==== " << endl;
    // *_res = &(*src)[0]; // ?????? ?????? [1]
    // *_res = *src; // ????????? ?????? [2]
    // _res = src; // ??? ?????? ????????? ??????[3]

    // cout << *(*_res) << "    " << (*src)[0] << endl; // ???????????? ?????? [1] (??? ??????)
    // cout << (*_res) << "    " << &(*src)[0] << endl; // ???????????? ?????? [1] (????????????)
    // cout << (*_res) << "    " << &(*src)[0] << endl; // ???????????? ?????? [1] (????????????)

    // cout << *_res << "    " << *src << endl; // ???????????? ?????? [2]
    // cout << *_res[0] << "    " << *src[0] << endl; // ??? ?????? ?????? [2]

    // cout << &(*_res) << "    " << &src << endl;    // ????????? ?????? ?????? [3]
    // cout << *(*_res) << "    " << *src[0] << endl; // ??? ?????? ?????? [3]

  }


  // ~Confirm(){
  //   if (_res)
  //   delete _res;
  // }

  Confirm(const Confirm& src) {
    *this = src;
  }
  Confirm& operator=(const Confirm& src) {
    if (this != &src) {
      if (this->_res) {
        delete[] _res;
        _res = nullptr;
      }

      _idx = src._idx;
      _res = new const Reservation*[_idx];

      for (auto i = 0u; i < _idx; ++i) {
        _res[i] = src._res[i];
        cout << endl << "===== ADDRESS ==== " << endl;
        cout << &_res[i] << ",    " << &(*src._res[i]) << endl; // ????????? ??????
      }
    }
    return *this;
  }
};

int main()
{

  string a = "1234  : John    ,  john@email.com  ,           2,   3,    5";
  string b = "ab defghij: David   , david@email.com  ,          1 ,   4,    6";
  string c = "      RES-004: Ana     ,   ana@email.com  ,        1   ,   5 ,    8";

  const Reservation* *test = new const Reservation*[2];
  test[0] = new const Reservation(a);
  test[1] = new const Reservation(b);
  cout << "main: " << a;


  Restaurant aa(test, 1);

  Confirm bb(*test[0], 1);

  cout << endl << "=====AAAAA=====" <<  endl << &a<< endl;

  cout << endl << "==== BBBBB ======" << endl << &test << "    " << &*test << "     " << &*test[0] << "    " <<&test[0] << endl;

  // &test: ?????? ??? Reservation* ????????? ??????????????? test??? ??????
  // &*test: ????????? ?????? test??? ????????? Reservation* ????????? ????????? ??????
  // &*test[0]: ??????????????? test??? ????????? Reservation* ????????? Reservation ????????? ??????
  // &test[0]: ??????????????? test??? ????????? Reservation* ????????? ?????? ??????

  Confirm cc(bb);

  delete[] test;


}