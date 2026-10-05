/*
 * main.cpp
 *
 * Includes the main() function for the sorting project. 
 *
 * This code is included in the build target "run-main"
*/

#include <iostream>
#include <cstddef>
#include <vector>

#include "sorter.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;

    vector<int> t = {7,8,29,-3,2828,0};
    sorter( t, 3 );

    for (unsigned int i = 0; i < t.size(); i++) {
        cout << t[i] << " ";
    }
    cout << endl;

    return 0;
}


