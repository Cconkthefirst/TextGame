#include "../headers/character.h"
#include <string>
#include <random>
#include <iostream>
using namespace std;


Character::Character(){
    health = 100;
    power = 5;
    Item stuff(0,0,"Empty",0);
    for(int i = 0; i < 10; i++){
        inventory[i] = stuff;
    }
    Item equipedStuff(0,0,"none",0);
    equipedArmor = equipedStuff;
    equipedWeap = equipedStuff;
    for (int i = 0; i < 4; i++)
    {
        notebook[i] = "Blank";
    }
    
}


void Character::printStats(){
    cout << "Current Stats:" << endl;
    cout << "--------------" << endl;
    cout << "Health: " << Character::health + Character::equipedArmor.getItemD() << endl;  
    cout << "Attack Power: " << Character::power << endl;
    cout << "Inventory:" << endl;
    for(int i = 0; i < 10; i++){
        cout << "[" << i <<"] - " << Character::inventory[i].getName();
        if(Character::inventory[i].getName() == Character::equipedArmor.getName() || Character::inventory[i].getName() == Character::equipedWeap.getName()){
            cout << " (equiped)";
        }
        cout << endl;
    }
    }


int Character::attack(){
    int curAttack = rand() % Character::power;
    return curAttack;
}

void Character::loseHealth(int monPower){
    health -= monPower;
}

void Character::pickUpItem(Item equip){
    if(equip.isKey()){
        Character::keys++;
        cout << "You got a key!" << endl << "Curent number of keys: " << Character::keys << endl;
    }else{
    cout << "Inventory:" << endl;
    cout << "----------" << endl;
    //Prints the current inventory of user before they pick an item up
    for (int i = 0; i < 10; i++)
    {
        int spot = i;
        cout << "[" << i << "] - " << inventory[i].getName() << endl;
    }

    int inp;
    cout<<endl;
    cout << "*What inventory slot would you like it in?*" << endl;
    cin >> inp;
    cin.ignore();
    inventory[inp] = equip;
    cout<<endl; 
    }
}

int Character::getHealth(){
    return Character::health + Character::equipedArmor.getItemD();
}

void Character::equipItem(){
    int input;
    for (int i = 0; i < 10; i++)
    {
        int spot = i;
        cout <<"["<< i <<"] - "<<inventory[i].getName() << endl;
    }
    cout << endl << "Which item would you like to equip?" << endl;
    cin >> input;
    cin.ignore();
    if(inventory[input].getItemAP() > 0){
        equipedWeap = inventory[input];
        Character::power = 5 + equipedWeap.getItemAP();
    }
    if(inventory[input].getItemD() > 0){
        equipedArmor = inventory[input];
    }
    
}

void Character::heal(){
    Character::health = 100;
}

int Character::getKeys(){
    return keys;
}

void Character::recordHint(string hint){
    for (int i = 0; i < 4; i++)
    {
        cout << "[" << i << "] - " << Character::notebook[i] <<endl;
    }

    int inp;
    cout << "On what Page?"<<endl;
    cin >> inp;
    cin.ignore();
    notebook[inp] = hint;
    cout<<endl;
}

void Character::printNoteBook(){
    cout<<"NoteBook:"<<endl;
    cout<<"---------"<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout <<"["<< i << "] - "<< Character::notebook[i] << endl;
    }
    
}