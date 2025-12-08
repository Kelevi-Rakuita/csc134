#include <iostream>
using namespace std;

/* CSC 134
 M7T1 - Restaurant Rating
 Kelevi Rakuita
 12/7/2025
 Use Restaurant class to store user ratings
 */

class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
    // constructor
    Restaurant(string n, double r) {
        name = n;
        rating = r;
    }

    // getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }

    // print a formatted entry
    void printInfo() {
        cout << "Name: " << name << " ";
        cout << "(" << rating << "/5 stars)" << endl;
    }
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl << endl;

    // create three restaurants (assignment requirement)
    Restaurant breakfast_place("Waffle House", 3.0);
    Restaurant lunch_place("Mi Casita", 4.5);
    Restaurant dinner_place("Texas Roadhouse", 5.0);  // <-- added third restaurant

    cout << "Review info" << endl << endl;

    cout << "Breakfast:" << endl;
    breakfast_place.printInfo();
    cout << endl;

    cout << "Lunch:" << endl;
    lunch_place.printInfo();
    cout << endl;

    cout << "Dinner:" << endl;
    dinner_place.printInfo();
    cout << endl;

    return 0;
}
