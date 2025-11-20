/*
CSC 134
M6LAB1 - Buckshot Roulette (Slime Magazine Demo)
Kelevi Rakuita  
11/20/2025

Description:
Minimal version of the Buckshot Roulette lab.
- Load a slime gun magazine with LIVE and BLANK shells
- Use a vector to store the shells
- Shuffle the shells
- Eject shells one by one and show what each shell is
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void showIntro();
vector<string> loadMagazine(int totalShells, int liveShells);
void shuffleMagazine(vector<string> &magazine);
void printMagazine(const vector<string> &magazine);
void ejectShells(vector<string> &magazine);

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    showIntro();

    int totalShells = 6;   // size of the magazine
    int liveShells = 3;    // number of LIVE shells (rest will be BLANK)

    cout << "Loading magazine with " << totalShells << " shells." << endl;
    cout << liveShells << " of them will be LIVE shells." << endl;
    cout << (totalShells - liveShells) << " of them will be BLANK shells." << endl << endl;

    // Load and shuffle the magazine
    vector<string> magazine = loadMagazine(totalShells, liveShells);
    shuffleMagazine(magazine);

    cout << "Magazine loaded. Here are the shells (from first to last):" << endl;
    printMagazine(magazine);
    cout << endl;

    // Eject shells one by one
    ejectShells(magazine);

    cout << endl << "All shells have been ejected." << endl;
    cout << "End of M6LAB1 demo." << endl;

    return 0;
}

// Show intro text
void showIntro() {
    cout << "----------------------------------------" << endl;
    cout << "            M6LAB1 - Buckshot           " << endl;
    cout << "          Slime Magazine Demo           " << endl;
    cout << "----------------------------------------" << endl;
    cout << "This program loads a slime gun magazine" << endl;
    cout << "with LIVE and BLANK shells using a vector." << endl;
    cout << "Then it ejects each shell and shows what it was." << endl << endl;
}

// Create a magazine vector with LIVE and BLANK shells
vector<string> loadMagazine(int totalShells, int liveShells) {
    vector<string> magazine;

    // Add LIVE shells
    for (int i = 0; i < liveShells; i++) {
        magazine.push_back("LIVE");
    }

    // Add BLANK shells
    int blankShells = totalShells - liveShells;
    for (int i = 0; i < blankShells; i++) {
        magazine.push_back("BLANK");
    }

    return magazine;
}

// Shuffle the magazine
void shuffleMagazine(vector<string> &magazine) {
    int n = static_cast<int>(magazine.size());
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        string temp = magazine[i];
        magazine[i] = magazine[j];
        magazine[j] = temp;
    }
}

// Print the magazine contents
void printMagazine(const vector<string> &magazine) {
    for (int i = 0; i < static_cast<int>(magazine.size()); i++) {
        cout << i << ": " << magazine[i] << endl;
    }
}

// Eject shells one by one (from the back of the vector)
void ejectShells(vector<string> &magazine) {
    cout << "Now ejecting shells one by one..." << endl << endl;

    // While there are shells left
    while (!magazine.empty()) {
        int lastIndex = static_cast<int>(magazine.size()) - 1;

        cout << "Shell ejected: " << magazine[lastIndex] << endl;

        // Remove the last shell from the magazine
        magazine.pop_back();
    }
}
