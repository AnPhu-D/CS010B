

using namespace std;

#include "IntList.h"

IntList::IntList() {
  head = nullptr;
  tail = nullptr;
}

IntList::~IntList() {
  IntNode* current = head;
  IntNode* previous = current;

  // Iterate over the list
  while (current != nullptr) {
    // Step forwards once while keeping a reference to the previous.
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

  // Add to the front by setting head as next.
  NewNode->next = head;

  // Set the head because we are adding to the front.
  head = NewNode;
}

void IntList::push_back(int value) {
  IntNode* NewNode = new IntNode(value);

  // Simply set head and tail if empty.
  if (empty()) {
    head = NewNode;
    tail = NewNode;
    return;
  }

  // Add to the end by setting tail's next.
  tail->next = NewNode;

  // Set the tail because we are adding to the back.
  tail = NewNode;
}

void IntList::pop_front() {
  // Do not continue if the list is empty.
  if (empty() == true) {
    return;
  }

  // Gets the successor node.
  IntNode* successorNode = head->next;

  // Cleans up the deleted node.
  delete head;

  // Set the new head.
  head = successorNode;

  // Checks for dangling tail pointer.
  if (empty()) {
    tail = nullptr;
  }
}

void IntList::clear() {
  IntNode* current = head;
  IntNode* previous = current;

  // Iterate over the list
  while (current != nullptr) {
    // Step forwards once while keeping a reference to the previous.
    previous = current;
    current = current->next;

    // Cleans up the iterated past node.
    delete previous;
    previous = nullptr;
  }

  head = nullptr;
  tail = nullptr;
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

// ----------------------------------------------------

IntList::IntList(const IntList& cpy) {

  if (cpy.empty()) {
    head = nullptr;
    tail = nullptr;
    return;
  }

  // First, allocate a new head node.
  IntNode* CurrentNode = cpy.head;
  head = new IntNode(CurrentNode->value);
  tail = head;

  // Declare another iterator, for the new list.
  IntNode* TrailingNode = head;

  CurrentNode = CurrentNode->next;

  while (CurrentNode != nullptr) {
    IntNode* NewNode = new IntNode(CurrentNode->value);

    TrailingNode->next = NewNode;
    tail = NewNode;

    // Traverse cpy list by 1.
    CurrentNode = CurrentNode->next;
    // Traverse new list by 1.
    TrailingNode = TrailingNode->next;
  }
}

IntList& IntList::operator=(const IntList& rhs) {
  if (rhs.empty()) {
    head = nullptr;
    tail = nullptr;
    return *this;
  } else if (this == &rhs) {
    return *this;
  }

  // Do I need to deallocate / delete the initial value in this?
  clear();

  // First, allocate a new head node.
  IntNode* CurrentNode = rhs.head;
  head = new IntNode(CurrentNode->value);
  tail = head;

  // Declare another iterator, for the new list.
  IntNode* TrailingNode = head;

  CurrentNode = CurrentNode->next;

  while (CurrentNode != nullptr) {
    IntNode* NewNode = new IntNode(CurrentNode->value);

    TrailingNode->next = NewNode;
    tail = NewNode;

    // Traverse rhs list by 1.
    CurrentNode = CurrentNode->next;
    // Traverse new list by 1.
    TrailingNode = TrailingNode->next;
  }

  return *this;
}

void IntList::selection_sort() {
  IntNode* TargetNode = head;
  while (TargetNode != nullptr) {
    IntNode* IteratorNode = TargetNode;
    IntNode* SmallestNode = IteratorNode;
    while (IteratorNode != nullptr) {
      if (IteratorNode->value < SmallestNode->value) {
        SmallestNode = IteratorNode;
      }

      // Traverse nested loop by 1.
      IteratorNode = IteratorNode->next;
    }

    int TargetValue = TargetNode->value;
    TargetNode->value = SmallestNode->value;
    SmallestNode->value = TargetValue;

    // Traverse main loop by 1.
    TargetNode = TargetNode->next;
  }
}

void IntList::insert_ordered(int value) {
  // Concept is: Insert BEFORE the FIRST one that you are less than
  IntNode* CurrentNode = head;

  // Iterate over the entire intlist
  while (CurrentNode != nullptr && value >= CurrentNode->value) {
    // If the end is reached, add to the end.
    if (CurrentNode->next == nullptr) {
      push_back(value);
      return;
    } else if (value < CurrentNode->next->value) {
      IntNode* NewNode = new IntNode(value);
      NewNode->next = CurrentNode->next;
      CurrentNode->next = NewNode;
      return;
    }

    // Traverse by 1.
    CurrentNode = CurrentNode->next;
  }

  push_front(value);
}

void IntList::remove_duplicates() {
  IntNode* TargetNode = head;
  while (TargetNode != nullptr) {
    IntNode* IteratorNode = TargetNode;

    while (IteratorNode != nullptr) {
      if (IteratorNode->next && IteratorNode->next->value == TargetNode->value) {
        IntNode* SuccessorNode = IteratorNode->next->next;
        delete IteratorNode->next;
        IteratorNode->next = SuccessorNode;

        if (IteratorNode->next == nullptr) {
          tail = IteratorNode;
        }

        continue;
      }

      IteratorNode = IteratorNode->next;
    }

    TargetNode = TargetNode->next;
  }
}