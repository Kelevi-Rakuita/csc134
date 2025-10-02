/*
CSC 134
Rakuita
M3BONUS - Number Guessing
10/2/2025

*/

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <limits>    // numeric_limits
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ---- Function Prototypes ----
void showTitle();
int showMenu();
int getMaxForDifficulty(int menuChoice);
int generateSecret(int maxValue);
int getValidatedInt(const string& prompt, int minVal, int maxVal);
bool playRound(int maxValue, int& attemptsOut, int& scoreOut);
bool askReplay();

// ---- Implementation ----
void showTitle() {
    cout << "=====================================\n";
    cout << "   NUMBER GUESSING - M3 BONUS GAME   \n";
    cout << "=====================================\n\n";
}

int showMenu() {
    cout << "Choose difficulty:\n";
    cout << "  1) Easy   (1-10)\n";
    cout << "  2) Normal (1-50)\n";
    cout << "  3) Hard   (1-100)\n";
    cout << "  4) Quit\n";
    int choice = getValidatedInt("Enter 1-4: ", 1, 4);
    cout << "\n";
    return choice;
}

int getMaxForDifficulty(int menuChoice) {
    // Uses a switch to map menu choice -> max target value
    switch (menuChoice) {
        case 1: return 10;
        case 2: return 50;
        case 3: return 100;
        default: return 10;
    }
}

int generateSecret(int maxValue) {
    // Returns a random number in [1, maxValue]
    // srand is seeded once in main.
    return (std::rand() % maxValue) + 1;
}

int getValidatedInt(const string& prompt, int minVal, int maxVal) {
    // Reads an int and enforces bounds. Re-prompts on bad input.
    while (true) {
        cout << prompt;
        int x;
        if (cin >> x) {
            if (x >= minVal && x <= maxVal) {
                return x;
            } else {
                cout << "Please enter a number between " << minVal << " and " << maxVal << ".\n";
            }
        } else {
            // Clear error state and discard bad input
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a whole number.\n";
        }
    }
}

bool playRound(int maxValue, int& attemptsOut, int& scoreOut) {
    // Play one round:
    // - Secret in [1, maxValue]
    // - Give higher/lower hints until correct
    // - Track attempts; compute a simple score
    const int secret = generateSecret(maxValue);
    attemptsOut = 0;
    scoreOut = 0;

    cout << "I'm thinking of a number between 1 and " << maxValue << ".\n";
    cout << "Can you guess it?\n\n";

    while (true) {
        int guess = getValidatedInt("Your guess: ", 1, maxValue);
        attemptsOut++;

        if (guess == secret) {
            cout << "ðŸŽ‰ Correct! The number was " << secret << ".\n";
            // Simple scoring: start at 100 and subtract 10 for each extra attempt (min 10)
            int raw = 100 - (attemptsOut - 1) * 10;
            scoreOut = (raw < 10) ? 10 : raw;
            cout << "Attempts: " << attemptsOut << " | Round Score: " << scoreOut << "\n\n";
            return true;
        } else if (guess < secret) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }
    }
}

bool askReplay() {
    cout << "Play again? (y/n): ";
    char c;
    // Eat leading whitespace and read a single char
    if (cin >> c) {
        c = std::tolower(static_cast<unsigned char>(c));
        cout << "\n";
        return c == 'y';
    }
    return false;
}

int main() {
    // Seed RNG once
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    showTitle();

    int totalRounds = 0;
    int cumulativeScore = 0;

    while (true) {
        int choice = showMenu();
        if (choice == 4) {
            cout << "Thanks for playing! Goodbye.\n";
            break;
        }

        int maxValue = getMaxForDifficulty(choice);

        int attempts = 0;
        int roundScore = 0;
        bool won = playRound(maxValue, attempts, roundScore);

        if (won) {
            totalRounds++;
            cumulativeScore += roundScore;
        }

        cout << "== STATS ==\n";
        cout << "Rounds won: " << totalRounds << "\n";
        cout << "Total Score: " << cumulativeScore << "\n\n";

        if (!askReplay()) {
            cout << "Final Score: " << cumulativeScore << "\n";
            cout << "See you next time!\n";
            break;
        }
    }

    return 0;
}

