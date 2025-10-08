/*
CSC 134
Rakuita
M3BONUS - Guess my number game.
10/1/2025


*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to show welcome message
void showWelcome() {
    cout << "\n================================" << endl;
    cout << "     GUESS MY NUMBER GAME!     " << endl;
    cout << "================================" << endl;
}

// Function to show difficulty menu and get choice
int getDifficulty() {
    int choice;
    cout << "\nChoose your difficulty:" << endl;
    cout << "1. Easy (1-20)" << endl;
    cout << "2. Medium (1-50)" << endl;
    cout << "3. Hard (1-100)" << endl;
    cout << "Enter 1, 2, or 3: ";
    cin >> choice;
    return choice;
}

// Function to generate secret number based on difficulty
int generateSecret(int difficulty) {
    if (difficulty == 1) {
        return rand() % 20 + 1;  // 1 to 20
    } else if (difficulty == 2) {
        return rand() % 50 + 1;  // 1 to 50
    } else {
        return rand() % 100 + 1; // 1 to 100
    }
}

// Function to show the range based on difficulty
void showRange(int difficulty) {
    cout << "\nI'm thinking of a number between ";
    if (difficulty == 1) {
        cout << "1 and 20..." << endl;
    } else if (difficulty == 2) {
        cout << "1 and 50..." << endl;
    } else {
        cout << "1 and 100..." << endl;
    }
    cout << "Can you guess it?" << endl;
    cout << endl;
}

// Function to get player's guess
int getGuess() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

// Function to give hints
void giveHint(int guess, int secret) {
    if (guess < secret) {
        cout << "Too low! Try a HIGHER number." << endl;
        cout << endl;
    } else if (guess > secret) {
        cout << "Too high! Try a LOWER number." << endl;
        cout << endl;
    }
}

// Function to rate player's performance
void ratePerformance(int guesses, int difficulty) {
    cout << "It took you " << guesses << " guesses!" << endl;
    
    // Different standards for different difficulties
    int excellent, good, okay;
    
    if (difficulty == 1) {
        excellent = 4;
        good = 6;
        okay = 8;
    } else if (difficulty == 2) {
        excellent = 6;
        good = 9;
        okay = 12;
    } else {
        excellent = 8;
        good = 12;
        okay = 16;
    }
    
    // Give rating based on performance
    if (guesses <= excellent) {
        cout << "⭐⭐⭐ EXCELLENT! You're a mind reader! ⭐⭐⭐" << endl;
    } else if (guesses <= good) {
        cout << "⭐⭐ GREAT JOB! Very impressive! ⭐⭐" << endl;
    } else if (guesses <= okay) {
        cout << "⭐ GOOD WORK! You got there! ⭐" << endl;
    } else {
        cout << "You made it! Keep practicing! 💪" << endl;
    }
}

// Function to ask if player wants to play again
char askPlayAgain() {
    char answer;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> answer;
    return answer;
}

int main() {
    // Seed the random number generator (only once!)
    srand(time(0));
    
    // Show welcome message
    showWelcome();
    
    // Variable to control the game loop
    char playAgain = 'y';
    
    // MAIN GAME LOOP - keeps playing until user says no
    while (playAgain == 'y' || playAgain == 'Y') {
        
        // Get difficulty choice
        int difficulty = getDifficulty();
        
        // Generate secret number based on difficulty
        int secretNumber = generateSecret(difficulty);
        
        // Show the range
        showRange(difficulty);
        
        // Variables for this round
        int playerGuess = 0;
        int guessCount = 0;
        
        // GUESSING LOOP - keep guessing until correct
        while (playerGuess != secretNumber) {
            playerGuess = getGuess();
            guessCount = guessCount + 1;
            
            if (playerGuess == secretNumber) {
                cout << "\n🎉 YES! You got it! The number was " << secretNumber << "!" << endl;
                ratePerformance(guessCount, difficulty);
                cout << "YOU WIN!" << endl;
            } else {
                giveHint(playerGuess, secretNumber);
            }
        }
        
        // Ask if they want to play again
        playAgain = askPlayAgain();
    }
    
    // Game over message
    cout << "\nThanks for playing! Goodbye! 👋" << endl;
    
    return 0;
}