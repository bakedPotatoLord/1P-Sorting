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
	#define u32 u_int32_t 

	if(k < 2){
		return;
	}

	u32 size = items.size();

	// std::cout << "size: " << size << endl;

	//handle base case
	if(size == 2){
		
		
		if(items[0] > items[1]){
			//get the lesser on the LHS
			std::swap(items[0], items[1]);
		}
		return;
	}else if(size == 1){
		//it's fine as-is
		return;
	}

	u32 subsetSize = size / 3;


	vector<T> [] subsets = vector<T>[5];
	// std::cout << midthird << " " << lastthird << endl;

	// vector<T> items1(items.begin(), items.begin()+ midthird);
	// vector<T> items2(items.begin()+ midthird, items.begin() + lastthird);
	// vector<T> items3(items.begin() + lastthird, items.end());

	// sorter(items1, k);
	// sorter(items2, k);
	// sorter(items3, k);

	//zipper merge

	items.clear();

	// for( const auto& item: items1){
	// 	std::cout << item << " ";
	// }	
	// std::cout << endl;
	// for( const auto& item: items2){
	// 	std::cout << item << " ";
	// }	
	// std::cout << endl;
	// for( const auto& item: items3){
	// 	std::cout << item << " ";
	// }	
	// std::cout << endl;

	for(u32 i =0u; i< k;i++){
		//iterate over all sorted lists
		//find max entry at end

	}

}
#endif
