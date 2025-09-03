/*
csc 134, M2T1
Rakuita
9/3/25
Revision of "sales" program from M1, now with user input.
*/

#include <iostream>
using namespace std;

int main () {
// Declare our variab;es ("the truth")
string item = "apples";
double cost_per= 0.99;
int amount = 20;
// Vaiables for user input
int amount_purchased;
double total_cost;

// Greet the user
cout <<"  Hello! Welcome to our " << item << "store." << endl;
// ask for information
cout << " Each of the "<< item << " cost $" << cost_per << endl;
cout<< " we have" << amount<< " for sale." << endl;
cout << endl;
cout <<" How many would you like to buy?"<< endl;
// cin: put information from the keyboard into a variable
cin >> amount_purchased;

// do some processing
//I say single equal as "gets"
total_cost = amount_purchased * cost_per;

//Output the answer
cout <<"You are buying" << "amount_purchased <<"  << item << endl;
cout << " The total is: $" << total_cost << endl;
cout << "Thank you for shopping with us." << endl;

    return 0;
}
