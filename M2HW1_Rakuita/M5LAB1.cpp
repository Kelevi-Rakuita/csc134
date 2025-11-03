/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Kelevi Rakuita
11/03/2025
This program creates an interactive story
where the user makes choices to explore
a spooky old house.
*/

#include <iostream>
using namespace std;

// Function Prototypes
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_window();
void choice_basement();
void choice_attic();
void choice_kitchen();
void choice_investigate_noise();
void choice_run_away();

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  cout << "====================================" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << " Thanks for playing!" << endl;
  return 0; // /inished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "--- Main Menu ---" << endl;
  cout << "You're in front of a spooky old house..." << endl;
  cout << "The windows are dark and you hear strange sounds inside." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
void choice_front_door() {
  cout << "--- Front Door ---" << endl;
  cout << "You approach the creaky front door and try the handle." << endl;
  cout << "It's locked tight!" << endl;
  cout << "But you notice a window nearby is slightly open..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try to climb through the window" << endl;
  cout << "2. Check around back" << endl;
  cout << "3. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  
  if (1 == choice) {
    choice_window();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else {
    cout << "Invalid choice! Try again." << endl;
    cin.ignore();
    choice_front_door();
  }
}

void choice_back_door() {
  cout << "--- Back Door ---" << endl;
  cout << "You sneak around to the back of the house." << endl;
  cout << "The back door is unlocked! It swings open with an eerie creak." << endl;
  cout << "You step inside and find yourself in a dark kitchen." << endl;
  cout << "You hear footsteps upstairs and see stairs leading to a basement." << endl;
  cout << "Do you:" << endl;
  cout << "1. Explore the kitchen" << endl;
  cout << "2. Go down to the basement" << endl;
  cout << "3. Run back home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  
  if (1 == choice) {
    choice_kitchen();
  } else if (2 == choice) {
    choice_basement();
  } else if (3 == choice) {
    choice_go_home();
  } else {
    cout << "Invalid choice! Try again." << endl;
    cin.ignore();
    choice_back_door();
  }
}

void choice_go_home() {
  cout << "--- Going Home ---" << endl;
  cout << "You decide this is too creepy and head home." << endl;
  cout << "As you walk away, you swear you see a face in the window watching you..." << endl;
  cout << "Maybe it's better not to know what was inside." << endl;
  cout << "*** THE END ***" << endl;
}

void choice_window() {
  cout << "--- Through the Window ---" << endl;
  cout << "You climb through the window and tumble into a dusty living room." << endl;
  cout << "Suddenly, you hear a LOUD CRASH from upstairs!" << endl;
  cout << "There's also a door that might lead to the attic." << endl;
  cout << "Do you:" << endl;
  cout << "1. Investigate the noise upstairs" << endl;
  cout << "2. Check out the attic" << endl;
  cout << "3. Run away through the window" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  
  if (1 == choice) {
    choice_investigate_noise();
  } else if (2 == choice) {
    choice_attic();
  } else if (3 == choice) {
    choice_run_away();
  } else {
    cout << "Invalid choice! Try again." << endl;
    cin.ignore();
    choice_window();
  }
}

void choice_basement() {
  cout << "--- The Basement ---" << endl;
  cout << "You carefully descend the creaky stairs into the dark basement." << endl;
  cout << "You find old furniture covered in sheets and... wait..." << endl;
  cout << "There's a treasure chest in the corner!" << endl;
  cout << "You open it and find it full of gold coins!" << endl;
  cout << "You're rich! You quickly grab the treasure and leave." << endl;
  cout << "*** THE END - You Win! ***" << endl;
}

void choice_attic() {
  cout << "--- The Attic ---" << endl;
  cout << "You climb the narrow stairs to the attic." << endl;
  cout << "It's filled with old boxes and cobwebs." << endl;
  cout << "In the corner, you find an old diary." << endl;
  cout << "It tells the story of the family who lived here 100 years ago." << endl;
  cout << "Mystery solved! You leave with the diary as a keepsake." << endl;
  cout << "*** THE END - Mystery Solved! ***" << endl;
}

void choice_kitchen() {
  cout << "--- The Kitchen ---" << endl;
  cout << "You explore the kitchen and find fresh food on the counter." << endl;
  cout << "Someone has been here recently!" << endl;
  cout << "Suddenly, you hear footsteps approaching..." << endl;
  cout << "A friendly elderly woman appears!" << endl;
  cout << "'Oh my! I didn't know anyone was here. Would you like some cookies?'" << endl;
  cout << "Turns out the 'haunted house' is just an old woman's home." << endl;
  cout << "*** THE END - False Alarm! ***" << endl;
}

void choice_investigate_noise() {
  cout << "--- Investigating the Noise ---" << endl;
  cout << "You bravely head upstairs toward the crashing sound." << endl;
  cout << "You open a bedroom door and..." << endl;
  cout << "It's just a cat! It knocked over a lamp." << endl;
  cout << "The cat purrs and rubs against your leg." << endl;
  cout << "You adopt the friendly cat and head home." << endl;
  cout << "*** THE END - You Made a Friend! ***" << endl;
}

void choice_run_away() {
  cout << "--- Running Away ---" << endl;
  cout << "This is too scary! You scramble back through the window." << endl;
  cout << "You run all the way home without looking back." << endl;
  cout << "Your heart is pounding, but at least you're safe!" << endl;
  cout << "*** THE END - Better Safe Than Sorry! ***" << endl;
}