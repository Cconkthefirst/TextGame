#ifndef ROOM_H
#define ROOM_H
#include "../headers/monster.h"
#include "../headers/character.h"
#include "../headers/item.h"
#include <iostream>
using namespace std;


class Room {

    private:

        int gold; // Amount of gold stored in the room
        Item equipment; // Any other gear in room (keys, swords, etc)
        Monster mon; // A monster that may be in the room
        string description; // A string description of the room
        bool north; // Can the player go north/east/south/west (true = yes, false = no)
        bool east;
        bool south;
        bool west;
        bool canHeal;   // Can the player heal in this room (true = yes, false = no)
        string hint; // A string description of the hint stored in the room
        bool explored; // Has the player explored this room?
        int isTrap; // Whether or not a trap is present in the room

    public:

        //Default constructor, creates an empty room with nothing in it
        //All values will be set to 0 or "empty"
        Room();

        //Argumented constructor for room class
        //inputs:
        // g - integer amount of gold in room
        // eq - string describing equipment in the room
        // curMon - Monster object in room
        // d - string description for the room
        // n - boolean for nort direction (can you go north)
        // ea - boolean for east direction (can you go east)
        // s - boolean for south direction (can you go south)
        // w - boolean for west direction (can you go west)
        // cH - boolean for whether or not a player can heal in the room
        Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, bool cH);

        
        //Argumented constructor for room class
        //inputs:
        // g - integer amount of gold in room
        // eq - string describing equipment in the room
        // curMon - Monster object in room
        // d - string description for the room
        // n - boolean for nort direction (can you go north)
        // ea - boolean for east direction (can you go east)
        // s - boolean for south direction (can you go south)
        // w - boolean for west direction (can you go west)
        // trap - boolean for whether or not there is a trap in the room
        Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, int trap);

        
        //Constructor for a room with a hint
        //inputs:
        // g - integer amount of gold in room
        // eq - string describing equipment in the room
        // curMon - Monster object in room
        // d - string description for the room
        // n - boolean for nort direction (can you go north)
        // ea - boolean for east direction (can you go east)
        // s - boolean for south direction (can you go south)
        // w - boolean for west direction (can you go west)
        // cH - boolean for whether or not a player can heal in the room
        // hi - string description of the hint in the room
        Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, bool cH, string hi);

        //Returns the amount of gold stored in the room, then removes gold from the room
        //returns: current value of gold in room
        //changes: sets gold in room to 0 (ensures the player can't get infinite gold from a single room)
        int getGold();

        //Returns whatever Item equipment is in the room
        //No input, outputs the room's equipment
        Item getEquip();

        //Clears the equipment in a room
        //Intended to run immediately after a player picks up the equipment so they can't pick it up again
        void voidEquip();

        //Gives the name of the equipment in the room
        //Used to restrict a player from picking up an "empty" item
        //No input, returns a string of the equipment name
        string getEquipName();

        //Simulates a fight between the player and the monster in the room
        //Will run the simulation until either the player or the monster is dead
        //Input: The player character (by reference) for attack power and health
        //Output: Either the monster will have <= 0 health, or the player will have <= 0 health
        void fightMonster(Character& plyr);

        //Prints out the string description of the room
        //No inputs
        //Changes the room to "explored" 
        //If the room has been explored, tells the player they have been here before
        void getDescription();

        //Tells if a movement is allowed
        //Input: input - string from the player, either "norht", "south", "east", or "west"
        //Returns true if the input direction is a possible direction to move
        //Returns false if the input direction is not allowed
        bool getDirection(string input);

        //Returns an exact copy of the monster in the room
        Monster getMon();

        //Tells the player whether or not they can heal in this room
        bool getHeal();

        //Tells the player whether or not there is a monster present in the room
        bool monsterPresent();

        //Returns the hint stored in the room as a string
        string getHint();

        //Returns whether or not there is a trap present in the room and if it is active
        int getTrap();

        //Used once a trap has been activated, sets the trap to inactive
        void trapSprung();
};



#endif