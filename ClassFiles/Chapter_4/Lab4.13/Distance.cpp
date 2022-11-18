#include <cmath>

using namespace std;

#include "Distance.h"

Distance::Distance() {
  feet = 0;
  inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
  feet = static_cast<int>(abs(in))/12;
  inches = abs(in) - (feet * 12.0);
  feet += ft;
}

Distance::Distance(double in) {
  feet = static_cast<int>(abs(in))/12;
  inches = abs(in) - (feet * 12.0);
}

unsigned Distance::getFeet() const {
  return feet;
}

double Distance::getInches() const {
  return inches;
}

double Distance::distanceInInches() const {
  return inches + (12 * feet);
}

double Distance::distanceInFeet() const {
  return (static_cast<double>(feet)*12.0 + inches)/12.0;
}

double Distance::distanceInMeters() const {
  return distanceInInches() * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const {
  double inchesTotal = distanceInInches() + rhs.distanceInInches();
  unsigned newfeet = static_cast<int>(abs(inchesTotal))/12;
  double newinches = abs(inchesTotal) - (newfeet * 12.0);

  Distance newDistance(newfeet, newinches);
  return newDistance;
}

Distance Distance::operator-(const Distance &rhs) const {
  double inchesTotal = abs(distanceInInches() - rhs.distanceInInches());
  unsigned newfeet = static_cast<int>(abs(inchesTotal))/12;
  double newinches = abs(inchesTotal) - (newfeet * 12.0);

  Distance newDistance(newfeet, newinches);
  return newDistance;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
  out << rhs.getFeet() << "'" << " " << rhs.getInches() << '"';
  return out;
}