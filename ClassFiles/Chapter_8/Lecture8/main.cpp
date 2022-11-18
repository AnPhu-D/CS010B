#include <iostream>

using namespace std;

class TestClass {
 private:
  int privateNum = 0;

 protected:
  int protectedNum = 1;

 public:
  int publicNum = 2;
};

class DerivedClass : public TestClass {
 public:
  int derived_publicNum = 3;

  int getprot() {
    return protectedNum;
  }

  // int getpriv() {
  //   return privateNum;
  // }
};

int main() {
  
  DerivedClass* dcp = new DerivedClass();
  cout << dcp->derived_publicNum << endl;
  cout << "------" << endl;

  cout << dcp->publicNum << " is Publicnum of TestClass" << endl;
  cout << dcp->getprot() << " is ProtectedNum of TestClass" << endl;
  // cout << dcp->privateNum << " is PrivateNum of TestClass" << endl;
}