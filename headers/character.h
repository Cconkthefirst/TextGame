#ifndef CHARACHTER_H
#define CHARACHTER_H
#include "../headers/item.h"
#include <random>
#include <vector>
#include <iostream>
using namespace std;

// I removed the #include <string>. I think using iostream and namespace std will do the same thing and it still works
class Character{

    private:

        int health; // maximum health of the player
        int power; // maximum attack power
        Item inventory[10]; // Max amount of items a player can hold at any given moment
        Item equipedWeap;
        Item equipedArmor;
        int keys = 0;
        string notebook[4]; //This acts as a way for the user to store hints

    public:

        //Basic Constructor for the users Character class
        //Creates a character with 100 health, 5 attack power,
        //    an empty inventory and notebook, 0 keys, and 
        //    nothing equiped
        Character();

        //Method that will execute an attacking move by player
        //Returns a random number between 0 and the maximum 
        //     player attack power
        int attack();

        //Used while fighting, this will subtract from the player health
        //Input: The monsters atack power will be needed to find damage taken
        //Return: The amount of damage taken by player in int form
        void loseHealth(int monPower);

        //Method to used when user chooses to pick something up
        //Input: An item to be added to the inventory
        //Output: Adds the item to the inventory
        void pickUpItem(Item equip);

        // Prints out the current health, attack power, and inventory of the character
        void printStats();

        // Returns the current value of health
        // Used for determining if the player is dead or for printing stats
        int getHealth();

        //Takes an item from the inventory and allows the player to equip it
        //If it is armor, it increases max health
        //If it is a weapon, it increases max damage
        void equipItem();

        //Returns the player's health to 100 + their armor
        void heal();

        //Returns the number of keys the player has in their inventory
        int getKeys();

        //If there is a hint in a room, this adds the hint to the players notebook
        void recordHint(string hint);

        //Prints out the player's notebook, used for referencing hints
        void printNoteBook();
};

#endif