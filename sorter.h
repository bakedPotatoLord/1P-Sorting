/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>
#include <utility>
#include <iostream>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 *
 * For more details, see the commentary at the top of
 *   tests/header-sans-using-namespace.h
 * in this project repo.
 */

template <class T>
void sorter(std::vector<T> &items, std::size_t k) {  

  using namespace std;
  using u32 = u_int32_t;

  // Base cases
  if (k < 2 || items.size() <= 1) {
    return;
  }

  u32 size = items.size();

  if (size == 2) {
    if (items[0] > items[1]) {
      std::swap(items[0], items[1]);
    }
    return;
  }

  // Calculate subset sizes
  u32 subsetSize = size / k;
  if (subsetSize == 0) {
    // If vector elements < k,
    subsetSize = 1;
    k = size; 
  }

  vector<vector<T>> subsets(k);
  auto it = items.begin();

  for (u32 i = 0; i < k; i++) {
    // include all elements (expecially remainders)
    auto next_it = (i == k - 1) ? items.end() : it + subsetSize;
    subsets[i] = vector<T>(it, next_it);
    it = next_it;
  }

  //sort sub-arrays
  for (auto& subset : subsets) {
    sorter(subset, k);
  }

  items.clear();

  //3-way zipper Merge phase
  for (u32 count = 0; count < size; count++) {
    u32 minIndex = 0;
    bool gotFirst = false;

    for (u32 i = 0; i < k; i++) {
      if (!subsets[i].empty()) {
        if (!gotFirst || subsets[i].front() < subsets[minIndex].front()) {
          gotFirst = true;
          minIndex = i;
        }
      }
    }

    if (gotFirst) {
      items.push_back(subsets[minIndex].front());
      subsets[minIndex].erase(subsets[minIndex].begin());
    }
  }
}
#endif
