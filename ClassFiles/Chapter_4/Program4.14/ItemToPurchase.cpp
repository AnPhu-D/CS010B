#include <iostream>

using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
  _name = "none";
  _description = "none";

  _price = 0;
  _quantity = 0;
}

ItemToPurchase::ItemToPurchase(const string& name, const string& description, const int& price=0, const int& quantity=0) {
  _name = name;
  _description = description;

  _price = price;
  _quantity = quantity;
}

void ItemToPurchase::setName(const string& _name) {
  this->_name = _name;
}
string ItemToPurchase::name() const {
  return _name;
}

void ItemToPurchase::setDescription(const string& _description) {
  this->_description = _description;
}
string ItemToPurchase::description() const {
  return _description;
}

void ItemToPurchase::setPrice(const int& _price) {
  this->_price = _price;
}
int ItemToPurchase::price() const {
  return _price;
}

void ItemToPurchase::setQuantity(const int& _quantity) {
  this->_quantity = _quantity;
}
int ItemToPurchase::quantity() const {
  return _quantity;
}

  // Ex: Bottled Water 10 @ $1 = $10
void ItemToPurchase::printItemCost() const {
  cout << _name << " " << _quantity << " @ $" << _price << " = $" << subtotal() << endl;
}

  // Ex: Bottled Water: Deer Park, 12 oz.
void ItemToPurchase:: printItemDescription() const {
  cout << _name << ": " << _description << endl;
}

int ItemToPurchase::subtotal() const {
  return _price * _quantity;
}