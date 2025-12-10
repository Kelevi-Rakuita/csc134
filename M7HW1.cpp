/*
CSC 134
M7HW1 - Mini Project
Shoot House: Mission Rehearsal
Kelevi Rakuita
12/10/2025
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum OccupantType {
    EMPTY = 0,
    HOSTILE = 1,
    CIVILIAN = 2
};

struct Room {
    string name;
    OccupantType occupant;
    bool cleared;
};

void show_intro();
int get_menu_choice(int min, int max);
void setup_rooms(vector<Room> &rooms);
void brief_room(const Room &room);
void run_room(Room &room, int &score, int &shots_fired, int &civilians_hit);
void show_after_action_report(const vector<Room> &rooms, int score, int shots_fired, int civilians_hit);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Room> shoot_house;
    int score = 0;
    int shots_fired = 0;
    int civilians_hit = 0;

    show_intro();
    setup_rooms(shoot_house);

    for (size_t i = 0; i < shoot_house.size(); i++) {
        cout << "----------" << endl;
        cout << "Approaching " << shoot_house[i].name << "..." << endl;
        brief_room(shoot_house[i]);
        run_room(shoot_house[i], score, shots_fired, civilians_hit);
    }

    show_after_action_report(shoot_house, score, shots_fired, civilians_hit);

    cout << "Press Enter to exit." << endl;
    cin.get();
    return 0;
}

void show_intro() {
    cout << "==============================================" << endl;
    cout << "   SHOOT HOUSE: MISSION REHEARSAL" << endl;
    cout << "==============================================" << endl;
    cout << "You are the team leader for a special operations unit." << endl;
    cout << "Tonight you hit the shoot house to rehearse for a real raid." << endl;
    cout << "Each room may contain:" << endl;
    cout << "  - HOSTILE target (shoot)" << endl;
    cout << "  - CIVILIAN (no-shoot)" << endl;
    cout << "  - EMPTY room" << endl;
    cout << "You will choose how to enter and whether to fire." << endl;
    cout << "Good judgment under stress is the goal." << endl;
}

int get_menu_choice(int min, int max) {
    int choice;
    while (true) {
        cout << "> ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.clear();
            cin.ignore(10000, ' ');
            return choice;
        }
        cout << "Invalid choice. Try again." << endl;
        cin.clear();
        cin.ignore(10000, ' ');
    }
}

void setup_rooms(vector<Room> &rooms) {
    rooms.clear();

    Room r1{"Room 1 - Entry", EMPTY, false};
    Room r2{"Room 2 - Hallway Corner", EMPTY, false};
    Room r3{"Room 3 - Hostage Room", EMPTY, false};
    Room r4{"Room 4 - Final Room", EMPTY, false};

    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    rooms.push_back(r4);

    for (size_t i = 0; i < rooms.size(); i++) {
        int roll = rand() % 3;
        rooms[i].occupant = static_cast<OccupantType>(roll);
    }
}

void brief_room(const Room &room) {
    cout << "Intel: ";
    if (room.name.find("Hostage") != string::npos) {
        cout << "Possible hostage presence. Positive ID required." << endl;
    } else if (room.name.find("Hallway") != string::npos) {
        cout << "Tight corner. Threat may be close." << endl;
    } else if (room.name.find("Final") != string::npos) {
        cout << "Last room. Threat may be barricaded." << endl;
    } else {
        cout << "Unknown threat level." << endl;
    }

    cout << "Choose entry method:" << endl;
    cout << " 1) Slow and deliberate" << endl;
    cout << " 2) Dynamic breach" << endl;
    cout << " 3) Flashbang then enter" << endl;

    int choice = get_menu_choice(1, 3);

    if (choice == 1)
        cout << "You pie the corner, clearing sectors one by one..." << endl;
    else if (choice == 2)
        cout << "You kick the door and flow into the room quickly..." << endl;
    else
        cout << "You toss a flashbang and enter on the blast..." << endl;
}

void run_room(Room &room, int &score, int &shots_fired, int &civilians_hit) {
    cout << "You see a silhouette!" << endl;
    cout << "Do you:" << endl;
    cout << " 1) SHOOT" << endl;
    cout << " 2) HOLD FIRE" << endl;

    int action = get_menu_choice(1, 2);
    bool fired = (action == 1);

    if (fired)
        shots_fired++;

    cout << "Result: ";
    if (room.occupant == HOSTILE) {
        if (fired) {
            cout << "Threat neutralized. Good shoot." << endl;
            score += 10;
        } else {
            cout << "You hesitated. Hostile would have shot you." << endl;
            score -= 5;
        }
    } else if (room.occupant == CIVILIAN) {
        if (fired) {
            cout << "You shot a civilian." << endl;
            civilians_hit++;
            score -= 15;
        } else {
            cout << "Correct. You held fire on a civilian." << endl;
            score += 5;
        }
    } else {
        if (fired) {
            cout << "Empty room. You fired at a shadow." << endl;
            score -= 2;
        } else {
            cout << "Room was empty. Good trigger discipline." << endl;
            score += 1;
        }
    }

    room.cleared = true;
}

void show_after_action_report(const vector<Room> &rooms, int score, int shots_fired, int civilians_hit) {
    cout << "==============================================" << endl;
    cout << " AFTER ACTION REPORT (AAR)" << endl;
    cout << "==============================================" << endl;

    cout << "Rooms cleared: " << rooms.size() << endl;
    cout << "Shots fired: " << shots_fired << endl;
    cout << "Civilians hit: " << civilians_hit << endl;
    cout << "Final score: " << score << endl;

    if (score >= 25)
        cout << "Assessment: Mission ready." << endl;
    else if (score >= 10)
        cout << "Assessment: Tighten threat ID." << endl;
    else if (score >= 0)
        cout << "Assessment: Needs more training." << endl;
    else
        cout << "Assessment: Unsafe performance." << endl;

    cout << "Train as you fight." << endl;
}
