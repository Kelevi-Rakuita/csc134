/* CSC 134
M4T1 - While Loops
Kelevi Rakuita
 3/10/2025
 */

#include <iostream>
#include <iomanip>  // for formatting table output
using namespace std;

int main()
{
    // -------------------------------
    // Part 1: Say "Hello" five times
    // -------------------------------
    cout << "Part 1: Saying Hello five times\n";
    int count = 1;              // initialize counter

    while (count <= 5) {        // condition to repeat 5 times
        cout << "Hello number " << count << endl;
        count++;                // increment to avoid infinite loop
    }

    cout << endl;

    // ------------------------------------------------------
    // Part 2: Display a table of numbers and their squares
    // ------------------------------------------------------
    cout << "Part 2: Number and Square Table\n";
    cout << "Number\tSquare\n";
    cout << "-----------------\n";

    int number = 1;             // starting number
    while (number <= 10) {      // repeat for numbers 1 through 10
        cout << number << "\t" << (number * number) << endl;
        number++;
    }

    cout << endl;

    return 0;
}
