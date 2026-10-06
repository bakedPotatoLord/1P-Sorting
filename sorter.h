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
  using u32 = std::size_t;

  u32 size = items.size();

  // Base cases
  if (k < 2 || size <= 1) {
    return;
  }

  // Optimize tree leaves: avoid creating empty subsets when vector size < k
  if (size < k) {
    k = size;
  }

  // Base case: small array sorting
  if (size == 2) {
    if (items[0] > items[1]) {
      std::swap(items[0], items[1]);
    }
    return;
  }

  u32 subsetSize = size / k;
  u32 remainder = size % k;

  std::vector<std::vector<T>> subsets(k);
  auto it = items.begin();

  // Divide items into k subsets using range constructor
  for (u32 i = 0; i < k; i++) {
    // Distribute remainder elements evenly across the first few subsets
    u32 currentSubsetSize = subsetSize + (i < remainder ? 1 : 0);
    auto next_it = it + currentSubsetSize;
    
    subsets[i] = std::vector<T>(it, next_it);
    it = next_it;
  }

  // Recursive call on each subarray
  for (auto& subset : subsets) {
    sorter(subset, k);
  }

  // Track the front index of each subset without doing expensive erase/pop operations
  std::vector<u32> indices(k, 0);

  // Resize output vector once upfront to avoid push_back overhead
  items.resize(size);

  // Linear-scan k-way merge phase
  for (u32 out_idx = 0; out_idx < size; out_idx++) {
    u32 min_subset_idx = 0;
    bool found = false;

    // Scan all non-exhausted subsets to find the minimum element
    for (u32 i = 0; i < k; i++) {
      if (indices[i] < subsets[i].size()) {
        if (!found || subsets[i][indices[i]] < subsets[min_subset_idx][indices[min_subset_idx]]) {
          min_subset_idx = i;
          found = true;
        }
      }
    }

    // Place min element directly into pre-allocated slot and advance subset's index
    items[out_idx] = subsets[min_subset_idx][indices[min_subset_idx]];
    indices[min_subset_idx]++;
  }
}

#endif
