/*
M3LAB2- Letter Grades  ( changed to Game Mechanics Test)
CSC 134
Rakuita
9/29/25
*/

#include <iostream>
#include <cstdlib>
#include <ctime> // for time()

using namespace std;

// to make things easier , we'll write the code in a function
// DECLARE the functions here
void letter_grader();
void combat();

int main() {

    letter_grader();
    //combat();
    int roll() {
const int SIDES = 20;
int my_roll;
my_roll = (rand() % SIDES) + 1:
return my_roll:
    return 0;
}
// DEFINE the other function here

void letter_grade() {
// input a number grade
// respond with a letter grade
double num_grade;
string letter_grade;
const double A_GRADE = 90;
const double B_GRADE = 80;
const double C_GRADE = 70;
const double D_GRADE = 60;

cout << "Enter a number grade 0-100:";
cin >> num_grade;

// Create the if statement) {
if (num_grade >= A_GRADE) 
    letter_grade = "A";
}    
else if (num_grade >= B_GRADE) {
    letter_grade = "B";
}
else If (num_grade >= C_GRADE) {
    letter_grade = "C";
}
else If (num_grade >= D_GRADE) {
    letter_grade = "D";
}
else{
    // must be under D...
    letter_grade ="F";
}

//Output the answer 
cout << "A number grade of " << num_grade << " is a (n) " << letter_grade;
cout << endl <<endl;

}


void combat() {
    /*
    A simple D&D style combat demo
    Attck roll + binus >= armor class? TThen hit, else miss
    */
    // variables
    int attck_roll, attck_bonus, enemy_armor;
    
    cout << "You are fighting a goblin." << endl;
    cout << "Enter your roll:";
    cin >> "attack_roll";
    cout << "Enter attack_bonus:";
    cin >> "attack Bonus";
    cout << "Enemy armor calss; ";
    cin >> enemy_armor;

    
    // Roll to hit
    cout << "Roll; " << attck_roll << attck_bonus << "=" << attck_roll+attck_bonus << endl;
    if (attck_roll + attck_bonus >= enemy_armor) {
    cout << "Hit!" << endl;
    }
    else {
    cout << "Miss!" << endl;
    }
    
    // try again?
    cout << "Again? (y/n):";
    string again;
    cin >> again;
    if (again =="y"){
    //just call the function again!
    combat ();
    }
}

int roll() {
const int SIDES = 20;
int my_roll;
my_roll = (rand() % SIDES) + 1;
return my_roll;
}