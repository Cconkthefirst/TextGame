#include "../headers/monster.h"
#include <random>
#include <iostream>
using namespace std;

void Monster::printStats(){
                cout << "Stats:" << endl;
                cout << "------" << endl;
                cout << "Health: " << Monster::health << endl;  
                cout << "Attack Power: " << Monster::power << endl;
            }


Monster::Monster(){
    health = 0;
    power = 0;
}

Monster::Monster(int h, int p){
    health = h;
    power = p;

}

int Monster::attack(){
    int curAttack = rand() % Monster::power;
    return curAttack;
}

void Monster::loseHealth(int playerPower){
    health -=playerPower;
    if(Monster::health <= 0){
        Monster::health = -100;
    }
}

int Monster::getHealth(){
    return Monster::health;
}

bool Monster::monsterPresent(){
    if(Monster::health <=0){
        return false;
    }else{
        return true;
    }
}
