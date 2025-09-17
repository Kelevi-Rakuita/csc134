/*
CSC 134
Kelevi Rakuita
M2HW1 - Case Studies with crates
9/8/2025
*/

#include <iostream>
#include <iomanip>   // for fixed and setprecision
using namespace std;

int main() {
    // set up the variables
    double length, width, height, volume; // size of crate
    double cost_to_make, charge_to_customer; // pricing
    double profit;
    const double COST_PER_CUBIC_FOOT = 0.3; // relates to cost
    const double CHARGE_PER_CUBIC_FOOT = 0.52; // relates to charge
    
    // Get the crate info
    cout << "Welcome to the crate program.\n";
    cout << "Crate Length: ";
    cin >> length;
    cout << "Crate Width: ";
    cin >> width;
    cout << "Crate Height: ";
    cin >> height;

    // Calculate the cost and prices
    volume = length * width * height;
    cost_to_make = volume * COST_PER_CUBIC_FOOT;
    charge_to_customer = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge_to_customer - cost_to_make;

    // Display the results
    cout << fixed << setprecision(2); // money format
    cout << "\n====================================\n";
    cout << "Crate Volume      : " << volume << " cubic feet\n";
    cout << "Customer Price    : $" << charge_to_customer << endl;
    cout << "Cost to Build     : $" << cost_to_make << endl;
    cout << "Profit            : $" << profit << endl;
    cout << "====================================\n";

    return 0;
}

