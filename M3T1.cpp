/*
CSC 134
M3T1 - Area of Rectangle
Simple Comparrison
Kelevi Rakuita
9/17/25
*/

#include <iostream>
using namespace std;

int main () {
    // Get info on the two rectangles
    double length1, length2, width1, width2;
    double area1, area2;
     cout << "Enter the length and width of two rectangles." << endl;
     cout << "First rectangle." << endl;
     cout << "Length: ";
     cin  >> length1;
     cout << "Width: ";
     cin >> width1;
     cout << endl;
     cout <<" Second rectangle." << endl;
     cout << "Length: ";
     cin >> length2;
     cout <<"Width: ";
     cin >> width2;

     //Calculate the area
     area1 = length1 * width1;
     area2 = length2 * width2;

     //print the output
     cout << "First rectangle area = " << area1 << endl;
     cout << " Second rectangle area = " << area2 << endl;

     return 0; // no errors

     // Compare the two rectangles
     if (area1 > area2) {
        cout << "The first rectangle is larger." << endl;
     }
     if (area1 > area1) {
        cout << "The second rectangle is larger." << endl;
     }
     if (area1 == area2) { // "==" means "is equal to"
        cout << " The rectangles are the same area." << endl;
     }
}
