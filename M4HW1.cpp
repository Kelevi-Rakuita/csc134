/*
CSC 134
M4HW1- (Bronze) 5 Multiplication table
Kelevi Rakuita
10/30/2025

*/

#include <iostream>
using namespace std;

int main() {
    int number = 5;     // the times table we’re printing
    int i = 1;          // starting multiplier

    cout << "Multiplication Table for " << number << ":\n" << endl;

    // while loop to print 5 times table up to 12
    while (i <= 12) {
        cout << number << " times " << i << " is " << number * i << "." << endl;
        i++;  // increment counter
    }

    return 0;
}
