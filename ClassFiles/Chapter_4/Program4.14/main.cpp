#include <iostream>

using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

char printMenu(ShoppingCart& _cart);

int main() {

// cn = Customer Name
  cout << "Enter customer's name: " << endl;
  string cn;
  getline(cin, cn);

// cd = Current Date
  cout << "Enter today's date: " << endl;
  string cd;
  getline(cin, cd);

  cout << endl;
  cout << "Customer name: " << cn << endl;
  cout << "Today's date: " << cd << endl;
  cout << endl;

  ShoppingCart newCart(cn, cd);

// pmr = PrintMenu reuslt
  char pmr;
  do {
    pmr = printMenu(newCart);
    if (pmr == 'o') {
      cout << endl;
      cout << "OUTPUT SHOPPING CART" << endl;
      newCart.printTotal();
    } else if (pmr == 'i') {
      cout << endl;
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      newCart.printDescriptions();
    } else if (pmr == 'a') {
      cout << endl;
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name: " << endl;
      // itmn = item name
      string itmn;
      getline(cin, itmn);
      cout << "Enter the item description: " << endl;
      // itmd = item description
      string itmd;
      getline(cin, itmd);
      cout << "Enter the item price: " << endl;
      // itmp = item price
      int itmp = 0;
      cin >> itmp;
      cin.ignore();
      cout << "Enter the item quantity: " << endl;
      // itmq = item quantity
      int itmq = 0;
      cin >> itmq;
      cin.ignore();

      ItemToPurchase addedItem(itmn, itmd, itmp, itmq);
      newCart.addItem(addedItem);

      cout << endl;
    } else if (pmr == 'd') {
      cout << endl;
      cout << "REMOVE ITEM FROM CART" << endl
           << "Enter name of item to remove: " << endl;
      // rin = remove item name
      string rin;
      getline(cin, rin);
      newCart.removeItem(rin);
      
      cout << endl;
    } else if (pmr == 'c') {
      cout << endl;
      cout << "CHANGE ITEM QUANTITY" << endl;

      cout << "Enter the item name: " << endl;
      // min = modify item name
      string min;
      getline(cin, min);
      cout << "Enter the new quantity: " << endl;
      // miq modify item quantity
      int miq = 0;
      cin >> miq;
      cin.ignore();

      ItemToPurchase _modifyItem(min, "name", 0, miq);
      newCart.modifyItem(_modifyItem);
    }
  } while(pmr != 'q');

  return 0;
}

char printMenu(ShoppingCart& _cart) {
  cout << "MENU" << endl;
  cout 
<< "a - Add item to cart" << endl
<< "d - Remove item from cart" << endl
<< "c - Change item quantity" << endl
<< "i - Output items' descriptions" << endl
<< "o - Output shopping cart" << endl
<< "q - Quit" << endl  << endl;

  char ic;
  do {
    cout << "Choose an option: " << endl;
    cin >> ic;
    cin.ignore();
  } while (
    ic != 'a'&&
    ic != 'd' &&
    ic != 'c' &&
    ic != 'i' &&
    ic != 'o' &&
    ic != 'q'
    );

  // cout << endl;

  return ic;
}