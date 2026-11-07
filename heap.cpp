// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  int size = end - start;
  vdata.assign(start, end);
  for (int i = size / 2 - 1; i >= 0; i--) {
    int parent = i;
    while (true) {
      int left = 2 * parent + 1;
      int right = 2 * parent + 2;
      int smallest = parent;
      if (left < size && vdata[left] < vdata[smallest]) smallest = left;
      if (right < size && vdata[right] < vdata[smallest]) smallest = right;
      if (smallest == parent) break;
      std::swap(vdata[parent], vdata[smallest]);
      parent = smallest;
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size() - 1;
  while (i > 0 && vdata[i] < vdata[(i - 1) / 2]) {
    std::swap(vdata[i], vdata[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) return;
  vdata[0] = vdata.back();
  vdata.pop_back();
  int parent = 0;
  int size = vdata.size();
  while (true) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int smallest = parent;
    if (left < size && vdata[left] < vdata[smallest]) smallest = left;
    if (right < size && vdata[right] < vdata[smallest]) smallest = right;
    if (smallest == parent) break;
    std::swap(vdata[parent], vdata[smallest]);
    parent = smallest;
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    