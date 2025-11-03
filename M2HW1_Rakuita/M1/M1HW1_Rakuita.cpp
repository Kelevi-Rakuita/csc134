// CSC 134
// M1HW1 (Movie Talk)
// Kelevi Rakuita
// 2025-08-28

#include <iostream>
#include <iomanip> // Required for fixed and setprecision
#include <string>  // Required for string variable type
using namespace std;

int main() {
    // This program will talk about a movie.

    // Variables to store movie information
    string movieName = "Inception";
    int releaseYear = 2010;
    double boxOfficeGross = 828300000.00; // Worldwide gross in dollars

    // Output a brief summary of the movie
    cout << "--- Movie Talk: " << movieName << " ---" << endl << endl;

    cout << "The movie \"" << movieName << "\" came out in " << releaseYear << ", and had a worldwide gross of around $"
         << fixed << setprecision(2) << boxOfficeGross << "." << endl << endl;

    // Output some interesting facts and quotes from the movie (4-5 lines)
    cout << "Interesting Facts & Quotes:" << endl;
    cout << "---------------------------" << endl;
    cout << "Directed by Christopher Nolan, it's known for its mind-bending plot." << endl;
    cout << "A memorable quote from the film is: \"Dreams feel real while we're in them. It's only when we wake up that we realize something was actually strange.\"" << endl;
    cout << "Another iconic line is: \"You're waiting for a train. A train that will take you far away.\"" << endl;
    cout << "The concept of 'shared dreaming' is central to the story." << endl;
    cout << "The film won four Academy Awards, including Best Cinematography." << endl;

    return 0;
}
