/*
csc 134
M4Lab1
Rakuita
10/6/2025
Claude AI help.
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void exercise1_healthRegen();
void exercise2_levelUpStats();
void exercise3_inventorySystem();

int main()
{
    int choice;

    cout << "==================================" << endl;
    cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
    cout << "==================================" << endl;
    cout << "1. Exercise 1: Health Regeneration" << endl;
    cout << "2. Exercise 2: Level Up Stats" << endl;
    cout << "3. Exercise 3: Inventory System" << endl;
    cout << "4. Run All Exercises" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            exercise1_healthRegen();
            break;
        case 2:
            exercise2_levelUpStats();
            break;
        case 3:
            exercise3_inventorySystem();
            break;
        case 4:
            exercise1_healthRegen();
            cout << endl;
            exercise2_levelUpStats();
            cout << endl;
            exercise3_inventorySystem();
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

/*
EXERCISE 1: HEALTH REGENERATION (30 points)
CONCEPT: while loop - repeat until condition changes
================================================================================
*/
void exercise1_healthRegen()
{
    cout << "\n=== EXERCISE 1: HEALTH REGENERATION ===" << endl;

    int health = 30;
    int maxHealth = 100;

    cout << "Starting health: " << health << "/" << maxHealth << endl;
    cout << "Resting to recover health..." << endl << endl;

    // WHILE LOOP: Keep healing while health is less than max
    while (health < maxHealth)
    {
        health = health + 10;  // Increase health by 10
        
        // Display current health
        cout << "Health: " << health << "/" << maxHealth;
        
        // BONUS: Visual health bar
        cout << "  [";
        int bars = health / 10;  // Each 10 HP = one bar
        for (int i = 0; i < 10; i++)
        {
            if (i < bars)
                cout << "█";
            else
                cout << "░";
        }
        cout << "]" << endl;
    }

    cout << "\nFully recovered!" << endl;
}

/*
EXERCISE 2: LEVEL UP STATS (35 points)
CONCEPT: for loop - count through a sequence
================================================================================
*/
void exercise2_levelUpStats()
{
    cout << "\n=== EXERCISE 2: LEVEL UP STATS ===" << endl;

    // Base stats at level 0
    const int BASE_STR = 10;
    const int BASE_DEX = 8;
    const int BASE_INT = 12;

    // Display table header
    cout << "Level |  STR  |  DEX  |  INT" << endl;
    cout << "------|-------|-------|-------" << endl;

    // Variables to track first and last level stats for growth calculation
    int firstStr, firstDex, firstInt;
    int lastStr, lastDex, lastInt;

    // FOR LOOP: Count from level 1 to 10
    for (int level = 1; level <= 10; level++)
    {
        // Calculate stats using the formulas
        int strength = BASE_STR + (level * 2);
        int dexterity = BASE_DEX + (level * 3);
        int intelligence = BASE_INT + (level * 1);
        
        // Save first level stats
        if (level == 1)
        {
            firstStr = strength;
            firstDex = dexterity;
            firstInt = intelligence;
        }
        
        // Save last level stats
        if (level == 10)
        {
            lastStr = strength;
            lastDex = dexterity;
            lastInt = intelligence;
        }
        
        // Display formatted row
        cout << "  " << level << "   |   " << strength << "  |   " 
             << dexterity << "  |   " << intelligence << endl;
    }

    cout << "==============================" << endl;
    
    // Calculate total growth (level 10 - level 1)
    int strGrowth = lastStr - firstStr;
    int dexGrowth = lastDex - firstDex;
    int intGrowth = lastInt - firstInt;
    
    cout << "Total Growth: STR +" << strGrowth 
         << ", DEX +" << dexGrowth 
         << ", INT +" << intGrowth << endl;
}

/*
EXERCISE 3: INVENTORY SYSTEM (35 points)
CONCEPT: arrays + loops - managing collections
================================================================================
*/
void exercise3_inventorySystem()
{
    cout << "\n=== EXERCISE 3: INVENTORY SYSTEM ===" << endl;

    // Equipment array with 5 items
    string equipment[5] = {
        "Iron Sword",
        "Leather Armor",
        "Health Potion",
        "Magic Ring",
        "Rope"
    };

    // Display all items using a for loop
    cout << "=== YOUR INVENTORY ===" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << (i+1) << ". " << equipment[i] << endl;
    }
    cout << "======================" << endl << endl;

    // Get search term from user
    string searchTerm;
    cout << "Enter item to search for: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, searchTerm);

    // Search for the item using a loop
    bool found = false;
    int position = -1;

    for (int i = 0; i < 5; i++)
    {
        if (equipment[i] == searchTerm)
        {
            found = true;
            position = i;
            break;  // Stop searching once found
        }
    }

    // Display search results
    if (found)
    {
        cout << "Found \"" << searchTerm << "\" in slot " 
             << (position + 1) << "!" << endl;
    }
    else
    {
        cout << "\"" << searchTerm << "\" not found in inventory." << endl;
    }
}
