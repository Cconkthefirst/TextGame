#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
using namespace std;

// I added comments to all the functions in the class so they can be more easily referenced. Also removed #include <string>
// I also made the a function to tell if a monster is acutally present/alive - Zach
class Monster {

private:
    int health; // Maximum health of the monster
    int power; // Maximum attack power of the monster

public:
    // Basic constructor for the monster
    // Creates a monster with 0 health and 0 power (no monster)
    Monster();

    // Argumented constructor for monster
    // h - integer input for the maximum health
    // p - integer input for the maximum attack power
    Monster(int h, int p);

    // Randomly determines an attack power between 0 and the max
    // returns - integer value for attack power
    int attack();

    // Dereases current health
    // input: playerPower - integer value for how much the monster is hurt by
    // output: decreases the current health value
    void loseHealth(int playerPower);

    // Prints out the current health and attack power of the monster
    void printStats();

    //Returns the current health of the monster
    int getHealth();   

    // Determines if a monster is present
    // if health <= 0, there is no monster - return false
    // if health > 0, there is a monster - return true
    bool monsterPresent(); 
    

};


#endif
