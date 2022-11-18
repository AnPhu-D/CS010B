#include <iostream>

using namespace std;

// Rational Class declaration

class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

int Rational::gcd(int a, int b) const {
   int result = (b==0) ? a : gcd(b, a % b);
   return result;
}

// Constructors
Rational::Rational(int numerator, int denominator) {
   this->numerator = numerator;
   this->denominator = denominator;
}

Rational::Rational(int numerator) {
   this->numerator = numerator;
   this->denominator = 1;
}

Rational::Rational() {
   this->numerator = 0;
   this->denominator = 1;
}

// Accessor Functions
Rational Rational::add(const Rational &that) const {
   int NewN = (this->numerator*that.denominator) + (that.numerator*this->denominator);
   int NewD = (this->denominator*that.denominator);

   return Rational(NewN,NewD);
}

Rational Rational::subtract(const Rational &that) const {
   int NewN = (this->numerator*that.denominator) - (that.numerator*this->denominator);
   int NewD = (this->denominator*that.denominator);

   return Rational(NewN,NewD);
}

Rational Rational::multiply(const Rational &that) const {
   int NewN = this->numerator*that.numerator;
   int NewD = this->denominator*that.denominator;

   return Rational(NewN, NewD);
}

Rational Rational::divide(const Rational &that) const {
   int NewN = this->numerator*that.denominator;
   int NewD = this->denominator*that.numerator;

   return Rational(NewN, NewD);
}

void Rational::simplify() {
   int GCD = this->gcd(this->numerator,this->denominator);
   this->numerator /= GCD;
   this->denominator /= GCD;
}

void Rational::display() const {
   cout << this->numerator << " / " << this->denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

