///////////////////////////
// Cade Conklin
// Final Project CS-171
// 12/2/2021
//
// source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
//////////////////////////

#include <iostream> //Used to print to terminal
#include <ctime> //Used for seeding a random number
#include <vector>
#include <string>
#include "../headers/character.h"
#include "../headers/monster.h"
#include "../headers/room.h"
#include "../headers/item.h"
using namespace std;

//Creates the dungeon itself, filling each of the rooms
//Input: - a 5x5 dungeon array
//Outpu: - fills each element of the array with a unique room 
void dungeonMaker(Room dungeon[5][5]);

//To add an item to users invetory 
//Input: The character (Pass by reference because we will need to change the inventory array) and current room(To see if there is something the user can pick up)
//Return: Fill the spot in a users inventory array that the user chooses
void pickUpItem(Character& plyr, Room& curRoom);

//This allows the user to move about the maz/labyrinth
//Input:
//Return:
void moveDirection(string input, Room curRoom, int& y, int& x);

//Print the commands to the user at any point if they need them
//Input: No input (Just printing to the terminal)
//Return: Print out a nice list of all the commands
void printComands();


/////////////////////////////////////////////////////////////////////////

int main(){
    srand(time(NULL)); //Seed random number, this is used throughout the program
    Room dungeon[5][5];
    Character player;
    dungeonMaker(dungeon);

    //Rules and Start Message
    cout << "--------------------------------" <<endl;
    cout << "| Super Awesome Video Game 2.0 |" <<endl;
    cout << "--------------------------------" <<endl;
    cout<<endl;
    cout<<endl;
    cout << "Goal:"<<endl;
    cout << "-----"<<endl;
    cout << "Make it to the center of the labyrinth and slay the Minotaur!" <<endl;
    cout<<endl;
    cout<<endl;
    cout <<"Commands for the Game:"<<endl;
    cout <<"----------------------"<<endl;
    printComands();
    cout<<endl;
    cout<<endl;
    cout << " ---------------" << endl;
    cout << "| VV :Start: VV |" << endl; 
    cout << "------------------------------------------------------------------------------------------------------";

    int x = 0;
    int y = 0;
    string input;
    int prevX = 0;
    int prevY = 0;

    dungeon[y][x].getDescription(); // Prints out the initial room description
    cout<<endl;
    //This while loop represents the game running | stops the game once user enters "quit" command
    while(input != "quit"){
        cout << "*What do you want to do?*" << endl;
        getline(cin,input);
        cout << endl;

        // Tells the player all accepted inputs
        if (input == "help")
        {
            printComands();
            cout<<endl;
        }
        // Lets the user see the description of the room again
        else if(input == "description"){
            dungeon[y][x].getDescription();
        }
        // Lets the user run away from a monster they don't want to fight yet 
        else if(input == "escape"){
            x = prevX;
            y = prevY;
            for(int i = 0; i < 20; i++){ // When clearing the terminal, ensures the whole terminal is cleared
                cout << endl;
            }
            system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
            dungeon[y][x].getDescription();
        }
        //When the player chooses to fight a monster
        else if(input == "fight"){
            if(dungeon[y][x].monsterPresent()){
                cout <<"Current player health: "<< player.getHealth() << endl;
                dungeon[y][x].fightMonster(player);

                //If the player dies during the fight...
                if (player.getHealth() <= 0)
                {
                    cout << "You died" << endl;
                    input = "quit";
                    player.printStats();
                }    
            }
            // If the monster dies during the fight
            Monster curMon = dungeon[y][x].getMon();
            if (curMon.getHealth() <=0 && curMon.monsterPresent() == true)
            {
                cout << "You Slayed the beast!" <<endl;
                
            }

            cout << endl << "Current player health: " << player.getHealth() << endl;
        }

        //If they are weak they use this command (quits the game)
        else if(input == "quit"){
            cout << "*Are you sure you want to quit?* (y/n)" << endl;
            cin >> input;
            if(input == "y"){
                cout << "Goodbye...your device will self destruct in ten seconds..." << endl;
                input = "quit";
            }
        }
        
        //Print the current stats of the user 
        else if (input == "stats")
        {
            player.printStats();
        }
        else if(input == "pnotebook"){
            player.printNoteBook();
        }
        
        // Adds a hint from a room into the user's notebook
        else if(input == "record"){
            if(dungeon[y][x].getHint() == "empty"){
                cout << "There is no hint here." << endl;
            }else{
                player.recordHint(dungeon[y][x].getHint());
                cout<<"You recorded the hint."<<endl;
            }
        }
        
        //Prohibits the player from taking certain actions while a monster is alive
        else if(dungeon[y][x].monsterPresent() && (input == "north" || input == "east" || input == "south" || input == "west" || input == "pickup" || input == "equip" || input == "heal")){
            cout << "You can't do that, there's a monster in here." << endl;
        }

        //These functions are only accessible IF the monster in the room is killed (or there is no monster in the room)
        else if(dungeon[y][x].monsterPresent() == false && (input == "north" || input == "east" || input == "south" || input == "west" || input == "pickup" || input == "equip" || input == "heal")){

            //When the user choose to move and in what direction
            if(input == "north" || input == "east" || input == "south" || input == "west"){
                prevY = y;
                prevX = x;

                // Checks if the player is in specific rooms with certain requirements to go through doors (puzles or keys)
                if((y==2) && (x==3) && (input == "west")){
                    if(player.getKeys() == 4){
                        moveDirection(input, dungeon[y][x], y, x);
                        cout<<"You have all the keys. You may enter..."<<endl;
                    }else{
                        cout << "You don't have enough keys." << endl;
                    }
                }else if((y==1) && (x==2) && (input == "west")){
                    cout << "*What is the answer to the puzzle?*" << endl;
                    string answer;
                    cin >> answer;
                    cin.ignore();
                    if(answer == "rivers"){
                        moveDirection(input, dungeon[y][x], y, x);
                    }else{
                        cout << "That is incorrect..." << endl;
                    }
                }else if((y==3) && (x==0) && (input == "east")){
                    cout << "*What is the answer to the puzzle?*" << endl;
                    string answer;
                    cin >> answer;
                    cin.ignore();
                    if(answer == "nothing"){
                        moveDirection(input, dungeon[y][x], y, x);
                    }else{
                        cout << "That is incorrect..." << endl;
                    }
                }else if((y==4) && (x==2) && (input == "north")){
                    cout << "*What is the answer to the puzzle?*" << endl;
                    string answer;
                    cin >> answer;
                    cin.ignore();
                    if(answer == "3" || "three" || "Three"){
                        moveDirection(input, dungeon[y][x], y, x);
                    }else{
                        cout << "That is incorrect..." << endl;
                    }
                }
                
                // If the player is in any other room, they can move freely
                else{
                    moveDirection(input, dungeon[y][x], y, x);
                    if(dungeon[y][x].getTrap() == 1){
                        for(int i = 0; i < 20; i++){ // When clearing the terminal, ensure the whole terminal is cleared
                            cout << endl;
                        }
                        system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
                        dungeon[y][x].getDescription();
                        cout << endl;
                        if((y == 4 && x == 0)){
                            cout << "There's a big ol' trap!!!" << endl;
                            cout << "You take 15 points of damage!" << endl;
                            player.loseHealth(15);
                        }else if(y == 3 && x == 3){
                            cout << "There's a tiny trap!!!" << endl;
                            cout << "You take 5 points of damage!" << endl;
                            player.loseHealth(5);
                        }else if(y == 2 && x == 4){
                            cout << "There's a trap!!!" << endl;
                            cout << "You take 10 points of damage!" << endl;
                            player.loseHealth(10);
                        }
                        dungeon[y][x].trapSprung();
                        if (player.getHealth() <= 0)
                            {
                                cout << "You died." << endl;
                                input = "quit";
                                player.printStats();
                            }  
                    }else{
                        dungeon[y][x].getDescription();
                    }
                }
            }      

            //Adds the item in the room to the user's inventory
            if (input == "pickup")
            {
                pickUpItem(player, dungeon[y][x]);
            }

            //Allows user to equip something from their inventroy
            if (input == "equip")
            {
                player.equipItem();
            }

            //If the current room is a healing room, resets the players health to maximum value
            if(input == "heal"){
                if(dungeon[y][x].getHeal()){
                    player.heal();
                    cout << "You feel refreshed... Health is reset to maximum!" << endl;
                }else{
                    cout << "You cannot heal in this location." << endl;
                }

            }
        }

        // If the user inputs an unrecognized command, this will print
        else{
            cout << "I don't recognize that command..." << endl;
        }
    cout << "-------------------------------------------------------------------------------------------------------------------------"<<endl;
    //cout<<endl;
      
    }
    return 0; // End of main function

}

//////////////////////////////////////////////////////////////////////////

void dungeonMaker(Room dungeon[5][5]){
    // Rooms (0, 0-4)
    //0,0
    Monster m00; //Creates a monster with 0 health and 0 power (creates a dead/empty monster)
    string d00 = "The room around you is rather nondescript. \nThere are doors on the east and south walls, and a rusty sword propped against the north wall.";
    Item i00(10, 0, "rusty sword", 0);
    Room r00(0, i00, m00, d00, false, true, true, false, false);
    dungeon[0][0] = r00;
    //0,1
    Monster m01(100,10);
    string d01 = "As you enter the room, you see a giant rat squatting in the middle of the room!\nThere are doors along the west and east walls.";
    Item i01;
    Room r01(10, i01, m01, d01, false, true, false, true, false);
    dungeon[0][1] = r01;
    //0,2
    Monster m02; // No monster in this room, but there is a hint
    string d02 = "As you step into the center of the room, you notice a spiraling pattern along the floor. There seem to be words enscribed on the patter... \n\"I am greater than god, more evil than the devil, the poor have me, the rich need me, and if you eat me, you will die. What am I?\" \nThere are doors along the west, east, and south walls of the room.";
    string hint02 = "I am greater than god, more evil than the devil, the poor have me, the rich need me, and if you eat me, you will die. What am I?";
    Item i02;
    Room r02(10, i02, m02, d02, false, true, true, true, false, hint02);
    dungeon[0][2] = r02;
    //0,3
    Monster m03(300, 50); // This has a stronger monster. A tough fight, might not be able to win without getting some other loot first
    string d03 = "As you open the door, you hear a squishing sound. Once you push past the door, a gelatinous cube is hulking in the center of the room!\nThere is a plain door on the west wall and an ornate golden door on the west wall.";
    Item i03;
    Room r03(35, i03, m03, d03, false, true, false, true, false);
    dungeon[0][3] = r03;
    //0,4
    Monster m04; // No monster here!
    string d04 = "As you open the door, you are nearly blinded by the reflective light of... GOLD!\nThis room is entirely plated in gold! In the middle of the room on a golden pedistal lays,\nA GOLD SWORD!!!\nThere are doors along the south and west walls.";
    Item i04(5,0, "Gold sword", 0);
    Room r04(100, i04, m04, d04, false, false, true, true, false);
    dungeon[0][4] = r04;

    //Room (1, 0 - 4)
    //1,0
    Monster m10; //No monster in this room
    string d10 = "A rather dull room, a door to the south, some ancient runes along the walls, and a light sheild laying against a wall.";
    Item i10(0,20,"Light shield",0);
    Room r10(10, i10, m10, d10, 1,0,1,0,0);
    dungeon[1][0] = r10;
    //1,1
    Monster m11; //No monster in this room
    string d11 = "You set foot in a room crafted entirely of marbel, gorgeous paintings along the walls and ceiling, they look tell some sort of ancient story... \nYou notice a Circle key in the center of the room held up by a marbel sculpting of a hand. ";
    Item i11(0,0,"Circle Key", 1);
    Room r11(50, i11 , m11, d11, 0,1,1,0,0);
    dungeon[1][1] = r11;
    //1,2
    Monster m12; //No Monster in this room
    string d12 = "Within this room you notice a contrapation along the western wall where you can enter a single word, seems to be some sort of puzzle. \nIt reads \"From home, I went. From home, I made my way. I saw a road of roads, and a road under them, and a road over them, and a road on all sides. What are we?\" ";
    Item i12(100,0,"The Rock",0);
    Room r12(0, i12, m12, d12, 1,1,0,1,0);
    dungeon[1][2] = r12; 
    //1,3
    string d13 = "Oh boy! Big time fight! You are know face to face with a huge duck... good luck.";
    Monster m13(225, 12);
    Item i13(10,0,"Steel Kopis",0);
    Room r13(10, i13, m13, d13, 0,1,0,1,0);
    dungeon[1][3] = r13;
    //1,4
    Monster m14;
    string d14 = "It appears that there is nothing in this room but you and a mythical fountian, looks like a good time to rest and heal!";
    Item i14;
    Room r14(2, i14, m14, d14, 0,0,1,1,1);
    dungeon[1][4] = r14;

    //Rooms (2, 0 -4)
    //2,0
    Monster m20; //No monster in this room
    string d20 = "This room seems remarkably empty except for a small stone bench along one wall. It looks welcoming for a small break to heal up!";
    Item i20(10,0, "Spoon",0);
    Room r20(3, i20, m20, d20, true, true, true, false,true);
    dungeon[2][0] = r20;
    //2,1
    Monster m21(175, 10);
    string d21 = "You walk into the room and see a hulking behemoth in front of you, blocking the next room...";
    Item i21(20,0, "The Spear of Achilles",0);
    Room r21(15, i21, m21, d21, true, false, false, true, false);
    dungeon[2][1] = r21;
    //2,2
    Monster m22(500,50); //This will be the final mosnter!!!
    string d22 = "You enter the final chamber of the labirynth, the air is heavy. \nThe floor is litered with the gear of fallen adventurers who came before.\nYou see standing opposite you a creature of monstorous proportions. You know its name in an instant...\nThe Minotaur.\nIt draws sword as it brandishes a menacing flail.\nYou see the legendary macguffin in front of you...\nYou know it is now or never...";
    Item i22(100,100,"The macguffin",0);
    Room r22(100, i22, m22, d22, false, true, false, false, false);
    dungeon[2][2] = r22;
    //2,3
    Monster m23; //No monster here!
    string d23 = "A large room sits on the west wall of the room, elaborate and well carved. There seem to be four keyholes in the door.";
    Item i23(0,0,"Square key", 1);
    Room r23(0, i23, m23, d23, false, false, true, true, false);
    dungeon[2][3] = r23;
    //2,4
    Monster m24; //Nothing in the mosnter department
    string d24 = "The room looks empty at first glance, but there's a faint smell of gunpowder in the air...";
    Item i24(0,1,"tattered book", 0);
    Room r24(7, i24, m24, d24, true, false, true, false, 1);
    dungeon[2][4] = r24;

    //Rooms (3, 0 - 4)
    //3,0
    Monster m30; //No monster
    string d30 = "In the center of this mostly empty room sits a circular pattern of letters. In the center of the circle is a single question: \"What am I?\"\nThe letters in the pattern look as if they could be pressed, like solving a puzzle.\nAlong the north, south, and east walls are doors.\nThe door on the east wall looks like it is locked with a strange mechanism...";
    Item i30;
    Room r30(0, i30, m30, d30, true, true, true, false, false);
    dungeon[3][0] = r30;
    //3,1
    Monster m31;
    string d31 = "THERES A KEY IN HERE!!!";
    Item i31(0,0,"Hex Key", 1);
    Room r31(15, i31, m31, d31, false, false, false, true, false);
    dungeon[3][1] = r31;
    //3,2
    Monster m32; //No monster in this room
    string d32 = "A room where the floor is all water and in the center of it is a stone slab holding a key.\nThe only door is the one you came through.";
    Item i32(0,0,"Triangle Key", 1);
    Room r32(0,i32, m32,d32, 0,0,1,0,0);
    dungeon[3][2] = r32;
    //3,3
    Monster m33; //No monater in this room
    string d33 = "As you enter this room something feels off, step by step you slowly walk across the room when all of the sudden you hear a click... another trap room\nIf you survive this one there is a set of spartan gauntlets you could snatch." ;
    Item i33(0,50,"Spartan Gauntlets", 0);
    Room r33(10, i33, m33, d33, true,false,true,false,1);
    dungeon[3][3] = r33;
    //3,4
    Monster m34(180,20);
    string d34 = "A delirious man wanders around this room. You try to speak to him but once he notices you its clear he is no friend... \nHe charges you with a bone mace, could be useful if you can get it from him.\nYou see doors to the north and south.";
    Item i34(20,0,"Bone Mace", 0);
    Room r34(13, i34, m34, d34, 1,0,1,0,0);
    dungeon[3][4] = r34;

    //Rooms (4, 0 - 4)
    //4,0
    Monster m40; //No monster in this room
    string d40 = "It's a trap room! If you can survive the trap there is a sharp looking galdius on the other side that could be helpful.\nThere are doors to the north and east.";
    Item i40(25,0,"Gladius", 0);
    Room r40(15,i40, m40, d40, true, true, false, false, 1);
    dungeon[4][0] = r40;
    //4,1
    Monster m41(300,10);
    string d41 ="A fat bungus sits upon a lofting pile of treasure. There is a chestplate behind the bungus, would be nice if you can get to it.";
    Item i41(0,80,"Chestplate", 0);
    Room r41(1,i41, m41, d41,0,1,0,1,0);
    dungeon[4][1] = r41;
    //4,2
    Monster m42; //No monster in this room
    string d42 = "You enter a vibrant but empty room full of plant life. To the north there is a door that can only be ulocked by a puzzle.\nThe puzzle is a series of numbers and symbols.\nIt reads |Pegasus = 4| |Cyclopes = 1| |Cerberus = \"What\"|  \nAfter some exploring around the room you find this symbol \"-\" looks to be a hint!";
    Item i42;
    string hint42 = "Test";
    Room r42(0,i42, m42, d42, 1,1,0,1,0, hint42);
    dungeon[4][2] = r42;
    //4,3
    Monster m43;
    string d43 = "Theres a slight warmth to this room. It's pleasant enough to take a nap and regain some health.";
    Item i43;
    Room r43(0, i34, m43, d43, true, true, false, true, true);
    dungeon[4][3] = r43;
    //4,4
    Monster m44; //No monster in this room
    string d44 = "A barren room except for the remains of a battle.\nAfter looking around you find the phrase \"What flows into lakes and oceans?\" seems to be a hint. \nThere is also super cool sword in the corner.";
    string hint44 = "What flows into lakes and oceans?";
    Item i44(50,0,"Literally the Coolest Sword you've ever seen", 0);
    Room r44(5,i44, m44, d44, 1,0,0,1,0,hint44);
    dungeon[4][4] = r44;
}

    void moveDirection(string input, Room curRoom, int& y, int& x){
        if(input == "north"){
            if(curRoom.getDirection(input) == true){
                y = y - 1;
                for(int i = 0; i < 20; i++){ // When clearing the terminal, ensures the whole terminal is cleared
                    cout << endl;
                }
                system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
            }else{
                cout << "You can't go that way." << endl;
            }
        }else if(input == "east"){
            if(curRoom.getDirection(input) == true){
                x = x + 1;
                for(int i = 0; i < 20; i++){ // When clearing the terminal, ensures the whole terminal is cleared
                    cout << endl;
                }
                system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
            }else{
                cout << "You can't go that way." << endl;
            }
        }
        else if(input == "south"){
            if(curRoom.getDirection(input) == true){
                y = y + 1;
                for(int i = 0; i < 20; i++){ // When clearing the terminal, ensures the whole terminal is cleared
                    cout << endl;
                }
                system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
            }else{
                cout << "You can't go that way." << endl;
            }
        }
        else if(input == "west"){
            if(curRoom.getDirection(input) == true){
                x = x - 1;
                for(int i = 0; i < 20; i++){ // When clearing the terminal, ensures the whole terminal is cleared
                    cout << endl;
                }
                system("cls"); // source : https://stackoverflow.com/questions/6486289/how-can-i-clear-console
            }else{
                cout << "You can't go that way." << endl;
            }
        }
    }


    void pickUpItem(Character& plyr, Room& curRoom){
        if(curRoom.getEquipName() != "empty"){
            plyr.pickUpItem(curRoom.getEquip());
            curRoom.voidEquip();
        }else{
            cout << "There is no equipment in this room to pick up." << endl;
        }
    }

    void printComands(){
        cout << "Cmd \"help\": Prints out the command list."<<endl;
        cout << "Cmd \"fight\": Fights a monster to the death."<<endl;
        cout << "Cmd \"escape\": Runs away from a tough monster fight, returning to the previous room." << endl;
        cout << "Cmd \"north, south, east, west\": Moves the player a direction."<<endl;
        cout << "Cmd \"pickup\": Picks up an item in a room."<<endl;
        cout << "Cmd \"record\": Adds a hint in a room to the notebook." <<endl;
        cout << "Cmd \"pnotebook\": Prints out the notebook with recorded hints." << endl;
        cout << "Cmd \"stats\": Shows your current stats."<<endl;
        cout << "Cmd \"equip\": Equip an item that is in your inventory."<<endl;
        cout << "Cmd \"heal\": If you are in a healing room this can be used to heal."<<endl;
        cout << "Cmd \"description\": Describes the current room." << endl;
        cout << "Cmd \"quit\": Quits the game."<<endl;
    }