#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double mealPrice = 5.99;
    const double taxRate = 0.08;   // 8%

    double taxAmount;
    double total;

    taxAmount = mealPrice * taxRate;
    total = mealPrice + taxAmount;

    cout << fixed << setprecision(2);
    cout << "=== Simple Receipt ===" << endl;
    cout << "Price before tax: $" << mealPrice << endl;
    cout << "Tax (8%):        $" << taxAmount << endl;
    cout << "Total:           $" << total << endl;

    return 0;
}
