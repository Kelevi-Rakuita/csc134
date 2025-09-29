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