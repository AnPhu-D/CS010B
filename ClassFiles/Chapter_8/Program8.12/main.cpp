#include <iostream>

using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {
  int Test;
  cout << "Test Case (1-2): ";
  cin >> Test;

  if (Test == 1) {
    cout << "------------ Testing: ------------" << endl;
    IntList is;
    is.push_back(1);
    is.push_back(1);
    is.push_back(1);

    is.push_back(2);
    is.push_back(3);

    cout << "List 1: " << is << endl;

    SortedSet ss(is);
    is.push_back(5);

    cout << "SortedSet 1: " << ss << endl;
    cout << "List 1: " << is << endl;

    SortedSet ss2(ss);
    cout << "SortedSet 2: " << ss2 << endl;

    cout << ss2.in(1) << " should be 1." << endl;

    SortedSet ss3(is);
    is.push_back(35);
    SortedSet ss4(is);

    ss4.add(15);

    ss3.push_back(16);
    ss3.push_front(25);

    cout << "---------------------------------" << endl;
    cout << "SortedSet 3: " << ss3 << endl;
    cout << "SortedSet 4: " << ss4 << endl;

    SortedSet ss5 = ss3 | ss4;
    cout << "Unioned Sets: " << ss5 << endl
         << endl;

    cout << "---------------------------------" << endl;
    cout << "SortedSet 3: " << ss3 << endl;
    cout << "SortedSet 4: " << ss4 << endl;

    SortedSet ss6 = ss3 & ss4;
    cout << "Intersected Set: " << ss6 << endl;

    ss3 &= ss4;
    cout << "SortedSet 3 after Intersction: " << ss3 << endl;
  } else if (Test == 2) {
    IntList is;
    for (int i = 1; i < 6; ++i) {
      is.push_back(i);
    }

    SortedSet ss1 = SortedSet(is);
    SortedSet ss2 = SortedSet();

    cout << "SS1: " << ss1 << endl;
    cout << "SS2: " << ss2 << endl;

    cout << "----------" << endl;

    SortedSet ss3 = ss1&ss2;
    cout << "SS3: " << ss3 << endl;

  }
}