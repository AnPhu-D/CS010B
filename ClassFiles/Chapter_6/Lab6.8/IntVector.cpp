#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.h"

void IntVector::expand() {
  // Allocate a new array of double the _capacity.
  int* newData = new int[(_capacity * 2 == 0) ? 1 : _capacity * 2];

  for (unsigned i = 0; i < _capacity; ++i) {
    newData[i] = _data[i];
  }

  _capacity = (_capacity * 2 == 0) ? 1 : _capacity * 2;
  delete[] _data;
  _data = newData;
}

void IntVector::expand(unsigned amount) {
  // Allocate a new array of _capacity + amount.
  int* newData = new int[_capacity + amount];

  for (unsigned i = 0; i < _capacity; ++i) {
    newData[i] = _data[i];
  }

  _capacity += amount;
  delete[] _data;
  _data = newData;
}

IntVector::IntVector(unsigned capacity, int value) {
  // Set member vars
  _capacity = capacity;
  _size = capacity;

  // Allocate heap for new array.
  _data = (_capacity == 0) ? nullptr : new int[_capacity];

  // Initialize all values to value.
  for (unsigned i = 0; i < _capacity; ++i) {
    _data[i] = value;
  }
}

IntVector::~IntVector() {
  // Delete any vars in heap.
  delete[] _data;
}

unsigned IntVector::size() const {
  return _size;
}

unsigned IntVector::capacity() const {
  return _capacity;
}

bool IntVector::empty() const {
  return (_size == 0);
}

const int& IntVector::at(unsigned index) const {
  if (index >= _size) {
    throw out_of_range("IntVector::at_range_check");
  }

  return _data[index];
}

int& IntVector::at(unsigned index) {
  if (index >= _size) {
    throw out_of_range("IntVector::at_range_check");
  }

  return _data[index];
}

void IntVector::insert(unsigned index, int value) {
  // cout << "Called insert with " << index << ", " << value << " on array with s,c of " << _size << ", " << _capacity << endl;

  // Check range
  if (index >= _capacity+1) {
    throw out_of_range("IntVector::insert_range_check");
  }

  // Double size if overflow
  if (_size == _capacity) {
    expand();
  }

  for (unsigned i = 0; i < _size - index; ++i) {
    _data[_size - i] = _data[_size - i - 1];
  }

  _data[index] = value;
  _size += 1;
}

void IntVector::erase(unsigned index) {
  // Check range

  if (index >= _size) {
    throw out_of_range("IntVector::erase_range_check");
  }

  for (unsigned i = index; i < _size; ++i) {
    _data[i] = _data[i + 1];
  }

  _size -= 1;
}

void IntVector::push_back(int value) {
  // Double size if overflow
  if (_size >= _capacity) {
    expand();
  }

  _data[_size] = value;
  _size += 1;
}

void IntVector::pop_back() {
  _size -= 1;
}

void IntVector::clear() {
  _size = 0;
}

void IntVector::resize(unsigned size, int value) {
  // Check for edge cases
  if (size < _size) {
    _size = size;
    return;
  }

  // Handle overflow
  if (size > _capacity * 2) {
    expand(size - _capacity);
  } else if (size > _capacity) {
    expand();
  }

  unsigned oldSize = _size;
  for (unsigned i = 0; i < size - oldSize; ++i) {
    push_back(value);
  }
}

void IntVector::reserve(unsigned n) {
  if (n > _capacity) {
    expand(n - _capacity);
  }
}

void IntVector::assign(unsigned n, int value) {
  if (n > _capacity * 2) {
    expand(n - _capacity);
  } else if (n > _capacity) {
    expand();
  }

  for (unsigned i = 0; i < _capacity; ++i) {
    _data[i] = value;
  }

  _size = n;
}

const int& IntVector::front() const {
  return _data[0];
}

int& IntVector::front() {
  return _data[0];
}

const int& IntVector::back() const {
  return _data[_size - 1];
}

int& IntVector::back() {
  return _data[_size - 1];
}