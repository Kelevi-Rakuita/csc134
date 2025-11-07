/*
CSC 134
Kelevi Rakuita
11/7/2025
Functions Practice

*/

#include <iostream>
using namespace std;

// Function prototype declarations
int square(int num);
void printAnswerLine(int num, int sq);

// Main function
int main() {
    cout << "Number Square";

    // Loop through numbers 1–10
    for (int i = 1; i <= 10; i++) {
        int result = square(i);            // Call value-returning function
        printAnswerLine(i, result);        // Call void function to print
    }

    return 0;
}

// Function definitions

// Value-returning function: calculates square
int square(int num) {
    return num * num;
}

// Void function: prints formatted line
void printAnswerLine(int num, int sq) {
    cout << num << "\t" << sq << endl;
}
