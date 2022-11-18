

using namespace std;

#include "IntList.h"

IntList::IntList() {
  head = nullptr;
  tail = nullptr;
}

IntList::~IntList() {
  IntNode* current = head;
  IntNode* previous = current;

  while (current != nullptr) {
    previous = current;
    current = current->next;
    // Cleans up the iterated past node.
    delete previous;
  }
}

void IntList::push_front(int val) {
  IntNode* NewNode = new IntNode(val);

  // Sets the tail if the list is empty.
  if (empty()) {
    tail = NewNode;
  }

  NewNode->next = head;
  head = NewNode;
}

void IntList::pop_front() {
  if (empty() == true) {
    cout << "Empty" << endl;
    return;
  }

  IntNode* successorNode = head->next;

  // Cleans up the deleted node.
  delete head;
  head = successorNode;

  // Checks for dangling tail pointer.
  if (empty()) {
    tail = nullptr;
  }
}

bool IntList::empty() const {
  return (head == nullptr);
}

const int& IntList::front() const {
  return head->value;
}

const int& IntList::back() const {
  return tail->value;
}

ostream& operator<<(ostream& o, const IntList& il) {

  // Prevents segfault
  if (il.empty()) {
    return o;
  }

  IntNode* CurrentNode = il.head;

  o << CurrentNode->value;
  CurrentNode = CurrentNode->next;

  while (CurrentNode != nullptr) {
    o << " " << CurrentNode->value;
    CurrentNode = CurrentNode->next;
  }

  return o;
}