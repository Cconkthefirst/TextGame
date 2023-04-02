#include "../headers/room.h"
#include <iostream>
using namespace std;

Room::Room(){
    Room::gold = 10;
    Item eq(0,0,"empty",0);
    Room::equipment = eq;
    Room::description = "A small room...";
    Monster curMon(0,0);
    Room::mon = curMon;
    Room::explored = 0;
    Room::canHeal = 0;
    Room::north = 1,east = 1,south = 1,west = 1;
    Room::hint = "empty";
}

Room::Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, bool cH){
    Room::gold = g;
    Room::equipment = eq;
    Room::description = d;
    Room::mon = curMon;
    Room::north = n;
    Room::east = ea;
    Room::south = s;
    Room::west = w;
    Room::canHeal = cH;
    Room::explored = 0;
    Room::hint = "empty";
}

Room::Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, bool cH, string hi){
    Room::gold = g;
    Room::equipment = eq;
    Room::description = d;
    Room::mon = curMon;
    Room::north = n;
    Room::east = ea;
    Room::south = s;
    Room::west = w;
    Room::canHeal = cH;
    Room::explored = 0;
    Room::hint = hi;
    Room::isTrap = 0;
}

Room::Room(int g, Item eq, Monster curMon, string d, bool n, bool ea, bool s, bool w, int trap){
    Room::gold = g;
    Room::equipment = eq;
    Room::description = d;
    Room::mon = curMon;
    Room::north = n;
    Room::east = ea;
    Room::south = s;
    Room::west = w;
    Room::canHeal = 0;
    Room::explored = 0;
    Room::isTrap = trap;
    Room::hint = "empty";
}


int Room::getGold(){
    int tempGold = Room::gold;
    Room::gold = 0;
    return tempGold;
}

Item Room::getEquip(){
    return Room::equipment;
}

void Room::voidEquip(){
    Item noEquip(0,0,"empty",0);
    Room::equipment = noEquip;
}

string Room::getEquipName(){
    string equipName = Room::equipment.getName();
    return equipName;
}

void Room::fightMonster(Character& plyr){
    do
    {
        if(mon.monsterPresent()){ 
            
        int plyrPower = plyr.attack();
        int monPower = Room::mon.attack();

        plyr.loseHealth(monPower);
        Room::mon.loseHealth(plyrPower);
        }else{
        cout << "-There is no monster in this room." << endl;
        }
    } while ((plyr.getHealth() > 0) && (mon.getHealth() > 0));
    
   
}

void Room::getDescription(){
    cout << endl << Room::description << endl;
    //if (Room::explored == true)
    //{
        cout<<endl;
        cout << "Room Status:" << endl;
        cout << "------------" << endl;
        if (Room::getHint() == "empty")
        {
            cout << "-There seems to be no hint here." << endl;
        } 
        if(Room::mon.getHealth() == -100){
            cout << "-You have already slayn this monster." << endl;
        }
        if(Room::equipment.getName() == "empty"){
            cout << "-There is no equipment to pick up in this room." << endl;
        }
        if(Room::explored){
            cout << "-You have been here before." << endl;
        }
   // }
    Room::explored = true;
}

bool Room::getDirection(string input){
    if(input == "north"){
        return Room::north;
    }else if(input == "east"){
        return Room::east;
    }else if(input == "south"){
        return Room::south;
    }else if(input == "west"){
        return Room::west;
    }else{
        return false;
    }
}

Monster Room::getMon(){
    return Room::mon;
}


bool Room::getHeal(){
    return Room::canHeal;
}


bool Room::monsterPresent(){
    return Room::mon.monsterPresent();
}

string Room::getHint(){
    return Room::hint;
}

int Room::getTrap(){
    return Room::isTrap;
}

void Room::trapSprung(){
    Room::isTrap = 0;
}