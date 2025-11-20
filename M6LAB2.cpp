/*
CSC 134
M6LAB2 - Using Data structures
Kelevi Rakuita
11/20/2025

*/

#include <iostream>
#include <string>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms (military mountain mission)
enum Room {
    LZ = 0,         // Helicopter Landing Zone
    OVERWATCH = 1,  // Overwatch Ridge
    COMPOUND = 2,   // Village Compound
    WADI = 3,       // Dry Wadi / IED Route
    CAVE = 4,       // Cave System / Weapons Cache
    NUM_ROOMS = 5
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Mountain LZ",
        "Overwatch Ridge",
        "Village Compound",
        "Dry Wadi",
        "Cave System"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        // LZ
        "You are at a small helicopter landing zone carved into the side of a mountain. "
        "The rotor wash has died down, and the bird has peeled off into the darkness. "
        "Your team is alone in the Afghan mountains.",
        
        // OVERWATCH
        "You crawl up onto a rocky ridge that overlooks the valley. "
        "From here you can observe the wadi, cave entrance, and compound below.",
        
        // COMPOUND
        "You enter a small village compound. Mud-brick walls, a metal gate, "
        "and a courtyard with a water barrel. You see signs of recent activity.",
        
        // WADI
        "You move into a dry wadi, a natural drainage channel cut through the terrain. "
        "This is a classic place for IED emplacement along a footpath.",
        
        // CAVE
        "You stand at the mouth of a cave system. Inside, the air is cooler. "
        "You see crates, tarps, and fresh footprints in the dust."
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Map layout (top-down mental map):
    //
    //       Overwatch Ridge
    //             ^
    //             |
    // Mountain LZ ---- Dry Wadi ---- Cave System
    //       |
    // Village Compound
    //
    // LZ connections
    connections[LZ][NORTH] = OVERWATCH;  // LZ -> North -> Overwatch
    connections[LZ][EAST]  = WADI;       // LZ -> East  -> Wadi
    connections[LZ][SOUTH] = COMPOUND;   // LZ -> South -> Compound
    connections[LZ][WEST]  = -1;
    
    // Overwatch connections
    connections[OVERWATCH][SOUTH] = LZ;
    connections[OVERWATCH][NORTH] = -1;
    connections[OVERWATCH][EAST]  = -1;
    connections[OVERWATCH][WEST]  = -1;
    
    // Compound connections
    connections[COMPOUND][NORTH] = LZ;
    connections[COMPOUND][EAST]  = -1;
    connections[COMPOUND][SOUTH] = -1;
    connections[COMPOUND][WEST]  = -1;
    
    // Wadi connections
    connections[WADI][WEST] = LZ;
    connections[WADI][EAST] = CAVE;
    connections[WADI][NORTH] = -1;
    connections[WADI][SOUTH] = -1;
    
    // Cave connections
    connections[CAVE][WEST] = WADI;
    connections[CAVE][NORTH] = -1;
    connections[CAVE][EAST]  = -1;
    connections[CAVE][SOUTH] = -1;
    
    // Game state
    int currentRoom = LZ;      // Start at the LZ
    bool gameRunning = true;
    
    // Mission objectives
    bool iedCacheMarked = false;
    bool weaponsCacheMarked = false;
    
    cout << "========================================" << endl;
    cout << "  M6LAB2 - SPECIAL OPS MOUNTAIN MISSION " << endl;
    cout << "========================================" << endl;
    cout << "You are part of a small special operations team inserted" << endl;
    cout << "into the mountains of Afghanistan." << endl;
    cout << "Mission: Locate and MARK the suspected IED cache and" << endl;
    cout << "the weapons cache, then return to the LZ for extraction." << endl << endl;
    
    cout << "Commands: north, east, south, west, look, mark, status, help, quit" << endl;
    cout << "Shortcuts: n, e, s, w, q" << endl;
    
    // Game loop
    while (gameRunning) {
        cout << endl;
        cout << "You are at: " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Check mission success
        if (currentRoom == LZ && iedCacheMarked && weaponsCacheMarked) {
            cout << endl;
            cout << "You report over the radio that both caches are marked for" << endl;
            cout << "follow-on strike and exploitation teams." << endl;
            cout << "Extraction bird inbound. Mission success. Nice work." << endl;
            break;
        }
        
        // Input
        string command;
        cout << endl;
        cout << "What would you like to do? ";
        cin >> command;
        
        // To lowercase
        for (size_t i = 0; i < command.size(); i++) {
            command[i] = static_cast<char>(tolower(command[i]));
        }
        
        // Process commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "The terrain is too steep to the north. You cannot move that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "No viable path to the east." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You cannot move south from here." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "No safe route to the west." << endl;
            }
        } else if (command == "look") {
            cout << roomDescriptions[currentRoom] << endl;
        } else if (command == "help") {
            cout << "Commands: north, east, south, west, look, mark, status, help, quit" << endl;
            cout << "Shortcuts: n, e, s, w, q" << endl;
            cout << "Objective: Mark the IED cache (Dry Wadi) and weapons cache (Cave System)," << endl;
            cout << "           then return to the Mountain LZ." << endl;
        } else if (command == "status") {
            cout << "Mission status:" << endl;
            cout << "  IED cache (Dry Wadi): ";
            cout << (iedCacheMarked ? "MARKED" : "NOT MARKED") << endl;
            cout << "  Weapons cache (Cave System): ";
            cout << (weaponsCacheMarked ? "MARKED" : "NOT MARKED") << endl;
        } else if (command == "mark") {
            if (currentRoom == WADI && !iedCacheMarked) {
                cout << "You identify disturbed earth and components along the wadi path." << endl;
                cout << "You mark the suspected IED cache location with IR chem lights." << endl;
                iedCacheMarked = true;
            } else if (currentRoom == WADI && iedCacheMarked) {
                cout << "The IED cache in this area is already marked." << endl;
            } else if (currentRoom == CAVE && !weaponsCacheMarked) {
                cout << "You confirm crates of weapons and ammunition inside the cave." << endl;
                cout << "You record grid coordinates and mark the cache for follow-on forces." << endl;
                weaponsCacheMarked = true;
            } else if (currentRoom == CAVE && weaponsCacheMarked) {
                cout << "The weapons cache here is already marked." << endl;
            } else {
                cout << "Nothing here that needs to be marked for now." << endl;
            }
        } else if (command == "quit" || command == "q") {
            cout << "You call for early extraction and abort the mission." << endl;
            gameRunning = false;
        } else {
            cout << "I do not understand that command." << endl;
        }
    }
    
    cout << endl;
    cout << "End of mission simulation." << endl;
    return 0;
}
