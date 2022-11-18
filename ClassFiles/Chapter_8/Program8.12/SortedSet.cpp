

using namespace std;

#include "SortedSet.h"

// ---------------------------------------------------------
// ---------- Constructors & Destructors -------------------
// ---------------------------------------------------------

SortedSet::SortedSet()
    : IntList() {
  // Calls the default inline constructor to set
  // head and tail to nullptr.
}

SortedSet::SortedSet(const SortedSet& cpy)
    : IntList(cpy) {
  // Invokes the copy constructor of IntList
}

SortedSet::SortedSet(const IntList& cpy)
    : IntList(cpy) {
  // Invokes the copy constructor of IntList,
  // then checks for duplicates and sorts.
  remove_duplicates();
  selection_sort();
}

SortedSet::~SortedSet() {
  // This method automatically invokes the intlist
  // destructor.
}

// ---------------------------------------------------------
// ------------------ Accessors ----------------------------
// ---------------------------------------------------------

bool SortedSet::in(int value) const {
  IntNode* CurrentNode = this->head;

  // Traverse the linked sorted list.
  // Because it is sorted, we can end the search once the value
  // becomes greater than the target value.
  while (CurrentNode != nullptr && CurrentNode->value <= value) {
    if (CurrentNode->value == value) {
      return true;
    }
    CurrentNode = CurrentNode->next;
  }
  return false;
}

SortedSet& SortedSet::operator|(const SortedSet& rhs) const {
  SortedSet* ResultSet = new SortedSet(*this);
  //// DEBUG CODE
  // cout << *ResultSet << " is the starting value of resultSet" << endl;

  IntNode* CurrentNode = rhs.head;
  while (CurrentNode != nullptr) {
    ResultSet->add(CurrentNode->value);
    CurrentNode = CurrentNode->next;
  }

  // DEBUG CODE
  // cout << "Head: " << ResultSet->head->value << endl;
  // cout << "Tail: " << ResultSet->tail->value << endl;

  return *ResultSet;
}

SortedSet& SortedSet::operator&(const SortedSet& rhs) const {
  SortedSet* ResultSet = new SortedSet();

  // We will use a two pointer method to simultaneously
  // traverse both lists.

  IntNode* ThisPointer = this->head;
  IntNode* RightPointer = rhs.head;

  if (this->empty() || rhs.empty()) {
    return *ResultSet;
  }

  while (ThisPointer != nullptr) {
    if (ThisPointer->value == RightPointer->value) {
      // Add the value if the two pointers have equal values.
      ResultSet->add(ThisPointer->value);
      ThisPointer = ThisPointer->next;
      RightPointer = RightPointer->next;
    } else if (ThisPointer->value < RightPointer->value) {
      // Stall the greater value, in this case, stall RP.
      ThisPointer = ThisPointer->next;
    } else if (ThisPointer->value > RightPointer->value) {
      // Stall the greater value, in this case, stall TP.
      RightPointer = RightPointer->next;
    }
  }

  // DEBUG CODE
  // cout << "Head: " << ResultSet->head->value << endl;
  // cout << "Tail: " << ResultSet->tail->value << endl;

  return *ResultSet;
}

// ---------------------------------------------------------
// ------------------ Mutators ----------------------------
// ---------------------------------------------------------
void SortedSet::add(int value) {
  insert_ordered(value);
}

void SortedSet::push_front(int value) {
  add(value);
}

void SortedSet::push_back(int value) {
  add(value);
}

void SortedSet::insert_ordered(int value) {
  if (!in(value)) {
    IntList::insert_ordered(value);
  }
}

SortedSet& SortedSet::operator|=(const SortedSet& rhs) {
  // Traverse rhs and add the values.
  IntNode* CurrentNode = rhs.head;
  while (CurrentNode != nullptr) {
    add(CurrentNode->value);
    CurrentNode = CurrentNode->next;
  }

  // Return the union.
  return *this | rhs;
}

SortedSet& SortedSet::operator&=(const SortedSet& rhs) {

  SortedSet* ResultSet = new SortedSet();
  *ResultSet = (*this)&rhs;

  // Clear the set.
  this->clear();

  // Copy the values of the result set into this.
  IntNode* CurrentNode = ResultSet->head;
  while (CurrentNode != nullptr) {
    add(CurrentNode->value);
    CurrentNode = CurrentNode->next;
  }

  return *ResultSet;

}