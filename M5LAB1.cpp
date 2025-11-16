/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Kelevi Rakuita
[date]
Military Mission Edition

*/


#include <iostream>
using namespace std;

// Function Prototypes
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();

// new story branches
void choice_check_window();
void choice_try_cellar();
void choice_watch_briefing();
void choice_call_squad();

int main() {
    cout << "M5LAB1 - Choose Your Own Adventure (Military Mission)" << endl;
    // load up the main menu
    main_menu();
    // when we return here, we're done
    cout << "Mission complete. Dismissed!" << endl;
    return 0; // finished with no errors
}

void main_menu() {
    // Simple menu that lets the user choose 1, 2, 3, or 4 to quit.
    cout << "==============================" << endl;
    cout << "  OPERATION GHOST OUTPOST" << endl;
    cout << "==============================" << endl;
    cout << "You are a squad leader on a night recon mission." << endl;
    cout << "Intel reports an abandoned enemy safe house on the edge of the village." << endl;
    cout << "Your team is staged outside the compound walls." << endl;
    cout << "Do you:" << endl;
    cout << "1. Approach the main gate" << endl;
    cout << "2. Move around to the rear entrance" << endl;
    cout << "3. Call off the mission and RTB (return to base)" << endl;
    cout << "4. [Abort Simulation]" << endl;
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
        cout << "Simulation aborted. Exiting program." << endl;
        return; // go back to main()
    } else {
        cout << "Invalid input, soldier. Try again." << endl;
        cin.ignore(); // clear the user input
        main_menu();  // try again
    }
}

// FUNCTION DEFINITIONS

void choice_front_door() {
    cout << endl;
    cout << "You signal your fire team and move up to the main gate." << endl;
    cout << "The metal gate is chained and locked, with razor wire along the top." << endl;
    cout << "You hear nothing from inside the compound." << endl;
    cout << "Do you:" << endl;
    cout << "1. Shift to the rear entrance" << endl;
    cout << "2. Call the mission and RTB" << endl;

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (1 == choice) {
        choice_back_door();
    } else if (2 == choice) {
        choice_go_home();
    } else {
        cout << "You hold position too long at the gate." << endl;
        cout << "Your instincts kick in and you pull the team back to cover." << endl;
        cout << "Sometimes, caution keeps you alive." << endl;
    }
}

void choice_back_door() {
    cout << endl;
    cout << "You lead your team along the outer wall, staying low and quiet." << endl;
    cout << "At the rear of the compound, you find a small side door," << endl;
    cout << "a narrow ground-level window, and a stairwell leading down" << endl;
    cout << "to what looks like a basement entrance." << endl;
    cout << "Do you:" << endl;
    cout << "1. Check the small window for signs of life" << endl;
    cout << "2. Investigate the basement entrance" << endl;
    cout << "3. Decide the risk is too high and RTB" << endl;

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (1 == choice) {
        choice_check_window();
    } else if (2 == choice) {
        choice_try_cellar();
    } else if (3 == choice) {
        choice_go_home();
    } else {
        cout << "You hesitate, scanning the compound." << endl;
        cout << "With no clear plan, you pull your team back to the ORP and report in." << endl;
    }
}

void choice_go_home() {
    cout << endl;
    cout << "You key your radio and report: \"Command, this is Raider One.\"" << endl;
    cout << "\"Terrain and structure not matching earlier imagery. Recommend abort.\" " << endl;
    cout << "Command acknowledges and orders you to RTB." << endl;
    cout << "Back at the TOC, you're still thinking about that compound." << endl;
    cout << "Do you:" << endl;
    cout << "1. Watch the drone footage and review the intel briefing" << endl;
    cout << "2. Call your squad and talk through what happened" << endl;

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (1 == choice) {
        choice_watch_briefing();
    } else if (2 == choice) {
        choice_call_squad();
    } else {
        cout << "You grab some chow at the DFAC, then crash in the barracks," << endl;
        cout << "knowing there will always be another mission." << endl;
    }
}

// NEW BRANCHES

void choice_check_window() {
    cout << endl;
    cout << "You crouch below the window and slowly rise up to peek inside." << endl;
    cout << "Through your NVGs you see old tables, empty ammo crates," << endl;
    cout << "and maps pinned to the walls. No movement. No heat signatures." << endl;
    cout << "The window is unlocked. You quietly push it open and slide in." << endl;
    cout << "Your team clears room by room: no enemy, just abandoned gear." << endl;
    cout << "You secure a hard drive and documents for intel exploitation." << endl;
    cout << "You exfil clean. Mission success without firing a single round." << endl;
}

void choice_try_cellar() {
    cout << endl;
    cout << "You stack your team on the basement door." << endl;
    cout << "The air is cold and still. You give the signal and pull it open." << endl;
    cout << "Stale air and darkness rush out. You click on your weapon light." << endl;
    cout << "The concrete steps lead down to a small bunker." << endl;
    cout << "Inside you find old comms equipment and a generator, long powered off." << endl;
    cout << "Just as you step in, your radio crackles with an update:" << endl;
    cout << "\"Raider One, be advised, friendly drone strike scheduled near your grid.\"" << endl;
    cout << "You quickly mark the location, snap photos, and pull your team out." << endl;
    cout << "Sometimes the best fight is the one you don't stay for." << endl;
}

void choice_watch_briefing() {
    cout << endl;
    cout << "You sit down in front of the big screen in the TOC." << endl;
    cout << "Drone footage shows the compound from above." << endl;
    cout << "Your call to abort looks solid: unknown vehicles moved in" << endl;
    cout << "right after you left the area." << endl;
    cout << "Command updates the intel and flags the site as high priority." << endl;
    cout << "You realize your judgment probably saved your team." << endl;
}

void choice_call_squad() {
    cout << endl;
    cout << "You gather your squad in the team room." << endl;
    cout << "Some are frustrated the mission ended early; others are relieved." << endl;
    cout << "You walk through the timeline, talk about what went right," << endl;
    cout << "and what you could do better next time." << endl;
    cout << "By the end, morale is high and everyone is ready for the next op." << endl;
}
