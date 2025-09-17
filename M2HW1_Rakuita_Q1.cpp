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

int main() {
    // --- Variable Declaration ---
    std::string name;
    double startBalance, deposit, withdrawal, finalBalance;
    int accountNumber;

    std::cout << "Welcome to the Digital Bank! 🏦\n\n";

    // --- User Input ---
    // Prompt for the user's full name
    std::cout << "Please enter the name for the account: ";
    // getline is used to read the entire line, including spaces
    std::getline(std::cin, name);

    // Prompt for financial details
    std::cout << "Enter your starting account balance: $";
    std::cin >> startBalance;

    std::cout << "Enter the amount to deposit: $";
    std::cin >> deposit;

    std::cout << "Enter the amount to withdraw: $";
    std::cin >> withdrawal;

    // --- Data Processing ---
    // Seed the random number generator using the current time
    srand(time(0)); 
    // Generate a random 6-digit account number (between 100000 and 999999)
    accountNumber = rand() % 900000 + 100000;

    // Calculate the final balance
    finalBalance = startBalance + deposit - withdrawal;

    // --- Display Output ---
    std::cout << "\n========================================\n";
    std::cout << "         Account Summary\n";
    std::cout << "========================================\n";

    // Set the output format for money to show two decimal places
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Account Holder:   " << name << std::endl;
    std::cout << "Account Number:   " << accountNumber << std::endl;
    std::cout << "Final Balance:    $" << finalBalance << std::endl;
    
    std::cout << "========================================\n";

    return 0;
}