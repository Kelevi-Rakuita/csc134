/*
CSC 134
Rakuita
M2BONUS
9/28/2025

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "M2 BONUS PROBLEMS" << endl;
    cout << "=================" << endl << endl;
    
    // Problem 1: Rectangle Area
    cout << "Problem 1: Rectangle Area Calculation" << endl;
    cout << "-------------------------------------" << endl;
    
    int height = 8;
    int width = 10;
    int area = height * width;
    
    cout << "Rectangle dimensions: " << height << " x " << width << endl;
    cout << "Area = length x width = " << height << " x " << width << " = " << area << " square units" << endl;
    cout << endl;
    
    // Problem 2: Sales Tax Calculation
    cout << "Problem 2: Sales Tax Calculation" << endl;
    cout << "--------------------------------" << endl;
    
    double productPrice = 99.99;
    double salesTaxRate = 0.08; // 8% as decimal
    double salesTaxAmount = productPrice * salesTaxRate;
    double finalCost = productPrice + salesTaxAmount;
    
    cout << fixed << setprecision(2); // Format for currency display
    cout << "Product price: $" << productPrice << endl;
    cout << "Sales tax (8%): $" << salesTaxAmount << endl;
    cout << "Final cost (including tax): $" << finalCost << endl;
    cout << endl;
    
    // Problem 3: Pizza Area Calculation
    cout << "Problem 3: Pizza Area Calculation" << endl;
    cout << "---------------------------------" << endl;
    
    double diameter = 12.0;
    double radius = diameter / 2.0;
    const double PI = 3.14159;
    double pizzaArea = PI * radius * radius; // Area = π * r²
    
    cout << "Pizza diameter: " << diameter << " inches" << endl;
    cout << "Pizza radius: " << radius << " inches" << endl;
    cout << "Pizza area = π × r² = " << PI << " × " << radius << "² = " << pizzaArea << " square inches" << endl;
    cout << endl;
    
    // Problem 4: Pizza Slice Area
    cout << "Problem 4: Pizza Slice Area" << endl;
    cout << "---------------------------" << endl;
    
    int numberOfSlices = 8;
    double sliceArea = pizzaArea / numberOfSlices;
    
    cout << "Number of pizza slices: " << numberOfSlices << endl;
    cout << "Area per slice = " << pizzaArea << " ÷ " << numberOfSlices << " = " << sliceArea << " square inches per slice" << endl;
    cout << endl;
    
    cout << "All problems completed successfully!" << endl;
    
    return 0;
}