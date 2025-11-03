// CSC 134
// M1LAB
// Kelevi Rakuita
// 2025-08-28

#include <iostream>
#include <iomanip> // Required for fixed and setprecision
using namespace std;

int main() {
    // This program will simulate an apple orchard.

    // The owner's name
    string name = "Kelevi Rakuita";

    // number of apples owned
    int apples = 100;

    // price per apple
    double pricePerApple = 0.25;

    // calculate the total price of the apples
    double totalPrice = apples * pricePerApple; // This will correctly be 25.00

    // print all the information about the orchard
    cout << "Welcome to " << name << "'s apple orchard." << endl;
    cout << "We have " << apples << " apples in stock" << endl;
    cout << "Apples are currently $" << fixed << setprecision(2)
         << pricePerApple << " each." << endl;

    // Final line, to print totalPrice
    // Added fixed and setprecision(2) here to format totalPrice
    cout << "If you want them all, that will be $" << fixed << setprecision(2) << totalPrice << endl;

    return 0;
}
