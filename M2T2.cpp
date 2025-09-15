/*
CSC 134
M2T2
Kelevi Rakuita
9/15/2025
purpose: Generate a "good receipt"
*/

#include <iostream>
#include <iomanip>
using namespace std;

#include <iostream>
#include <iomanip> // Required for setprecision and fixed

int main() {
    // Use the standard namespace for cout, endl, etc.
    using namespace std;

    // Declare variables
    const double mealPrice = 5.99;
    const double taxRate = 0.08;   // This is 8/100 or 8%
    double tax_amount;             // How much tax in $
    double total;

    // --- Calculations ---
    // Calculate the tax amount by multiplying the meal price by the tax rate
    tax_amount = mealPrice * taxRate;
    
    // Calculate the total by adding the tax amount to the meal price
    total = mealPrice + tax_amount;

    // --- Output ---
    // Print the results, formatted to two decimal places
    cout << fixed << setprecision(2);
    cout << "=== Shop receipt ===" << endl;
    cout << "Price before tax: $" << mealPrice << endl;
    cout << "Tax (8%):         $" << tax_amount << endl;
    cout << "Total:            $" << total << endl;

    return 0;
}
