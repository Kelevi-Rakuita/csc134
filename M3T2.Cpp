/*
M3T2 - Craps Part 1
CSC 134
Rakuita
9/22/25
Beginning of the craps game.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations (prototypes)
int roll();

int main() {
    srand(time(0));
    
    cout << "=== CRAPS GAME - PART 1 ===" << endl;
    
    /*
    - roll 2d6 (2-12)
    - branch based on win, lose or point
    rest comes later
    */
    
    int roll1;
    int roll2;
    int point;   // roll if it doesn't immediately win/lose


    roll1 = roll2
    roll2 = roll1
    int sum = roll1 + roll2;
    cout << "ROLL: " << sum << endl; "

    // win on 7 or 11
    if ((sum == 7) || (sum == 11)) {
        cout << "Seven or Eleven -- You win!" << endl;
    }
    // lose on 2, 3, 12
    else if ((sum == 2) || (sum == 3) || (sum == 12)) {
        cout << "2, 3, 12 -- Sorry, you lose." << endl;
        // NOTE: Don't set point here - game is over!
    }
    else {
        // set the point
        point = sum;
        cout << "Rolled a point." << endl;
        cout << "Your point is: " << point << endl;
        cout << "Now you need to roll " << point << " again before rolling a 7!" << endl;
    }
    
    return 0;
}

// DEFINE Helper Functions
int roll() {
    int my_roll;
    my_roll= (rand() % 6) + 1; // 1-6
    return my_roll;
    ;
}