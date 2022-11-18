// Include libraries

using namespace std;

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H


class ItemToPurchase {
  public:
// Declare constructor (Default)
  ItemToPurchase();

// Parameterized Constructor
  ItemToPurchase(const string& name, const string&description, const int& price, const int& quantity);


// Declare public accessors/mutators
  void setName(const string& _name);
  string name() const;

  void setDescription(const string& _description);
  string description() const;

  void setPrice(const int& _price);
  int price() const;

  void setQuantity(const int& _quantity);
  int quantity() const;

  // Other member functions
  // Outputs the item name followed by the quantity, price, and subtotal
  // Ex: Bottled Water 10 @ $1 = $10
  void printItemCost() const;

  // Outputs the item name and description
  // Ex: Bottled Water: Deer Park, 12 oz.
  void printItemDescription() const;

  private:

  // Private helper function used to caluclate subtotal
  int subtotal() const;

  string _name = "none";
  string _description = "none";
  int _price = 0;
  int _quantity = 0;

};

#endif