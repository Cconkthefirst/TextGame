#include "../headers/item.h"

Item::Item(){
    attackPower = 0;
    defense = 0;
    name = "empty";
    key = 0;
}

Item::Item(int ap, int d, string n, bool k){
    Item::attackPower = ap;
    Item::defense = d;
    Item::name = n;
    Item::key = k;
}

int Item::getItemAP(){
    return Item::attackPower;
}

int Item::getItemD(){
    return Item::defense;
}

string Item::getName(){
    return Item::name;
}

bool Item::isKey(){
    return Item::key;
}