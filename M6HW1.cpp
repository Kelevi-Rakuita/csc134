/*
CSC 134
M6HW1 - Bronze
Kelevi Rakuita
12/3/25

*/

#include <iostream>
#include <string>
using namespace std;

// Directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Rooms
enum Room {
    LZ = 0,
    TRAIL = 1,
    COMPOUND = 2,
    NUM_ROOMS = 3
};

int main() {
    // ==========================
    // BRONZE: 3 ROOMS + EXITS
    // ==========================
    string roomNames[NUM_ROOMS] = {
        "Landing Zone (LZ)",
        "Mountain Trail",
        "Insurgent Compound (outside gate)"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "You’re at the LZ. The helicopter has just dropped you off in the mountains.",
        "You’re on a narrow mountain trail with loose rocks and sharp turns.",
        "You’re outside a small compound with mud-brick walls and a metal gate."
    };

    // exits[room][direction] = next room, or -1 if no exit
    int exits[NUM_ROOMS][NUM_DIRECTIONS] = {
        // From LZ: only north to TRAIL
        /* LZ */       { TRAIL, -1, -1, -1 },
        // From TRAIL: north to COMPOUND, south back to LZ
        /* TRAIL */    { COMPOUND, -1, LZ, -1 },
        // From COMPOUND: south back to TRAIL
        /* COMPOUND */ { -1, -1, TRAIL, -1 }
    };

    int currentRoom = LZ;
    bool playing = true;

    cout << "CSC134 - M6HW1 PROJECT PROTOTYPE (BRONZE)";
    cout << "Special Ops: Mountain Patrol\n\n";

    while (playing) {
        cout << "====================================";
        cout << "Location: " << roomNames[currentRoom] << "";
        cout << roomDescriptions[currentRoom] << "";

        cout << "You can try moving north or south.";
        cout << "Commands:";
        cout << "  n = move north";
        cout << "  s = move south";
        cout << "  q = quit";
        cout << "> ";

        char cmd;
        cin >> cmd;
        cout << "";

        if (cmd == 'q' || cmd == 'Q') {
            cout << "You radio for extract. Mission over.";
            playing = false;
        } else if (cmd == 'n' || cmd == 'N') {
            int nextRoom = exits[currentRoom][NORTH];
            if (nextRoom == -1) {
                cout << "You can't go further north from here.";
            } else {
                cout << "You move north...";
                currentRoom = nextRoom;
            }
        } else if (cmd == 's' || cmd == 'S') {
            int nextRoom = exits[currentRoom][SOUTH];
            if (nextRoom == -1) {
                cout << "You can't go further south from here.";
            } else {
                cout << "You move south...";
                currentRoom = nextRoom;
            }
        } else {
            cout << "Unknown command. Try n, s, or q.";
        }
    }

    cout << "Thanks for playing.";
    return 0;
}
