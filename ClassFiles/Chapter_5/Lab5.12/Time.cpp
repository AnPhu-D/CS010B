// Time class implementation file

#include <iomanip> // library needed for setfill and setw

using namespace std;

#include "Time.h"

int max(const int& a, const int& b) {
  if (a > b)  {
    return a;
  }
  return b;
}

int min(const int& a, const int& b) {
  if (a < b) {
    return a;
  }
  return b;
}

void Time::init() {
  if (_ampm != "am" && _ampm != "pm" && _ampm != "") {
    _ampm = "am";
  } 

    _minute = min(_minute, 59);
    _minute = max(_minute, 0);

    _second = min(_second, 59);
    _second = max(_second, 0);

  if (_ampm == "") {
    _hour = min(_hour, 23); // Clamp hour below or equal to 23
    _hour = max(_hour, 0); // Clamp hour above or equal to 0
  } else {
    _hour = min(_hour, 12); // Clamp hour below or equal to 23
    _hour = max(_hour, 1); // Clamp hour above or equal to 0
  }

}

Time::Time() {
  _hour = 0;
  _hour = 0;
  _second = 0;
  _ampm = "";

  init();
}

Time::Time(int hour, int minute, int second) {
  _hour = hour;
  _minute = minute;
  _second = second;
  _ampm = "";

  init();
}

Time::Time(int hour, int minute, int second, const string& ampm) {
  _hour = hour;
  _minute = minute;
  _second = second;
  _ampm = ampm;

  init();
}

ostream& operator<<(ostream& o, const Time& oTime) {
  if (oTime._ampm == "") {
    o << setw(2) << setfill('0') << oTime._hour;
  } else {
    o << oTime._hour;
  }
  
  o << ':' << setw(2) << setfill('0') << oTime._minute;
  o << ':' << setw(2) << setfill('0') << oTime._second << oTime._ampm;

  return o;
}