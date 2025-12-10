/*
Special Operations Roguelike
CSC 134 Final Project
Kelevi Rakuita
12/7/2025
Afghanistan mountain mission: Locate and destroy IED cache

*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

// small helper to print a line then pause for readability (~250 ms)
void pl(const string &s, int ms = 250) {
    cout << s << '\n';
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// -------------------- Basic types --------------------
struct Attack {
    string name;
    int minDamage;
    int maxDamage;
    bool isRanged;
    int chargeTurns;       // number of turns required to charge before firing
    bool selfDestruct;     // if true, attacker dies when attack fires

    Attack(string n = "", int minD = 0, int maxD = 0, bool ranged = false,
           int charge = 0, bool selfDes = false)
        : name(n), minDamage(minD), maxDamage(maxD), isRanged(ranged),
          chargeTurns(charge), selfDestruct(selfDes) {}

    int getDamage() const {
        if (maxDamage <= minDamage) return minDamage;
        return minDamage + (rand() % (maxDamage - minDamage + 1));
    }
};

struct EnemyType {
    string name;
    int maxHealth;
    vector<Attack> attacks;
    bool isBoss = false;
};

struct EnemyActionResult {
    int damage;         // damage dealt this turn (0 if charging or no damage)
    string message;     // message to print
    bool attackerDied;  // true if the enemy killed itself (self-destruct)
    EnemyActionResult(int d = 0, string m = "", bool died = false) : damage(d), message(m), attackerDied(died) {}
};

class Enemy {
    EnemyType type;
    int health;

    // charging state
    Attack pendingAttack;
    int chargeRemaining; // turns left before pendingAttack fires
    bool hasPending;

public:
    Enemy(const EnemyType& t) : type(t), health(t.maxHealth), chargeRemaining(0), hasPending(false) {}

    string getName() const { return type.name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return type.maxHealth; }
    bool alive() const { return health > 0; }

    Attack chooseAttack() const {
        if (type.attacks.empty()) return Attack("Rifle Butt", 1, 2, false);
        int idx = rand() % type.attacks.size();
        return type.attacks[idx];
    }

    void startCharging(const Attack &a) {
        pendingAttack = a;
        chargeRemaining = max(1, a.chargeTurns);
        hasPending = true;
    }

    EnemyActionResult takeTurn() {
        if (!alive()) return EnemyActionResult(0, getName() + " is neutralized.", false);

        if (hasPending) {
            if (chargeRemaining > 1) {
                chargeRemaining--;
                return EnemyActionResult(0, getName() + " continues setting up " + pendingAttack.name + ".", false);
            } else {
                int dmg = pendingAttack.getDamage();
                string msg = getName() + " executes " + pendingAttack.name + " for " + to_string(dmg) + " damage!";
                bool died = false;
                if (pendingAttack.selfDestruct) {
                    health = 0;
                    died = true;
                    msg += " " + getName() + " is taken out in the blast!";
                }
                hasPending = false;
                chargeRemaining = 0;
                return EnemyActionResult(dmg, msg, died);
            }
        }

        Attack a = chooseAttack();
        if (a.chargeTurns > 0) {
            startCharging(a);
            return EnemyActionResult(0, getName() + " begins preparing " + a.name + ".", false);
        } else {
            int dmg = a.getDamage();
            string msg = getName() + " uses " + a.name + " for " + to_string(dmg) + " damage!";
            return EnemyActionResult(dmg, msg, false);
        }
    }

    void takeDamage(int d) {
        health -= d;
        if (health < 0) health = 0;
    }

    bool isBoss() const { return type.isBoss; }
};

// -------------------- Faction enemy pools --------------------
// You’re in the Afghanistan mountains; each “faction” is a different route / sector
// but we reuse internal variable names for simplicity.

vector<EnemyType> hiveEnemies = {
    {"Lookout Scout", 60, {
        Attack("AK Burst", 4, 9, true),
        Attack("Rushed Spray", 6, 11, true)
    }},
    {"Rifleman", 80, {
        Attack("Controlled Burst", 6, 13, true)
    }},
    {"Suicide Bomber", 70, {
        Attack("Body-borne IED", 60, 80, false, 2, true)
    }},
    {"Machine Gun Nest", 170, {
        Attack("Sustained Fire", 11, 20, true),
        Attack("Spray and Pray", 11, 18, true)
    }},
    {"RPG Gunner", 140, {
        Attack("RPG Shot", 13, 22, true),
        Attack("Grenade Volley", 11, 20, true)
    }},
    {"Heavy Gunner", 260, {
        Attack("PKM Burst", 16, 28, true),
        Attack("Mounted Gun Sweep", 24, 34, true, 2, false)
    }}
};

vector<EnemyType> fallenEnemies = {
    {"Hill Fighter", 44, {
        Attack("Single Shot", 4, 9, true),
        Attack("Short Burst", 6, 13, true)
    }},
    {"Ambush Cell", 82, {
        Attack("Crossfire", 7, 15, true),
        Attack("Close Assault", 6, 11, false)
    }},
    {"Demolitions Expert", 95, {
        Attack("Grenade Toss", 9, 18, true),
        Attack("Remote Charge", 11, 20, false)
    }},
    {"Spotter Drone", 33, {
        Attack("Drone Strike", 3, 7, true),
        Attack("Shrapnel Blast", 4, 9, true)
    }},
    {"Mortar Team", 120, {
        Attack("Indirect Fire", 11, 20, true)
    }},
    {"Cell Leader", 132, {
        Attack("Coordinated Volley", 14, 22, true),
        Attack("Close Quarter Attack", 17, 27, false)
    }}
};

vector<EnemyType> vexEnemies = {
    {"Ridge Marksman", 88, {
        Attack("Scoped Shot", 11, 20, true),
        Attack("Buttstroke", 10, 15, false)
    }},
    {"Tunnel Fighter", 77, {
        Attack("Blind Fire", 9, 18, true),
        Attack("Knife Flurry", 8, 13, false)
    }},
    {"Technical Truck", 200, {
        Attack("Heavy Machine Gun", 18, 30, true),
        Attack("Ram Attempt", 13, 22, false)
    }},
    {"Bunker Team", 160, {
        Attack("Interlocking Fire", 15, 24, true),
        Attack("Grenade Trap", 10, 18, false)
    }},
    {"Flanker Team", 66, {
        Attack("Flanking Burst", 8, 15, true),
        Attack("Rush", 6, 13, false)
    }},
    {"Hilltop Strongpoint", 300, {
        Attack("Enfilade Fire", 28, 44, true),
        Attack("Shock-and-Awe Volley", 24, 38, true)
    }}
};

// Boss templates (one per route/sector)
EnemyType hiveBoss   = {"IED Cache Commander", 440, {
    Attack("Coordinated Ambush", 32, 48, true),
    Attack("Pre-planned IED Strike", 38, 54, false, 2, false)
}, true};

EnemyType fallenBoss = {"Foreign Fighter Commander", 380, {
    Attack("Overwatch Killzone", 30, 44, true),
    Attack("Mortar Barrage", 32, 46, true)
}, true};

EnemyType vexBoss    = {"Mountain Stronghold Leader", 460, {
    Attack("Heavy Weapon Barrage", 34, 52, true),
    Attack("Coordinated Assault", 30, 44, false)
}, true};

// -------------------- Player --------------------
enum ClassType { ASSAULTER, MEDIC, SNIPER };

struct Ability {
    string name;
    int cooldownMax;
    int cooldown; // turns remaining
    int power; // effect magnitude (damage or heal or overshield)
    string desc;
    Ability(string n = "", int cd = 0, int p = 0, string d = "") : name(n), cooldownMax(cd), cooldown(0), power(p), desc(d) {}
    bool ready() const { return cooldown == 0; }
    void use() { cooldown = cooldownMax; }
    void tick() { if (cooldown > 0) --cooldown; }
};

class Player {
    string name;
    ClassType cls;
    int maxHealth;
    int health;
    int baseDamageMin;
    int baseDamageMax;
    int weaponBoost; // loot increases this
    int overshield;  // separate overshield value (body armor / extra protection)
    vector<Ability> abilities;
public:
    Player(string n, ClassType c) : name(n), cls(c), weaponBoost(0), overshield(0) {
        if (c == ASSAULTER) {
            maxHealth = 260; health = maxHealth;
            baseDamageMin = 16; baseDamageMax = 24;
            abilities.push_back(Ability("Frag Grenade", 4, 80, "High explosive vs clustered enemies"));
            abilities.push_back(Ability("Breaching Charge", 5, 50, "Powerful directional blast"));
            abilities.push_back(Ability("Ballistic Shield Push", 3, 30, "Damage + gain extra protection"));
            abilities.push_back(Ability("Adrenaline Rush", 5, 60, "Gain a strong temporary armor boost"));
        } else if (c == MEDIC) {
            maxHealth = 180; health = maxHealth;
            baseDamageMin = 18; baseDamageMax = 26;
            abilities.push_back(Ability("CAS Airstrike", 5, 100, "Call in close air support on all hostiles"));
            abilities.push_back(Ability("Field Medkit", 6, 60, "Patch yourself up under fire"));
            abilities.push_back(Ability("Suppressive Fire", 4, 60, "Focused fire on one target"));
        } else { // SNIPER
            maxHealth = 150; health = maxHealth;
            baseDamageMin = 22; baseDamageMax = 34;
            abilities.push_back(Ability("Precision Shot", 3, 80, "Well-placed round on vital target"));
            abilities.push_back(Ability("Close-Quarters Strike", 4, 36, "Buttstroke + sidearm combo"));
            abilities.push_back(Ability("Smoke Grenade", 5, 20, "Deploy smoke, reducing incoming damage"));
            abilities.push_back(Ability("Evasive Maneuver", 6, 30, "Roll to cover and counter-attack"));
        }
    }

    string getClassName() const {
        if (cls == ASSAULTER) return "Assaulter";
        if (cls == MEDIC) return "Combat Medic";
        return "Marksman";
    }

    int attackDamage() const {
        int base = baseDamageMin + (rand() % (baseDamageMax - baseDamageMin + 1));
        return base + weaponBoost;
    }

    bool alive() const { return health > 0; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getOvershield() const { return overshield; }

    // Damage first reduces overshield, then HP
    void takeDamage(int d) {
        if (d <= 0) return;
        if (overshield > 0) {
            if (d <= overshield) {
                overshield -= d;
                return;
            } else {
                d -= overshield;
                overshield = 0;
            }
        }
        health -= d;
        if (health < 0) health = 0;
    }

    // heal and report actual healed amount
    void heal(int amount) {
        if (amount <= 0) return;
        int before = health;
        health += amount;
        if (health > maxHealth) health = maxHealth;
        int actual = health - before;
        if (actual > 0) {
            pl("You stabilize and regain " + to_string(actual) + " HP");
        } else {
            pl("No additional effect; you're already topped off");
        }
    }

    // add overshield and report amount gained
    void addOvershield(int amount) {
        if (amount <= 0) return;
        overshield += amount;
        pl("You increase your protection by " + to_string(amount) + " (armor / cover bonus)");
    }

    vector<Ability>& getAbilities() { return abilities; }

    // Use ability index on a single enemy (returns damage dealt or -1 for non-damage ability)
    int useAbility(int idx, Enemy &target, vector<Enemy>& enemies) {
        if (idx < 0 || idx >= (int)abilities.size()) return -2;
        Ability &a = abilities[idx];
        if (!a.ready()) return -3;
        int dmg = 0;
        string clsName = getClassName();
        if (clsName == "Assaulter") {
            if (a.name == "Frag Grenade") {
                dmg = a.power + (rand() % 11);
                target.takeDamage(dmg);
            } else if (a.name == "Breaching Charge") {
                dmg = a.power - 10 + (rand() % 21);
                target.takeDamage(dmg);
            } else if (a.name == "Ballistic Shield Push") {
                // damage + grant armor
                dmg = a.power/2 + (rand() % 11);
                target.takeDamage(dmg);
                int os = a.power/3;
                addOvershield(os);
            } else if (a.name == "Adrenaline Rush") {
                addOvershield(a.power);
            }
        } else if (clsName == "Combat Medic") {
            if (a.name == "CAS Airstrike") {
                for (Enemy &e : enemies) {
                    if (!e.alive()) continue;
                    int ed = a.power/2 + (rand() % (a.power/2));
                    e.takeDamage(ed);
                }
                dmg = a.power; // total effect
            } else if (a.name == "Field Medkit") {
                int healAmt = a.power/2;
                heal(healAmt);
            } else if (a.name == "Suppressive Fire") {
                dmg = a.power + (rand() % 16);
                target.takeDamage(dmg);
            }
        } else { // Marksman
            if (a.name == "Precision Shot") {
                dmg = a.power + (rand() % 16);
                target.takeDamage(dmg);
            } else if (a.name == "Close-Quarters Strike") {
                dmg = a.power/2 + (rand() % 12);
                target.takeDamage(dmg);
            } else if (a.name == "Smoke Grenade") {
                addOvershield(12);
            } else if (a.name == "Evasive Maneuver") {
                dmg = a.power + (rand() % 8);
                target.takeDamage(dmg);
                addOvershield(8);
            }
        }
        a.use();
        return dmg;
    }

    void tickCooldowns() {
        for (auto &a : abilities) a.tick();
    }

    void addWeaponBoost(int b) { weaponBoost += b; }
    int getWeaponBoost() const { return weaponBoost; }

    // status string for printing
    string statusString() const {
        return to_string(health) + "/" + to_string(maxHealth) + " (Armor Buffer: " + to_string(overshield) + ")";
    }
};

// -------------------- Utility --------------------
int getIntInput(int minv, int maxv) {
    int choice;
    while (true) {
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pl("Please enter a number: ");
            continue;
        }
        if (choice < minv || choice > maxv) {
            pl("Enter a number between " + to_string(minv) + " and " + to_string(maxv) + ": ");
            continue;
        }
        break;
    }
    return choice;
}

bool getYesNo(const string &prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        string s;
        if (!(cin >> s)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (s.empty()) continue;
        char c = tolower(s[0]);
        if (c == 'y') return true;
        if (c == 'n') return false;
        pl("Please enter 'y' or 'n'.");
    }
}

EnemyType randomFrom(const vector<EnemyType>& pool) {
    int idx = rand() % pool.size();
    return pool[idx];
}

// Spawn enemies for a round based on count and sector
vector<Enemy> spawnEnemiesForRound(int round, const vector<EnemyType>& pool, const EnemyType& bossType) {
    vector<Enemy> enemies;
    if (round == 5 || round == 10 || round == 15) {
        EnemyType boss = bossType;
        double bossMult = 1.0;
        if (round == 10) bossMult = 1.05;
        if (round == 15) bossMult = 1.1;
        boss.maxHealth = int(boss.maxHealth * bossMult);
        enemies.push_back(Enemy(boss));
        return enemies;
    }
    int count = 1;
    if (round >= 1 && round <= 3) count = 1;
    else if (round == 4 || (round >= 6 && round <= 8)) count = 2;
    else if (round >= 9 && round <= 14) {
        if (round == 10) count = 1;
        else count = 3;
    }

    double roundMult = 1.0;
    if (round <= 3) roundMult = 0.95;
    else if (round <= 5) roundMult = 1.05;
    else if (round <= 8) roundMult = 1.15;
    else if (round <= 12) roundMult = 1.30;
    else roundMult = 1.40;

    for (int i = 0; i < count; ++i) {
        EnemyType et = randomFrom(pool);
        et.maxHealth = max(1, int(et.maxHealth * roundMult));
        enemies.push_back(Enemy(et));
    }
    return enemies;
}

void printEnemyStatus(const vector<Enemy>& enemies) {
    pl("Contacts in the area:");
    for (size_t i = 0; i < enemies.size(); ++i) {
        pl("  [" + to_string(i+1) + "] " + enemies[i].getName() + " (" + to_string(enemies[i].getHealth()) + "/" + to_string(enemies[i].getMaxHealth()) + ")");
    }
}

// -------------------- Game run (single playthrough) --------------------
bool runPlaythrough() {
    // Choose sector / route for this mission
    vector<string> sectors = {"Valley Route", "Ridgeline Sector", "Village Network"};
    int sectorChoice = rand() % sectors.size();
    string sector = sectors[sectorChoice];
    if (sector == "Valley Route") {
        pl("Intel: Enemy activity along a mountain valley route. Possible IED cache nearby.");
    } else if (sector == "Ridgeline Sector") {
        pl("Intel: Multiple firing positions reported along the ridgeline. Expect heavy contact.");
    } else if (sector == "Village Network") {
        pl("Intel: Enemy cells operating between remote mountain villages. IED facilitation suspected.");
    }
    pl("");

    // Choose enemy pool and boss based on sector
    vector<EnemyType> enemyPool;
    EnemyType bossType;
    if (sector == "Valley Route") { enemyPool = hiveEnemies; bossType = hiveBoss; }
    else if (sector == "Ridgeline Sector") { enemyPool = fallenEnemies; bossType = fallenBoss; }
    else { enemyPool = vexEnemies; bossType = vexBoss; }

    // Player creation
    pl("Special Ops Team – choose your role:");
    pl("1) Assaulter (high HP, strong close combat)");
    pl("2) Combat Medic (balanced, can heal and call CAS)");
    pl("3) Marksman (lower HP, high precision damage)");
    cout << "Enter choice: ";
    int c = getIntInput(1,3);
    ClassType chosen = (c==1?ASSAULTER:(c==2?MEDIC:SNIPER));
    cout << "Enter your callsign: ";
    string pname;
    cin >> pname;
    Player player(pname, chosen);
    pl("Welcome, " + pname + " – " + player.getClassName() + " attached to a special operations team in the Afghanistan mountains.");
    pl("Mission: Fight through 15 engagements, locate, and destroy the main IED cache.");
    pl("");

    // Rounds 1..15
    for (int round = 1; round <= 15; ++round) {
        pl("-----------------------------");
        pl("Contact " + to_string(round));

        // Spawn enemies
        vector<Enemy> enemies = spawnEnemiesForRound(round, enemyPool, bossType);
        if (enemies.empty()) {
            pl("No enemy contact this phase.");
            continue;
        }

        // Combat loop for this contact
        while (player.alive() && any_of(enemies.begin(), enemies.end(), [](const Enemy& e){ return e.alive(); })) {
            pl("\nStatus – You: " + player.statusString());
            printEnemyStatus(enemies);

            // Player turn: repeat until a valid action is taken
            bool actionTaken = false;
            while (!actionTaken) {
                pl("\nChoose action:");
                pl("1) Standard Fire");
                pl("2) Use Ability");
                cout << "Enter: ";
                int action = getIntInput(1,2);

                if (action == 1) {
                    cout << "Select target number: ";
                    int t = getIntInput(1, (int)enemies.size()) - 1;
                    if (!enemies[t].alive()) {
                        pl("That contact is already down. You waste the burst.");
                    } else {
                        int dmg = player.attackDamage();
                        enemies[t].takeDamage(dmg);
                        pl("You engage " + enemies[t].getName() + " for " + to_string(dmg) + " damage.");
                    }
                    actionTaken = true;
                } else if (action == 2) {
                    auto &abs = player.getAbilities();
                    bool anyReady = false;
                    for (auto &ab : abs) if (ab.ready()) { anyReady = true; break; }

                    pl("Abilities (enter 0 to go back):");
                    for (size_t i = 0; i < abs.size(); ++i) {
                        pl("  " + to_string(i+1) + ") " + abs[i].name + " (CD: " + to_string(abs[i].cooldown) + "/" + to_string(abs[i].cooldownMax) + ") - " + abs[i].desc);
                    }
                    if (!anyReady) pl("All abilities are on cooldown. Press 0 to go back and choose another action.");

                    cout << "Choose ability number (0 to cancel): ";
                    int ai = getIntInput(0, (int)abs.size()) - 1;
                    if (ai == -1) {
                        pl("Returning to action selection...");
                        continue;
                    }

                    int targetIndex = 0;
                    if (!enemies.empty()) {
                        cout << "Select target number: ";
                        targetIndex = getIntInput(1, (int)enemies.size()) - 1;
                    }
                    int res = player.useAbility(ai, enemies[targetIndex], enemies);
                    if (res == -2) pl("Invalid ability.");
                    else if (res == -3) pl("That ability is still on cooldown.");
                    else {
                        pl("You execute: " + abs[ai].name + ".");
                        if (res > 0) pl("It inflicts " + to_string(res) + " damage (or equivalent effect).");
                        actionTaken = true;
                    }
                }
            } // end player action loop

            // Enemies' turn: each enemy acts
            for (size_t i = 0; i < enemies.size(); ++i) {
                EnemyActionResult ar = enemies[i].takeTurn();
                pl(ar.message);
                if (ar.damage > 0) {
                    player.takeDamage(ar.damage);
                    pl("You take " + to_string(ar.damage) + " damage. (Current: " + player.statusString() + ")");
                }
                if (ar.attackerDied) {
                    pl(enemies[i].getName() + " is eliminated in the blast.");
                }
                if (!player.alive()) break;
            }

            // tick cooldowns
            player.tickCooldowns();

            if (!player.alive()) {
                pl("You’re hit and unable to continue on contact " + to_string(round) + ". Mission failed.");
                bool again = getYesNo("Run the mission again?");
                return again;
            }
        } // end combat loop

        pl("Contact " + to_string(round) + " cleared.");
        player.heal(20); // small post-contact recovery
        pl("You take a short pause to reset. (" + player.statusString() + ")");

        // Random post-round event: offer elite contact or rest (30% chance)
        int eventRoll = rand() % 100;
        if (eventRoll < 30 && round != 15) {
            pl("\nIntel reports a high-value hostile team nearby. Do you:");
            pl("1) Interdict the elite element for potential intel and upgraded gear");
            pl("2) Bypass and rest (heal 25)");
            cout << "Enter: ";
            int choice = getIntInput(1,2);
            if (choice == 1) {
                EnemyType elite = randomFrom(enemyPool);
                elite.name = "Elite " + elite.name;
                elite.maxHealth = int(elite.maxHealth * 1.5);
                for (auto &a : elite.attacks) {
                    a.minDamage = int(a.minDamage * 1.2);
                    a.maxDamage = int(a.maxDamage * 1.2);
                }
                Enemy e(elite);
                pl("You move to contact with " + e.getName() + " (" + to_string(e.getHealth()) + " HP).");

                // elite duel loop
                while (player.alive() && e.alive()) {
                    pl("Your status: " + player.statusString());
                    pl("Enemy: " + e.getName() + " (" + to_string(e.getHealth()) + "/" + to_string(e.getMaxHealth()) + ")");
                    pl("1) Standard Fire  2) Ability");
                    cout << "Choose: ";
                    int a = getIntInput(1,2);
                    if (a == 1) {
                        int dmg = player.attackDamage();
                        e.takeDamage(dmg);
                        pl("You fire and hit for " + to_string(dmg) + ". " + e.getName() + " HP: " + to_string(e.getHealth()));
                    } else {
                        auto &abs = player.getAbilities();
                        bool anyReady = false;
                        for (auto &ab : abs) if (ab.ready()) { anyReady = true; break; }

                        pl("Abilities (enter 0 to go back):");
                        for (size_t i = 0; i < abs.size(); ++i) {
                            pl("  " + to_string(i+1) + ") " + abs[i].name + " (CD " + to_string(abs[i].cooldown) + ")");
                        }
                        if (!anyReady) pl("All abilities are on cooldown. Press 0 to choose another option.");

                        cout << "Choose ability (0 to cancel): ";
                        int ai = getIntInput(0, (int)abs.size()) - 1;
                        if (ai == -1) {
                            pl("Returning to duel action selection...");
                            continue;
                        }
                        vector<Enemy> tmp; // empty for signature
                        int res = player.useAbility(ai, e, tmp);
                        if (res >= 0) pl("Ability inflicts " + to_string(res) + " damage.");
                        else if (res == -3) pl("Ability still on cooldown.");
                    }

                    // Elite's turn
                    if (e.alive()) {
                        EnemyActionResult ar = e.takeTurn();
                        pl(ar.message);
                        if (ar.damage > 0) {
                            player.takeDamage(ar.damage);
                            pl("You take " + to_string(ar.damage) + " damage. (Current: " + player.statusString() + ")");
                        }
                        if (ar.attackerDied) pl(e.getName() + " is taken out by its own device.");
                    }

                    player.tickCooldowns();

                    if (!player.alive()) {
                        pl("You are overwhelmed by the elite element. Mission failed.");
                        bool again = getYesNo("Run the mission again?");
                        return again;
                    }
                }

                if (player.alive()) {
                    pl("Elite element neutralized. You recover upgraded weapon components (+2 damage).");
                    player.addWeaponBoost(2);
                } else {
                    pl("You are taken out by the elite team. Mission failed.");
                    bool again = getYesNo("Run the mission again?");
                    return again;
                }
            } else {
                pl("You choose to bypass and rest, regaining 25 HP.");
                player.heal(25);
                pl("Current status: " + player.statusString());
            }
        }

        // Boss reward on boss contacts
        if (round == 5 || round == 10 || round == 15) {
            if (round == 15) {
                pl("You overrun the final compound and locate the main IED cache.");
                pl("You secure the site and call in EOD to destroy the explosives.");
            } else {
                pl("High-value commander neutralized. You capture critical intel and resources.");
            }
            pl("Reward: Major weapon upgrade (+6 damage) and full recovery.");
            player.addWeaponBoost(6);
            player.heal(player.getMaxHealth());
            pl("Updated status: " + player.statusString());
        }

        // small checkpoint
        pl("End of contact " + to_string(round) + ". Current status: " + player.statusString());
        pl("");
    } // end contacts

    // Player survived all contacts
    pl("Mission complete.");
    pl("You and your team fought through 15 engagements in the Afghan mountains,");
    pl("located the primary IED cache, and oversaw its destruction.");
    pl("Final stats:");
    pl("HP: " + player.statusString());
    pl("Weapon effectiveness bonus: (+" + to_string(player.getWeaponBoost()) + ")");
    pl("Outstanding work, operator.");
    bool again = getYesNo("Run the mission again?");
    return again;
}

// -------------------- Main --------------------
int main() {
    srand((unsigned)time(0));
    pl("=== Mountain Ops: Special Operations IED Hunt ===");
    pl("Setting: Afghanistan mountains. You lead a small special operations element.");
    pl("");

    while (true) {
        bool playAgain = runPlaythrough();
        if (!playAgain) {
            pl("RTB. Mission terminated.");
            break;
        }
        pl("");
        pl("Re-initializing mission profile...");
        pl("");
    }

    return 0;
}
