/*
CSC 134
Rakuita
9/24/2025
Welcome to your Adventure
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Program introduction
    cout << "================================" << endl;
    cout << "    DUNGEON ENCOUNTER" << endl;
    cout << "================================" << endl;
    cout << endl;
    
    // Set the scene
    cout << "You are exploring a dark dungeon when suddenly..." << endl;
    cout << "A fierce goblin blocks your path!" << endl;
    cout << "The goblin snarls and raises its rusty sword." << endl;
    cout << endl;
    
    // Present the choice
    cout << "What do you do?" << endl;
    cout << "Type 'fight' to battle the goblin" << endl;
    cout << "Type 'run' to flee from danger" << endl;
    cout << "Type 'sneak' to try sneaking past" << endl;
    cout << endl;
    cout << "Your choice: ";
    
    // Get user input
    string userChoice;
    cin >> userChoice;
    cout << endl;
    
    // Process the choice with if statements
    if (userChoice == "fight") {
        cout << "🗡️ You draw your sword and charge!" << endl;
        cout << "After a fierce battle, you defeat the goblin!" << endl;
        cout << "You find 50 gold coins in its pouch." << endl;
        cout << "Victory! You continue deeper into the dungeon." << endl;
    }
    else if (userChoice == "run") {
        cout << "🏃 You turn and run as fast as you can!" << endl;
        cout << "The goblin chases you but you're too quick." << endl;
        cout << "You escape safely but find no treasure." << endl;
        cout << "You live to fight another day!" << endl;
    }
    else if (userChoice == "sneak") {
        cout << "🤫 You try to sneak past quietly..." << endl;
        cout << "Success! The goblin doesn't notice you." << endl;
        cout << "You spot a hidden chest behind the goblin!" << endl;
        cout << "You find 100 gold coins and a magic potion!" << endl;
        cout << "Sometimes the clever path is the best path." << endl;
    }
    else {
        cout << "❓ You hesitate, unsure what to do..." << endl;
        cout << "The goblin takes advantage of your confusion!" << endl;
        cout << "It strikes you with its sword!" << endl;
        cout << "You barely escape with your life." << endl;
        cout << "Next time, make a clear choice!" << endl;
    }
    
    cout << endl;
    cout << "Thanks for playing!" << endl;
    
    return 0;
}