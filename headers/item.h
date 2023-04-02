#ifndef ITEM_H
#define ITEM_H
#include <random>
#include <iostream>
using namespace std;

class Item {
    
    private:
        int attackPower; // The attack power of an item if equiped to the player (additional AP)
        int defense; // The defense of an item if equiped to the player (additional health)
        string name; // What the item is called
        bool key; // If the item is a key or not

    public:
        //Basic Constructor for item
        //Creates an item with 0 attack, 0 defense, the name "empty", and key = false
        Item();

        //Argumented constructor for item 
        //Inputs: ap - attack modifier for weapons
        //        d - defensive modifier for armor
        //        n - name of item
        //        k - if it's a key, true. If it's not, false
        Item(int ap, int d, string n, bool k);

        //Returns the attack power/modifier of the item
        int getItemAP();

        //Returns the defense modifier of the item
        int getItemD();

        //Returns the name of the item
        string getName();

        //Returns whether or not the item is a key
        bool isKey();

};


#endif