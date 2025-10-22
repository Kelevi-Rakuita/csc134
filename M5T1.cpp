/*
CSC 134
M5T1 -  Intro to Functions
Kelevi Rakuita
10/22/2025

purpose: Demo void and value  returning funtions.
*/
#include  <iostream>
using namespace std;
// Functopns declarations (Definitions are at he bottom)
void say_hello(); // says hi

int get_the_answer(); // provides the naswer to everything

double double_a_number(double); // num times two

int main() {
    // This program does nothing useful
    double my_num;
    int another_num_base;

   cout << "Please enter a number (with or without decimal place). " << endl;
    cin >> my_num;
    //my_num = my_num * 2;
    my_num= double_a_number(my_num); //
    cout << "Double the number is: " << my_num<< endl;
    cout << "But the only answer you need is: ";
    cout << get_the_answer() << endl;
}

//  Function Definitions (the whole function!) go here
void say_hello() {
    // says hi
     cout <<"Welcome to the best program ever!" << endl;
}

int get_the_answer() {
    //provides the answer to everything
    return 42;
}

double double_a_number(double the_num) {
    // num times two
    double answer = the_num * 2;
    return answer;
}