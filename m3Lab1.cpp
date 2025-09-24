/*
CSC 134
Rakuita
9/24/2025
Welcome to your Adventure
*/

#include <iostream>
#include <string>      // ADDED: For text handling
#include <random>      // ADDED: For dice rolling
#include <vector>      // ADDED: For inventory system
using namespace std;

// ========== GAME STATE ========== 
struct Player {
    int health = 100;              // ADDED: Health points
    int gold = 50;                 // ADDED: Starting money
    int strength = 10;             // ADDED: Attack power
    vector<string> inventory;      // ADDED: Items collected
    bool hasKey = false;           // ADDED: Quest flags
    bool hasSword = false;
};

Player player;  // ADDED: Global player object
// ADDED: Clear screen for better presentation
void clearScreen() {
    for(int i = 0; i < 50; i++) cout << "\n";
}

// ADDED: Show player's current stats
void showStats() {
    cout << "\n--- Your Stats ---" << endl;
    cout << "Health: " << player.health << "/100" << endl;
    cout << "Gold: " << player.gold << endl;
    cout << "Strength: " << player.strength << endl;
    if(!player.inventory.empty()) {
        cout << "Inventory: ";
        for(size_t i = 0; i < player.inventory.size(); i++) {
            cout << player.inventory[i];
            if(i < player.inventory.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

// ADDED: Random number generation for events
int rollDice(int sides = 20) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, sides);
    return dis(gen);
}

// ADDED: Add items to inventory
void addItem(string item) {
    player.inventory.push_back(item);
    cout << "📦 You found: " << item << "!" << endl;
}
int main() {
    cout << "==================================" << endl;
    cout << " ⚔️  KINGDOM OF SHADOWS  ⚔️" << endl;    // CHANGED: Better title + emojis
    cout << "==================================" << endl;
    cout << "\nThe kingdom is in peril, and only you can save it!" << endl;  // ADDED
    cout << "Your quest begins..." << endl;                                   // ADDED
    
    tavern();  // Same as original
    
    cout << "\n🏰 === THE END === 🏰" << endl;         // CHANGED: Added emojis
    cout << "Thanks for playing!" << endl;             // ADDED
    return 0;
}
void tavern() {
    // ADDED: Better formatting and title
    cout << "\n🍺 === THE RUSTY DRAGON TAVERN === 🍺" << endl;
    
    // ENHANCED: More detailed story
    cout << "\nYou wake up in a dusty tavern, your head pounding." << endl;
    cout << "The gruff bartender approaches you with concern." << endl;
    cout << "\"Ah, you're awake! A dragon has been terrorizing our kingdom!\"" << endl;
    cout << "\"Many brave souls have tried to stop it... none returned.\"" << endl;
    
    showStats();  // ADDED: Show player stats
    
    // ENHANCED: More choices and better formatting
    cout << "\nWhat will you do?" << endl;
    cout << "1. 🗡️  Accept the quest (head to the forest)" << endl;
    cout << "2. 🍺 Buy a drink and gather information (5 gold)" << endl;  // COMPLETELY NEW OPTION
    cout << "3. 🚪 Leave the tavern (coward's path)" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        // ENHANCED: More story + give player items
        cout << "\n\"Brave soul! May the gods protect you!\"" << endl;
        cout << "The bartender hands you a rusty dagger." << endl;
        addItem("Rusty Dagger");  // ADDED: Give starting weapon
        player.strength += 2;     // ADDED: Increase player stats
        forest();
    } 
    else if (choice == 2 && player.gold >= 5) {  // COMPLETELY NEW: Information gathering
        player.gold -= 5;
        cout << "\n🍺 You buy an ale and listen to the tavern gossip..." << endl;
        cout << "\"The dragon hoards treasure in the old castle!\"" << endl;
        cout << "\"There's a secret path through the Whispering Woods.\"" << endl;
        cout << "\"Legend says a magic sword lies hidden in the forest.\"" << endl;
        player.health += 10; // Rest bonus
        tavern(); // Return to menu - lets player try again
    }
    else if (choice == 2) {  // ADDED: Handle insufficient gold
        cout << "\n💰 You don't have enough gold!" << endl;
        tavern();
    }
    else {
        cout << "\n\"Coward! Don't let the door hit you on the way out!\"" << endl;
        gameOver("You fled from your destiny...");  // ENHANCED: Added death reason
    }
}
void forest() {
    // ADDED: Atmospheric description with title
    cout << "\n🌲 === THE WHISPERING WOODS === 🌲" << endl;
    cout << "\nYou enter the dark forest. Ancient trees tower above you," << endl;
    cout << "their branches creaking ominously in the wind." << endl;
    
    // ADDED: Random encounter system!
    int encounter = rollDice(6);
    
    if (encounter <= 2) {
        // ADDED: Combat encounters
        cout << "\n⚠️  A wild wolf jumps out from behind a tree!" << endl;
        if (combat("Wolf", 30, 8)) {  // NEW: Combat system
            player.gold += 10;
            cout << "💰 You found 10 gold on the wolf's collar!" << endl;
        } else {
            return; // Player died in combat
        }
    }
    else if (encounter <= 4) {
        // ADDED: Treasure encounters with conditional rewards
        cout << "\n✨ You discover a glittering object in a hollow tree!" << endl;
        if (!player.hasSword) {
            cout << "🗡️  It's a magical sword!" << endl;
            addItem("Magic Sword");
            player.hasSword = true;
            player.strength += 8;
        } else {
            cout << "💰 It's a pouch of gold!" << endl;
            int goldFound = rollDice(20) + 10;
            player.gold += goldFound;
            cout << "You found " << goldFound << " gold!" << endl;
        }
    }
    else {
        // ADDED: Peaceful helpful encounters
        cout << "\n🧙 An old hermit emerges from the shadows." << endl;
        cout << "\"Seeking the dragon, are we? Take this advice...\"" << endl;
        cout << "\"The beast fears the light of day. Strike when the sun is high!\"" << endl;
        player.health += 20;
        cout << "❤️  The hermit's blessing restores 20 health!" << endl;
    }
    
    showStats();  // ADDED: Show updated stats after encounter
    
    // ADDED: Multiple path system
    cout << "\nWhich path will you take?" << endl;
    cout << "1. 🏰 Head to the ancient castle" << endl;
    cout << "2. 🌲 Search deeper in the forest" << endl;  // NEW: Can explore multiple times
    cout << "3. 🔙 Return to the tavern" << endl;         // NEW: Go back option
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    switch(choice) {
        case 1: castle(); break;
        case 2: forest(); break; // ADDED: Recursive exploration
        case 3: tavern(); break; // ADDED: Can go back
        default: 
            cout << "Invalid choice! The path chooses for you..." << endl;
            castle();
    }
}
void castle() {
    // ADDED: Atmospheric castle approach
    cout << "\n🏰 === THE SHADOW CASTLE === 🏰" << endl;
    cout << "\nYou approach the imposing castle. Its towers pierce the stormy sky." << endl;
    cout << "The massive wooden doors are locked tight." << endl;
    
    // ADDED: Key finding mechanic
    if (!player.hasKey) {
        cout << "\n🔍 You search around and find a hidden key under a loose stone!" << endl;
        addItem("Castle Key");
        player.hasKey = true;
    }
    
    // ADDED: Castle interior description
    cout << "\nYou unlock the doors and step inside..." << endl;
    cout << "The air is thick with the smell of sulfur and smoke." << endl;
    cout << "You hear a deep rumbling from above - the dragon's lair!" << endl;
    
    // ADDED: Strategic choice system
    cout << "\nWhat's your approach?" << endl;
    cout << "1. ⚔️  Charge directly to the dragon's lair" << endl;
    cout << "2. 🔍 Search the castle for treasure and supplies" << endl;
    cout << "3. 🤫 Try to sneak up on the dragon" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    // ADDED: Branching paths
    if (choice == 2) {
        treasure();  // Go to optional treasure room
    } else {
        dragonLair();  // Go straight to final boss
    }
}
bool combat(string enemy, int enemyHealth, int enemyAttack) {
    cout << "\n⚔️  === COMBAT WITH " << enemy << " === ⚔️" << endl;
    
    while (enemyHealth > 0 && player.health > 0) {
        cout << "\n" << enemy << " Health: " << enemyHealth << endl;
        cout << "Your Health: " << player.health << endl;
        cout << "\nWhat will you do?" << endl;
        cout << "1. ⚔️  Attack!" << endl;
        cout << "2. 🛡️  Defend (reduce damage)" << endl;
        cout << "3. 🏃 Try to flee" << endl;
        
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            int damage = rollDice(10) + player.strength;
            cout << "You deal " << damage << " damage!" << endl;
            enemyHealth -= damage;
        }
        else if (choice == 2) {
            cout << "You raise your guard!" << endl;
            enemyAttack = max(1, enemyAttack - 3);
        }
        else if (choice == 3) {
            if (rollDice() > 15) {
                cout << "You successfully escape!" << endl;
                return false;
            } else {
                cout << "You couldn't escape!" << endl;
            }
        }
        
        if (enemyHealth > 0) {
            cout << enemy << " attacks for " << enemyAttack << " damage!" << endl;
            player.health -= enemyAttack;
        }
    }
    
    if (player.health <= 0) {
        gameOver("You were defeated in combat!");
        return false;
    }
    
    cout << "\n🎉 You defeated the " << enemy << "!" << endl;
    return true;
}void treasure() {
    cout << "\n💎 === THE TREASURE ROOM === 💎" << endl;
    cout << "\nYou discover a room filled with glittering treasure!" << endl;
    
    int goldFound = rollDice(50) + 25;
    player.gold += goldFound;
    cout << "💰 You found " << goldFound << " gold!" << endl;
    
    cout << "⚗️  You also find a healing potion!" << endl;
    addItem("Healing Potion");
    player.health = min(100, player.health + 30);
    
    showStats();
    dragonLair();
}void dragonLair() {
    cout << "\n🐉 === THE DRAGON'S LAIR === 🐉" << endl;
    cout << "\nYou climb the winding stairs to the highest tower." << endl;
    cout << "The ancient dragon SHADOWWING lies coiled around a massive treasure hoard!" << endl;
    cout << "Its eyes glow like molten gold as it notices you." << endl;
    cout << "\n\"FOOLISH MORTAL! YOU DARE CHALLENGE ME?\"" << endl;
    
    showStats();
    
    if (player.health < 50) {
        cout << "\n⚠️  You're badly wounded! This will be dangerous!" << endl;
    }
    
    // Epic final boss fight
    if (combat("SHADOWWING THE DRAGON", 80, 15)) {
        victory();
    }
}void gameOver(string reason) {  // ADDED: Custom death reasons
    cout << "\n💀 === GAME OVER === 💀" << endl;
    if (!reason.empty()) {         // ADDED: Show specific death reason
        cout << reason << endl;
    }
    cout << "Your adventure ends here." << endl;
    cout << "The kingdom falls to darkness..." << endl;  // ADDED: More dramatic ending
}void victory() {
    cout << "\n🏆 === VICTORY! === 🏆" << endl;           // ENHANCED: Better formatting
    cout << "\nWith a final mighty blow, you strike down the dragon!" << endl;  // ADDED
    cout << "SHADOWWING crashes to the ground, defeated at last!" << endl;      // ADDED
    cout << "\nThe kingdom is saved!" << endl;
    cout << "You are hailed as the greatest hero in the land!" << endl;        // ADDED
    
    cout << "\n🎊 FINAL STATS 🎊" << endl;                // ADDED: Show final stats
    showStats();
    
    cout << "\n👑 You claim the dragon's treasure and become royalty!" << endl;  // ADDED
    cout << "Bards will sing songs of your courage for generations!" << endl;    // ADDED
}