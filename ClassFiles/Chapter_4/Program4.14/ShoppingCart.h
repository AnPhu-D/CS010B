// Include libraries
#include <vector>

using namespace std;

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"

class ShoppingCart {
  public:
// Declare constructor (Default)
  ShoppingCart();

// Parameterized constructor
  ShoppingCart(const string& _customerName, const string& _currentDate);


// Declare public accessors
  string customerName() const;
  string date() const;

// Declare mutator
  void addItem(const ItemToPurchase& _newItem);
  void removeItem(const string& _itemName);
  void modifyItem(ItemToPurchase& _modifyItem);

  int numItemsInCart() const;
  int costOfCart() const;

  void printTotal() const;
  void printDescriptions() const;

  private:
  string _customerName = "none";
  string _currentDate = "January 1, 2016";
  vector <ItemToPurchase> _cartItems;

};

#endif