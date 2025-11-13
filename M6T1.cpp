/*
CSC 134
Kelevi Rakuita
11/13/2025
M6T1- Basic Arrays

*/
#include <iostream>
#include <string>
#include <iomanip>   // for setprecision
using namespace std;

// ----- Global constants -----
const int NUM_DAYS = 5;

// Array of day names to use in prompts and output
const string DAY_NAMES[NUM_DAYS] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
};

// ----- Function prototypes -----
void part1();   // Calculates total and average without using arrays
void part2();   // Uses an array and prints daily values + ASCII graph

int main()
{
    cout << "M6T1 - Basic Arrays (Car Counter)" << endl;
    cout << "This program has two parts:" << endl;
    cout << "  Part 1: No arrays (just a loop)." << endl;
    cout << "  Part 2: Uses an array and ASCII graph." << endl;
    cout << endl;

    // Run Part 1
    part1();

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    // Run Part 2
    part2();

    cout << endl;
    cout << "Program complete. Goodbye!" << endl;

    return 0;
}

// --------------------------------------------------------
// Part 1: Count cars Monday–Friday using a loop, NO arrays
// --------------------------------------------------------
void part1()
{
    cout << "PART 1: Total and average (no arrays)" << endl;
    cout << "(We only use a loop here, no array yet.)" << endl;
    cout << endl;

    int carsToday = 0;   // cars for the current day
    int totalCars = 0;   // running total for the week

    // Loop through each day, ask for input, add to total
    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << "Enter the number of cars that passed on "
             << DAY_NAMES[i] << ": ";
        cin >> carsToday;

        // Add today's cars to the total
        totalCars += carsToday;
    }

    // Calculate average as a double
    double average = static_cast<double>(totalCars) / NUM_DAYS;

    // Display results
    cout << endl;
    cout << "=== Part 1 Results ===" << endl;
    cout << "Total cars for the week: " << totalCars << endl;

    // Format average to 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Average cars per day:   " << average << endl;
}

// --------------------------------------------------------
// Part 2: Use an array to store each day's count and then
//         print total, average, and an ASCII bar chart.
// --------------------------------------------------------
void part2()
{
    cout << "PART 2: Using an array and ASCII graph" << endl;
    cout << "(Now we store each day's value in an array.)" << endl;
    cout << endl;

    int cars[NUM_DAYS];   // array to hold cars per day
    int totalCars = 0;    // running total for the week

    // Input loop: get value for each day and store in the array
    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << "Enter the number of cars that passed on "
             << DAY_NAMES[i] << ": ";
        cin >> cars[i];

        // Add to total as we go
        totalCars += cars[i];
    }

    // Calculate average as a double
    double average = static_cast<double>(totalCars) / NUM_DAYS;

    // Show daily values, total, and average
    cout << endl;
    cout << "=== Part 2 Results ===" << endl;
    cout << "Daily counts:" << endl;

    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << DAY_NAMES[i] << ": " << cars[i] << endl;
    }

    cout << endl;
    cout << "Total cars for the week: " << totalCars << endl;

    cout << fixed << setprecision(2);
    cout << "Average cars per day:   " << average << endl;

    // -----------------------------
    // ASCII bar chart of the week
    // -----------------------------
    cout << endl;
    cout << "ASCII Bar Chart" << endl;
    cout << "(Each * represents 10 cars.)" << endl;

    // For each day, print the day name and a row of stars
    for (int i = 0; i < NUM_DAYS; i++)
    {
        cout << DAY_NAMES[i] << " | ";

        // Number of stars = cars divided by 10
        int stars = cars[i] / 10;

        // If there were some cars but less than 10,
        // make sure we still show at least one star.
        if (cars[i] > 0 && stars == 0)
        {
            stars = 1;
        }

        // Print the stars
        for (int s = 0; s < stars; s++)
        {
            cout << '*';
        }

        cout << endl;
    }
}
