#include <iomanip>
#include <iostream>

using namespace std;

#include "IntVector.h"

void printTitle(string TitleText) {
  if (TitleText.length() > 20) {
    cout << "TitleText is too long!";
    exit(1);
  }

  int TotalSize = 30;
  int CountLeft = TotalSize - (TitleText.length() / 2);

  cout << setfill('-') << setw(CountLeft) << "-";
  cout << TitleText;
  cout << setfill('-') << setw(CountLeft - (CountLeft % 2)) << "-";
  cout << endl;
}

int main() {
  printTitle("Test Harness");

  // Test default constructor
  IntVector Vector1;
  cout << "V1 Empty?: " << Vector1.empty() << endl
       << endl;
  ;

  // Test parameterized constructors
  IntVector Vector2(3);
  cout << "V2 Empty?: " << Vector2.empty() << endl;
  cout << "V2 Size  : " << Vector2.size() << endl;
  for (unsigned i = 0; i < Vector2.size(); ++i) {
    cout << "  V2[" << i << "] = " << Vector2.at(i) << endl;
  }
  cout << "V2 Front : " << Vector2.front() << endl;
  cout << "V2 Back  : " << Vector2.back() << endl << endl; 

  IntVector Vector3(3, 1);
  cout << "V3 Empty?: " << Vector3.empty() << endl;
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;
  for (unsigned i = 0; i < Vector3.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector3.at(i) << endl;
  }
  cout << "V3 at 1  : " << Vector3.at(1) << endl;


  Vector3.insert(1,5);
  for (unsigned i = 0; i < Vector3.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector3.at(i) << endl;
  }
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;

  cout << "AAA" << endl;
  Vector3.insert(1,5);
  for (unsigned i = 0; i < Vector3.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector3.at(i) << endl;
  }
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;

  Vector3.erase(1);
  Vector3.erase(1);
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;

  Vector3.push_back(15);
  Vector3.pop_back();
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;

  Vector3.resize(5,5);
  cout << "V3 Size  : " << Vector3.size() << endl;
  cout << "V3 Cap   : " << Vector3.capacity() << endl;

  cout << "AAA" << endl;
  for (unsigned i = 0; i < Vector3.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector3.at(i) << endl;
  }

  Vector3.assign(10,9);
  cout << "AAA" << endl;
  for (unsigned i = 0; i < Vector3.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector3.at(i) << endl;
  }

  IntVector Vector4;
  Vector4.push_back(200);

  cout << "V4 Size  : " << Vector4.size() << endl;
  cout << "V4 Cap   : " << Vector4.capacity() << endl;

  for (unsigned i = 0; i < Vector4.size(); ++i) {
    cout << "  V3[" << i << "] = " << Vector4.at(i) << endl;
  }

  IntVector Vector5(17,1);
  cout << "V5 Size  : " << Vector5.size() << endl;
  cout << "V5 Cap   : " << Vector5.capacity() << endl;

  Vector5.insert(17, 5);
  // Vector5.at(17);

  cout << "V5 Size  : " << Vector5.size() << endl;
  cout << "V5 Cap   : " << Vector5.capacity() << endl;


  // Vector5.reserve(4);
  // cout << "V5 Size  : " << Vector5.size() << endl;
  // cout << "V5 Cap   : " << Vector5.capacity() << endl;

  // Vector5.erase(0);



  return 0;
}