/* CSC 134
 M3HW1 - Bronze
 Kelevi Rakuita
10/09/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    // ---------------- Question 1 ----------------
    cout << "Question 1 - Simple Chatbot" << endl;
    cout << "---------------------------------" << endl;

    string answer;
    cout << "Hello, I'm a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no: ";
    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        cout << "That's great! I'm sure we'll get along." << endl;
    } else if (answer == "no" || answer == "No") {
        cout << "Well, maybe you'll learn to like me later." << endl;
    } else {
        cout << "If you're not sure... that's OK." << endl;
    }

    cout << endl;

    // ---------------- Question 4 ----------------
    cout << "Question 4 - Math Practice" << endl;
    cout << "---------------------------------" << endl;

    srand(time(0));  // seed random number generator
    int num1 = rand() % 10;  // random 0–9
    int num2 = rand() % 10;
    int userAnswer;

    cout << "What is " << num1 << " + " << num2 << "? ";
    cin >> userAnswer;

    if (userAnswer == num1 + num2) {
        cout << "Correct! Great job!" << endl;
    } else {
        cout << "Incorrect. The correct answer was " << num1 + num2 << "." << endl;
    }

    cout << endl;
    cout << "End of M3HW1 Bronze assignment." << endl;
    return 0;
}
