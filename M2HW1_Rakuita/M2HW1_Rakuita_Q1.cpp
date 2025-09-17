/*
CSC 134
M2HW1 - Bronze
Kelevi Rakuita
9/15/2025
*/
#include <iostream>
#include <string>    // Required to use the string class
#include <iomanip>   // Required for output formatting (setprecision, fixed)
#include <cstdlib>   // Required for random number generation (rand, srand)
#include <ctime>     // Required to seed the random number generator (time)


using namespace std;   // <-- allows us to drop "std::"

int main() {
    // --- Variable Declaration ---
    string name;
    double startBalance, deposit, withdrawal, finalBalance;
    int accountNumber;

    cout << "Welcome to the Digital Bank! 🏦\n\n";

    // --- User Input ---
    cout << "Please enter the name for the account: ";
    getline(cin, name);

    cout << "Enter your starting account balance: $";
    cin >> startBalance;

    cout << "Enter the amount to deposit: $";
    cin >> deposit;

    cout << "Enter the amount to withdraw: $";
    cin >> withdrawal;

    // --- Data Processing ---
    srand(time(0)); 
    accountNumber = rand() % 900000 + 100000; // random 6-digit account number

    finalBalance = startBalance + deposit - withdrawal;

    // --- Display Output ---
    cout << "\n========================================\n";
    cout << "         Account Summary\n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    cout << "Account Holder:   " << name << endl;
    cout << "Account Number:   " << accountNumber << endl;
    cout << "Final Balance:    $" << finalBalance << endl;
    
    cout << "========================================\n";

    return 0;
}