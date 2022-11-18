#include <iostream>
#include <vector>

using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
  _customerName = "none";
  _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(const string& _customerName, const string& _currentDate) {
  this->_customerName = _customerName;
  this->_currentDate = _currentDate;
}

string ShoppingCart::customerName() const {
  return _customerName;
}

string ShoppingCart::date() const {
  return _currentDate;
}

void ShoppingCart::addItem(const ItemToPurchase& _newItem) {
  _cartItems.push_back(_newItem);
}

void ShoppingCart::removeItem(const string& _itemName) {
  for (unsigned i = 0; i < _cartItems.size(); ++i) {
    if (_cartItems.at(i).name() == _itemName) {
      _cartItems.erase(_cartItems.begin()+i);
      return;
    }
  }
  cout << "Item not found in cart. Nothing removed." << endl;
  // cout << endl;
}

void ShoppingCart::modifyItem(ItemToPurchase& _modifyItem) {
  ItemToPurchase _default;

  for (unsigned i = 0; i < _cartItems.size(); ++i) {

    if (_cartItems.at(i).name() == _modifyItem.name()) {

      if (_modifyItem.description() != _default.description()) {
        _cartItems.at(i).setDescription(_modifyItem.description());
      }
      if (_modifyItem.price() != _default.price()) {
        _cartItems.at(i).setPrice(_modifyItem.price());
      }
      if (_modifyItem.quantity() != _default.price()) {
        _cartItems.at(i).setQuantity(_modifyItem.quantity());
      }

      cout << endl;
      return;
    }
  }
  cout << "Item not found in cart. Nothing modified." << endl;
  cout << endl;
}

int ShoppingCart::numItemsInCart() const {
  int ItemCount = 0;

  for (unsigned i = 0; i < _cartItems.size(); ++i) {
    ItemCount += _cartItems.at(i).quantity();
  }

  return ItemCount;
}

int ShoppingCart::costOfCart() const {
  int TotalCost = 0;

  for (unsigned i = 0; i < _cartItems.size(); ++i) {
    TotalCost += (_cartItems.at(i).quantity() * _cartItems.at(i).price());
  }

  return TotalCost;
}

void ShoppingCart::printTotal() const {
  int ItemCount = numItemsInCart();
  cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
  cout << "Number of Items: " << ItemCount << endl;

  cout << endl;
    
  if (ItemCount == 0) {
    cout << "SHOPPING CART IS EMPTY" << endl;
  } else {
    for (unsigned i = 0; i < _cartItems.size(); ++i) {
      _cartItems.at(i).printItemCost();
    }
  }
  cout << endl;
    
  cout << "Total: $" << costOfCart() << endl;
  cout << endl;
}

void ShoppingCart::printDescriptions() const {
  cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
  cout << endl;

  cout << "Item Descriptions" << endl;
  for (unsigned i = 0; i < _cartItems.size(); ++i) {
    _cartItems.at(i).printItemDescription();
  }

  cout << endl;
}