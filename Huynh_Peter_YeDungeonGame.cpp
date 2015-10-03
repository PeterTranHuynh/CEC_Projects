/**
* This is a file containing multiple classes, enumerations, and structures that are used within a text adventure game.
* Written in C++, This small scale game is designed after the famous MIT Zork, which was one of the first electronic RPGs
* to have been released to the general public. In this program, you will find various methods pertaining to their
* corrisponding classes.
* 
* @author Peter Tran Huynh
* @version 1.0 December 12th 2013
*/

/* ----- Headers ------ */
#include <string>
#include <iostream>
#include <math.h>

/* ----- Namespace Standard for cin and cout within iostream ----- */
using namespace std;

/* ----- Enumerations: Enumerations are collections of integer constants into a public class. ----- */

/**
* 
* Enumeration class for room names. Each room name will be a constant, with 22 of them in total.
* One of which will be a null room that will prevent users from moving in that direction.
* 
*/
enum RoomId
{
	NONE,
	START,
	WOODEN,
	STEEL,
	DECOR,
	DARK,
	DOWNSTAIRS,
	RIDDLE,
	NPC,
	SWORD,
	KEY,
	MOB,
	ARMOR,
	EASTER,
	MOB2,
	POTION,
	NPC2,
	SHIELD,
	BOSS,
	TREASURE,
	END,
	EGG
};

/**
* 
* Emnumeration for direction names. There are seven directions in all. N E S W are the general directions.
* I've included three other directions, up, down, and stay. stay being used only for when a user is
* trying to move into an impossible area. up and down will be used to change floors.
* 
*/
enum Movement
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	UP,
	DOWN,
	STAY
};

/* ----- Structures: Similar to classes, except with an absence of access-specifiers and contains public defaults ----- */

/**
*
* Structure class that is used to create an array of the game world.
*
*/
struct Room
{
	char *name;		// Room labels, as a pointer const* char
	int move[7];	// North, South, East, West, Up, Down, and Stay from current location. A 7 array slot integer.
};

/* ----- Classes ----- */

/**
*
* Class of the Player, his/her stats, and the player's inventory. 
* The methods and variables within this class pertain to the users "character" within the game.
*
*/
class Player
{
	private:
		// Player Stats
		int health;
		int attack;
		int defense;
		// Items
		bool sword;
		bool armor;
		bool shield;
		bool potion;
		bool key;
		bool flute;
	public:
		// Constructor
		Player(int initalHp, int initalAtk, int initalDef, bool initalSword, bool initalArmor, bool initalShield, bool initalPotion, bool initalKey, bool initalFlute);
		// Getters
		int getHp();
		int getAtk();
		int getDef();
		bool getSword();
		bool getArmor();
		bool getShield();
		bool getPotion();
		bool getKey();
		bool getFlute();
		// Setters
		void addHp(int hp);
		void addAtk(int atk);
		void addDef(int def);
		void obtainSword(bool item);
		void obtainArmor(bool item);
		void obtainShield(bool item);
		void obtainPotion(bool item);
		void obtainKey(bool item);
		void obtainFlute(bool item);
		// Methods
		void stats();
		void inventory();
};
/**
* This is the constructor for the class Player. initializes all variables private and public.
* 
* @params three integers, six booleans. the integers will represent the initial player stats, and the booleans will represent inventory
* @return none
*/
Player::Player(int initalHp, int initalAtk, int initalDef, bool initalSword, bool initalArmor, bool initalShield, bool initalPotion, bool initalKey, bool initalFlute)
{
	health = initalHp;
	attack = initalAtk;
	defense = initalDef;
	sword = initalSword;
	armor = initalArmor;
	shield = initalShield;
	potion = initalPotion;
	key = initalKey;
	flute = initalFlute;
}
/**
* Getters of Player class, there are nine in total.
*
* @params none for all of them.
* @return three return integers, six return booleans.
*/
int Player::getHp()
{
	return health;
}
int Player::getAtk()
{
	return attack;
}
int Player::getDef()
{
	return defense;
}
bool Player::getSword()
{
	return sword;
}
bool Player::getArmor()
{
	return armor;
}
bool Player::getShield()
{
	return shield;
}
bool Player::getPotion()
{
	return potion;
}
bool Player::getKey()
{
	return key;
}
bool Player::getFlute()
{
	return flute;
}
/**
* Setters of Player class. These methods allow for the modification of the private variables
* 
* @params three take in one integers, six take in one boolean
* @return none for all of them.
*/
void Player::addHp(int hp)
{
	health += hp;
}
void Player::addAtk(int atk)
{
	attack += atk;
}
void Player::addDef(int def)
{
	defense += def;
}
void Player::obtainSword(bool item)
{
	sword = item;
}	
void Player::obtainArmor(bool item)
{
	armor = item;
}
void Player::obtainShield(bool item)
{
	shield = item;
}
void Player::obtainPotion(bool item)
{
	potion = item;
}		
void Player::obtainKey(bool item)
{
	key = item;
}
void Player::obtainFlute(bool item)
{
	flute = item;
}
/**
* Methods inside Player class that is used to display player stats and inventory in a formatted fashion.
* 
* @params none
* @return none
*/
void Player::stats()
{
	cout << "- Your current health is: " << getHp() << endl << "- Your current attack is: " << getAtk() << endl << "- Your current defence is: " << getDef();
}
void Player::inventory()
{
	cout << "================================================================================" << endl;
	if(getSword() == 1)
		cout << "- You have a steel sword." << endl;
	if(getArmor() == 1)
		cout << "- You have some enchanted armor." << endl;
	if(getShield() == 1)
		cout << "- You have a steel shield." << endl;
	if(getPotion() == 1)
		cout << "- You have a health potion." << endl;
	if(getKey() == 1)
		cout << "- You have the castle's keys." << endl;
	if(getFlute() == 1)
		cout << "- You have the dragon lord's flute." << endl;
	if(getSword() == 0 && getArmor() == 0 && getShield() == 0 && getPotion() == 0 && getKey() == 0 && getFlute() == 0)
		cout << "- You have nothing! Good day sir!" << endl;
	cout << endl << "================================================================================";	
}

/**
*
* Class of Npc that will contain interactions with non-player characters and their stats.
* 
*/
class Npc
{
	private:
		string npcName;
		int npcHealth;
		int npcAttack;
		int npcDefense;
		int npcDamageDealt;
		int npcDamageTaken;
	public:
		// Constructor
		Npc(int hp, int atk, int def, string name);
		// Getters
		string getNpcName();
		int getHp();
		int getAtk();
		int getDef();
		// Methods
		void attack(Player &you, int &room);
};
/**
* Constructor for Npc class.
* 
* @params four integers for the npc stats, one string for their name/id
* @return none
*/
Npc::Npc(int hp, int atk, int def, string name)
{
	npcHealth = hp;
	npcAttack = atk;
	npcDefense = def;
	npcName = name;
}
/**
* Getters for Npc class.
* 
* @params none for all four.
* @return returns variable primitive types, one string, three integers.
*/
string Npc::getNpcName()
{
	return npcName;
}
int Npc::getHp()
{
	return npcHealth;
}
int Npc::getAtk()
{
	return npcAttack;
}
int Npc::getDef()
{
	return npcDefense;
}
/**
* Method used for damage calculation and display format when attacking various npcs. 
* 
* @params none
* @return Player instance called by reference, integer called by reference.
*/
void Npc::attack(Player &you, int &room)
{
	npcDamageTaken = (you.getAtk() - getDef());		// Sets damage npc will take.
	npcDamageDealt = (getAtk() - you.getDef());		// Sets damage npc will deal.
	if(npcDamageDealt < 0)							// Conditional where if the damages are negative, they will be set to 1.
		npcDamageDealt = 1;
	if(npcDamageTaken < 0)
		npcDamageTaken = 1;
	if(getHp() > 0)
	{
		cout << "You attacked the " << getNpcName() << "." << endl << "You dealt " << npcDamageTaken << " damage." << endl << " The " << getNpcName() << " attacked back, dealing " << npcDamageDealt << " damage to your health" << endl;
		npcHealth -= npcDamageTaken;
		you.addHp(-(npcDamageDealt));
		if(getHp() < 0)
			npcHealth = 0;
		cout << " The " << getNpcName() << " now has " << getHp() << " health." << endl << " You now have " << you.getHp() << " health.";
		if(getHp() <= 0)
		{
			if(room == NPC)
				cout << endl << "You killed the innocent old man...";
			else if(room == NPC2)
				cout << endl << "The friendly soldier landed on a pile of rubble, and is now dead.";
			else if(room == MOB)
				cout << endl << "The chicken stubled, fell down, and died... Poor chicken.";
			else if(room == MOB2)
				cout << endl << "The dragon fell on the floor, dead... You must feel like a hero now, don't you?";
			else if(room == BOSS)
				cout << endl << "The Dragon Lord is disintegrated into a pile of ash. Neat.";
		}
	}
	else
		cout << "There's nothing to attack.";
}

/**
* 
*  Class of the world's game variables and functions for world items.
*
*/
class Game
{
	private:
		// World Items
		bool sword;
		bool armor;
		bool shield;
		bool potion;
		bool key;
		bool flute;
	public:
		// Constructor
		Game(bool initalSword, bool initalArmor, bool initalShield, bool initalPotion, bool initalKey, bool initalFlute);
		// Getters
		bool getSword();
		bool getArmor();
		bool getShield();
		bool getPotion();
		bool getKey();
		bool getFlute();
		// Setters
		void setSword(bool worldItem);
		void setArmor(bool worldItem);
		void setShield(bool worldItem);
		void setPotion(bool worldItem);
		void setKey(bool worldItem);
		void setFlute(bool worldItem);
};
/**
* Constructor of Game
* 
* @params eight booleans, all representing inital values for the items on the map and the win/lose condition
* @return none
*/
Game::Game(bool initalSword, bool initalArmor, bool initalShield, bool initalPotion, bool initalKey, bool initalFlute)
{
	sword = initalSword;
	armor = initalArmor;
	shield = initalShield;
	potion = initalPotion;
	key = initalKey;
	flute = initalFlute;
}
/**
* Getters of Game class.
* 
* @params all six return booleans, their primitive type.
* @return none for all.
*/
bool Game::getSword()
{
	return sword;
}
bool Game::getArmor()
{
	return armor;
}
bool Game::getShield()
{
	return shield;
}
bool Game::getPotion()
{
	return potion;
}
bool Game::getKey()
{
	return key;
}
bool Game::getFlute()
{
	return flute;
}
/**
* Setters of Game class.
* 
* @params one boolean for all six, which will be used to reassign the variables
* @return none for all.
*/
void Game::setSword(bool worldItem)
{
	sword = worldItem;
}
void Game::setArmor(bool worldItem)
{
	armor = worldItem;
}
void Game::setShield(bool worldItem)
{
	shield = worldItem;
}
void Game::setPotion(bool worldItem)
{
	potion = worldItem;
}
void Game::setKey(bool worldItem)
{
	key  = worldItem;
}
void Game::setFlute(bool worldItem)
{
	flute = worldItem;
}

/**
*
* Class used for initializing the foundation of the gameplay. Allows user interaction with this world.
* 
*/
class GameCommands
{
	private:
		char buff[BUFSIZ];	// Primitive character array that can hold 512 characters used as a reference
		char cmd[BUFSIZ];	// Character array that holds up to 512 characters used for user commands
		int pos;			// Integer used for user input size
		char *params;		// Character with a pointer used for parameters of command
		bool winrarIsYou;	// Boolean to win the game
	public:
		// Constructor
		GameCommands(bool winNow);
		// Methods
		int move(int &room, char *dir, Room rooms[]);
		void takeItem(int room, char *item, Player &you, Game &world);
		void useItem(int room, char *item, Player &you, Game &world);
		void storyLine(int &room, Player &you, Game &world, Npc &oldMan, Npc &lambentChicken, Npc &soldier, Npc &dragon, Npc &dragonLord);
		void userCommands(int &room, Room rooms[], Player &you, Game &world, Npc &oldMan, Npc &lambentChicken, Npc &soldier, Npc &dragon, Npc &dragonLord);
};
/**
* Constructor for GameCommands class. Only initializes boolean win to 0 and character arrays to 0, the rest will be assigned in the method userCommands.
* 
* @params one boolean to initialize win boolean.
* @return none
*/
GameCommands::GameCommands(bool winNow)
{
	buff[BUFSIZ] = 0;
	cmd[BUFSIZ] = 0;
	winrarIsYou = winNow;
}
/**
* Function that takes in an integer for the room value, and a character for user input.
* then uses a switch statement to change the room based on a redefined integer referenced to the enumeration constants
* 
* @params none
* @return none
*/
int GameCommands::move(int &room, char *dir, Room rooms[])
{
	// Local Integer direction that will assume the value of an enumeration constant within Movement
	int direction;
	
	// Switch Statement that changes direction based on user input
	switch(*dir)
	{
		case 'n':
			direction = NORTH;
			break;
		case 's':
			direction = SOUTH;
			break;
		case 'e':
			direction = EAST;
			break;
		case 'w':
			direction = WEST;
			break;
		case 'u':
			direction = UP;
			break;
		case 'd':
			direction = DOWN;
			break;
		default:
			direction = STAY;
			break;
	}

	// Displays different outputs depending on the pathway direction
	if(rooms[room].move[direction] == NONE)
	{
		cout << endl << "There is no pathway in this direction" << endl;
	}
	else
	{
		switch(*dir)
		{
			case 'n':
				cout << endl << "You have moved north.";
				break;
			case 's':
				cout << endl << "You have moved south.";
				break;
			case 'e':
				cout << endl << "You have moved east.";
				break;
			case 'w':
				cout << endl << "You have moved west.";
				break;
			case 'u':
				cout << endl << "You have moved upstairs.";
				break;
			case 'd':
				cout << endl << "You have moved downstairs.";
				break;
			default:
				cout << endl << "Error, invalid input:" << endl << "Please type in 'help' for a list of commands." << endl;
				break;
		}

		room = rooms[room].move[direction];
		cout << endl << "You are currently in " << rooms[room].name << endl;
	}

	return room;
}
/**
* Function that takes in an integer for the room value, a pointer character for user input, and instances of Player and Game called by reference.
* then uses a switch statement to change to reassign world values and inventory/stats of player
* 
* @params one integer passed by reference, one char pointer, one player class instance passed by reference, and one world class instance passed by reference
* @return none
*/
void GameCommands::takeItem(int room, char *item, Player &you, Game &world)
{
	// Switch Statement that converts world items into inventory items.
	switch(*item)
	{
		case 'a':
			if((room == ARMOR) && (world.getArmor() == 1))
			{
				cout << "Armor taken. You equipped it. +30 DEF!";
				world.setArmor(0);
				you.obtainArmor(1);
				you.addDef(30);
			}
			else
				cout << "What armor?";
			break;
		case 's':
			if((room == SWORD) && (world.getSword() == 1))
			{
				cout << "Sword taken. You equipped it. +34 ATK!";
				world.setSword(0);
				you.obtainSword(1);
				you.addAtk(34);
			}
			else if((room == SHIELD) && (world.getShield() == 1))
			{
				cout << "Shield taken. You equipped it. +15 ATK and +20 DEF!";
				world.setShield(0);
				you.obtainShield(1);
				you.addAtk(25);
				you.addDef(20);
			}
			else
				cout << "Nope, nothing like that here.";
			break;
		case 'p':
			if((room == POTION) && (world.getPotion() == 1))
			{
				cout << "Potion taken. You can use it to heal 75 HP.";
				world.setPotion(0); 
				you.obtainPotion(1);
			}
			else if((room == POTION) && (world.getPotion() == 0))
				cout << "You grab another one of the potions, but placed it back because there was a dead spider inside of it." << endl << "It's best not to take anymore...";
			else
				cout << "What potion?";
			break;
		case 'k':
			if((room == KEY) && (world.getKey() == 1))
			{
				cout << "Key taken. This will be useful for later.";
				world.setKey(0);
				you.obtainKey(1);
			}
			else
				cout << "What key?";
			break;
		default:
			cout << "Take what? I don't see anything around by that name.";
			break;
	}
}
/**
* Function that takes in an integer for the room value, and a character for user input, with various classes
* then uses a switch statement to determine which item to use
* 
* @params one integer passed by reference, one char pointer, one player class instance passed by reference, and one world class instance passed by reference
* @return none
*/
void GameCommands::useItem(int room, char *item, Player &you, Game &world)
{
	// Switch Statement that converts world items into inventory items.
	switch(*item)
	{
		case 'p':
			if(you.getPotion() == 1)
			{
				cout << "Potion used. +75 HP!";
				you.obtainPotion(0);
				you.addHp(75);
			}
			else
				cout << "You don't have that.";
			break;
		case 'k':
			if(you.getKey() == 1)
			{
				cout << "Use the key on what? Save it for when you need it.";
			}
			else
				cout << "You don't have that.";
			break;
		case 'f':
			if((you.getFlute() == 1) && (room != END))
				cout << endl << "You played the flute, but nothing happened.";
			else if((you.getFlute() == 1) && (room == END))
			{
				cout << endl << "You played the flute, and magically the dragon egg started hatching." << endl << "A dragon then swoops out from the egg!" << "It seems tame, so you decide to hop on it's back and fly away." << endl << "The End.";
				winrarIsYou = 1;
			}
			else
				cout << "You don't have that.";
			break;
		default:
			cout << "Nope. Can't do that.";
			break;
	}
}
/**
* Function that outputs the games story, contains a switch statement that analyzes the room constant assigned to integer room.
* 
* @params one integer pased by reference, and seven instances all passed by reference.
* @return none
*/
void GameCommands::storyLine(int &room, Player &you, Game &world, Npc &oldMan, Npc &lambentChicken, Npc &soldier, Npc &dragon, Npc &dragonLord)
{
	switch(room)
	{
		case START:
			cout << "You are in a small cobblestone room with no windows, there is:" << endl <<  "- A plain wooden door pointing north," << endl << "- A reinforced steel door pointing east," << endl << "- An elegantly decorated door pointing south," << endl << "- And a dark hallway pointing west." <<  endl << "You also notice something written on the ceiling of the room:" << endl << " 'There are four doors in this room, you must take a path or death will fall" << endl << " upon thy. But be weary, not all paths are as they appear.'";
			break;
		case WOODEN:
			cout << "You opened the door and enter a room with a large table in the center." << endl << "You notice there is a nicely decorated chocolate cake on the table, so you help yourself." << endl << "You notice a note within the cake that stated: 'You lose'" << endl << "You begin to chock uncontrollably... and faint from the suffication..." << endl << "Death by chocolate.";
			you.addHp(-(you.getHp()));
			break;
		case DARK:
			cout << "You head into the dark hallway." << endl << "It is hard to see and hard to breath" << endl << "The hall feels small and cramped." << endl << "Suddenly tourches light up the hallway, revealing that you're in a cage." << endl << "There is a large bear-like demon breathing right in front of your face." << endl << "The demon then grabs you and swallows you whole.";
			you.addHp(-(you.getHp()));
			break;
		case STEEL:
			cout << "You opened the door, entering a completely steel room with a wooden floor." << endl << "The floor is very unstable... as you step forward the floor beings to callapse." << endl << "You try to quickly leave the room but the door has been shut behind you..." << endl << "You fall to your death...";
			you.addHp(-(you.getHp()));
			break;
		case DECOR:
			cout << "You opened the door, entering a small room with a plain box on the floor." << endl << "You open the box and there was a note in it that said: 'You lose'." << endl << "The door closes shut behind you and all light in the room darken... smog starts to appear out of the floor and you feel uncontrollably tired... you slowly fall asleep.";
			you.addHp(-(you.getHp()));
			break;
		case DOWNSTAIRS:
			cout << "You enter a small room with a staircase leading upstairs from where you started. There is also a southern path leading to another room.";
			break;
		case RIDDLE:
			cout << "You enter a room with no obvious paths except for the northern path from where  you began." << endl << "There is something written on the floor." << endl << " 'I am neither strong, elegant, or plain... I share my path with the direction   of darkness. I am the direction you seek.'";
			break;
		case NPC:
			cout << "You exit to discover that you are inside a castle town that is on top of a largemountain." << endl << "You see a small shack a couple of meters across the castle exit." << endl;
			if(oldMan.getHp() == 10)
				cout << "You enter and see an old man inside the house." << endl;
			else
				cout << "You enter the shack to see the corpse of an old man." << endl;
			cout << "If you exit the shack, you can:" << endl << " reenter the castle by heading east," << endl << " head north to explore the castle walls," << endl << " or head up the mountain to search the city.";
			break;
		case SWORD:
			cout << "You head up the mountain to find an abandon town." << endl << "You search the town for people, but instead find an torn-down blacksmith." << endl;
			if((world.getSword()) == 1)
				cout << "You enter and see nothing important except a sturdy sword sitting next a broken furnace.";
			else if (world.getSword() == 0)
				cout << "You enter to see nothing here but a broken furnace.";
			cout << endl << "If you exit the smith, you can head back down to the elder's house.";
			break;
		case KEY:
			cout << "You enter a guard post on the western side of the castle top." << endl << "There is no sign of life here." << endl;
			if(world.getKey() == 1)
				cout << "You search around the post and notice a key ring hanging on the wall." << endl;
			else if(world.getKey() == 0)
				cout << "This was where you found the key." << endl;
			cout << "The castle walls expand north and south, making it possible to move in those    directions.";
			break;
		case MOB:
			cout << "You walk across the castle top and see a giant nest in front of a tower leading up." << endl;
			if(lambentChicken.getHp() > 0)
				cout << "As you walk closer to the tower, a giant lambent chicken jumps down from the" << endl << "towertop. You backed off and notice that the chicken seems to be guarding the  nest, which happens to be in front of the tower enterance." << endl;
			else
				cout << "You see a giant dead chicken, covered in green blood. It seems it be emitting a glowing light." << endl;
			cout << "You can either try to head up the tower, head east to enter the castle again, orhead south to the guard post.";
			break;
		case ARMOR:
			if(lambentChicken.getHp() > 0)
			{
				cout << "The giant lambent chicken is guarding the path!" << endl << "You have moved back to the giant lambent chicken's nest";
				room = MOB;
			}
			else
			{
				cout << "As you head in the tower, you find an armory and a guards barrack at the top." << endl; 
				if(world.getArmor() == 1)
					cout << "There is a nice set of armor lying on top of a bed.";
				else if(world.getArmor() == 0)
					cout << "This was where you found the armor.";
				cout << "The only way of leaving this tower is by heading back down.";
			}
			break;
		case EASTER:
			if((dragon.getHp() > 0) && (dragon.getHp() < 100))
			{
				cout << "The dragon is awake and is blocking the path!" << endl << "You can't get past the dragon.";
				room = MOB2;
			}
			else
				cout << "You walk past a simple hallway inside the castle." << endl << "Something about this area seems odd... You feel your teeth tingle." << endl << "You can move east into a dinning hall or exit the castle by heading west.";
			break;
		case MOB2:
			cout << "You enter a large room, what use to be a dinning hall." << endl << "It now seems to be the home of a large red dragon now." << endl;
			if(dragon.getHp() == 100)
				cout << "The dragon is currently sleeping." << endl << "If you don't interact with it, you may be able to sneak by it.";
			else if((dragon.getHp() < 100) && (dragon.getHp() > 0))
				cout << "The dragon is awake and angry!" << endl << "It's blocking both paths, the only way to get out is to kill it.";
			else
				cout << "The dragon is sitting there, dead... because you killed him.";
			cout << endl << "You can head east, to the alchemy lab, or west, into a hallway.";
			break;
		case POTION:
			if((dragon.getHp() > 0) && (dragon.getHp() < 100))
			{
				cout << "The dragon is awake and is blocking the path!" << endl << "You have moved back to the dragon's den";
				room = MOB2;
			}
			else
				cout << "You enter a strange room filled with potions, tonics, and various herbs." << endl << "Obviously it was an alchemy lab at some point in time.";
			
			if(world.getPotion() == 1)
				cout << endl << "There's a red potion laying on the floor with a label stating: 'health potion'.";
			else if(world.getPotion() == 0)
				cout << endl << "None of these potions have any labels on them, so their effects are unknown." << endl << "It's best if you don't take any of them. Unforeseen side-effects could occur.";
			
			cout << endl << "You can either head south, into enterance of the throne room, or west, into the dragon's den.";
			break;
		case NPC2:
			cout << "You enter a slightly damaged room, what use to be the castle enterance.";
			if(soldier.getHp() != 0)
				cout << endl << "There is a soldier sitting down on the rubble.";
			else
				cout << endl << "The corpse of a guard is laying on some rubble.";
			cout << endl << "The rubble is blocking the original enterance, but you can still" << endl << " head west into the destroyed parts of the castle,\n head south to the throne room,\n or head north to the alchemy shop.";
			break;
		case SHIELD:
			cout << "You enter a nearly destroyed room, full of rubble and various objects.";
			if(world.getShield() == 1)
				cout << endl << "As you search the pile of rubble, you spy a shield on the far side of the room.";
			else if(world.getShield() == 0)
				cout << endl << "You search through the pile og junk to find nothing important.";
			cout << endl << "The rubble is blocking most exits, except the east door to the former enterance.";
			break;
		case BOSS:
			cout << "You enter the Dragon Lord's lair, what use to be the castle's throne room.";
			if(dragonLord.getHp() == 75)
				cout << endl << "The Dragon Lord is sitting on the throne, which is on a pile of gold." << endl << "He is paying no attention to you." << endl << "He seems to be counting gold coins, like a boss.";
			else if(dragonLord.getHp() <= 0)
				cout << endl << "The ashes of the Dragon Lord remain on top of the throne... Neat-o burrito.";
			else if((dragonLord.getHp() < 75) && (dragonLord.getHp() > 0))
				cout << endl << "Ther Dragon Lord is flying in the center of the room, with a staff at hand, shooting fireballs at you like some italian plumber.";
			cout << endl << "There is a locked door on the far west side of the room, right behind the Dragon Lord." << endl << "There is also the northern enterance from where you came.";
			break;
		case TREASURE:
			if(dragonLord.getHp() > 0)
			{
				cout << "The Dragon Lord is guarding the path!" << endl << "You can't get passed the throne room.";
				room = BOSS;
			}
			else if(you.getKey() == 0)
			{
				cout << "The door is locked, you need a key. HINT: Check the guard's station.";
				room = BOSS;
			}
			else
			{
				cout << endl << "You enter a small room, with a nicely decorated chest in the center." << endl << "You open the chest to find a golden flute designed similarly to a dragon." << endl << " - Flute added to inventory." << endl;
				world.setFlute(0);
				you.obtainFlute(1); 
				cout << "There is a long staircase leading up and a door on" << endl << "the east side leading back to throne room.";
			}
			break;
		case EGG:
			cout << "You are at a weird balcony, there is no obvious exits..." << endl <<  "How'd you get here?" << endl << "There is a small, blue fairy flying around the balcony.";
			break;
		case END:
			cout << "You head up to the balcony and spot a Dragon's nest." << endl << "There is no sign of a dragon, but there is an egg inside the nest." << endl << "The flute you just picked up starts to glow magically.";
			break;
		default:
			break;
	}
}
/**
* Function that computes all user inputs, passes it through various conditionals and modifies the game based on the input.
* 
* @params An instance array of the class room, one integer passed by reference, and various instances of the player, npcs, and game world all passed by reference.
* @return none
*/
void GameCommands::userCommands(int &room, Room rooms[], Player &you, Game &world, Npc &oldMan, Npc &lambentChicken, Npc &soldier, Npc &dragon, Npc &dragonLord)
{
	while(fgets(buff, sizeof buff, stdin) != NULL || (you.getHp() <= 0) || (winrarIsYou != 1)) // While player isn't dead, the player won, or there is a null interpretation of input
	{
		// Taking Inputs
		sscanf(buff, "%s %n", cmd, &pos);	// sscanf function, used instead of cin because I want to take in a single input into multiple variables
		params = &buff[pos];				// params is set to a reference to buff containing the amount of pos assigned in the user input
		
		// Commands
		// Command for movement
		if((strcmp(cmd, "move") == 0) || (strcmp(cmd, "go") == 0) || (strcmp(cmd, "walk") == 0) || (strcmp(cmd, "head") == 0))
		{
			room = move(room, params, rooms);		// Reassigning room to the return of function move with the parameters of room and param
			cout << endl;							// Outputs line break.
			storyLine(room, you, world, oldMan, lambentChicken, soldier, dragon, dragonLord);	// Displays the story based on the room.
		}
		// Help
		else if(strcmp(cmd, "help") == 0)
			cout << endl << "================================================================================" << endl << "Instructions:" << endl << "- 'move ?' to move to a specified location." << endl << "   where '?' is 'north', 'south', 'east', 'west', 'up', and 'down'." << endl << "   or 'n', 's' ,'e', 'w', 'u', and 'd'." << endl << "- 'observe' to take a closer look at the room and possibly find secrets." << endl << "- 'whereami' to redisplay the decription of the your current room." << endl << "- 'help' to display this list of commands." << endl << "- 'stats' to view your status." << endl << "- 'take ?' to add an item to your inventory." << endl << "   where '?' is the item name." << endl << "- 'inventory' to view all of your items." << endl << "- 'use ?' to use a usable item from your inventory." << endl << "   where '?' is the item name." << endl << "- 'talk' to speak to any NPCs and enemies in the current area." << endl << "- 'attack' to fight any enemies and NPCs in the current area." << endl << endl << "================================================================================";
		// Redisplays location and story
		else if(strcmp(cmd, "whereami") == 0)
		{
			cout << endl << "You are currently at " << rooms[room].name << endl << endl;
			storyLine(room, you, world, oldMan, lambentChicken, soldier, dragon, dragonLord);
		}
		// Stats of the player
		else if((strcmp(cmd, "stats") == 0) || (strcmp(cmd, "stat") == 0))
			you.stats();
		// Player skill observe, outputs hints based on the area
		else if(strcmp(cmd, "observe") == 0)
		{
			cout << endl;
			if(room == START)
				cout << "You examine the room, and notice a small indent on the floor. As you step on it,the indent opens, revealing a staircase.";
			else if(room == RIDDLE)
				cout << "You examine the room, and notice part of the west wall has a hidden door." << endl << "This wall shares the same direction with the dark hallway at the beginning.";
			else if(room == EASTER)
				cout << "You look at the ceiling and see something engraved on it: 'xyzzy'.";
			else if(room == EGG)
				cout << "You look around the balcony, but see nothing hinting how exit." << endl << "Maybe you should say that magic word again. 'xyzzy'.";
			else
				cout << "You looked around the area and see nothing of importance hidden anywhere.";
		}
		// Command for user to obtain items on the 'map'.
		else if((strcmp(cmd, "take") == 0) || (strcmp(cmd, "grab") == 0) || (strcmp(cmd, "retrieve") == 0) || (strcmp(cmd, "get") == 0))
			takeItem(room, params, you, world);
		// Command to use an item.
		else if((strcmp(cmd, "use") == 0) || (strcmp(cmd, "consume") == 0))
			useItem(room, params, you, world);
		// Displays player items
		else if(strcmp(cmd, "inventory") == 0)
			you.inventory();
		// Npc interaction
		else if((strcmp(cmd, "talk") == 0) || (strcmp(cmd, "speak") == 0))
		{
			// NPC 1: The Elder
			cout << endl;
			if((room == NPC) && (you.getSword()  == 0) && (oldMan.getHp() == 10))
				cout << "Old Man:" << endl << " 'Hello there sonny, it's pretty dangerous to go further into the castle alone." << endl << " You should search the town for something to defend yourself.'";
			else if((room == NPC) && (you.getSword()  == 1) && (oldMan.getHp() == 10))
				cout << "Old Man:" << endl << " 'Looks like you found a sword! That'll keep you safe from all the things inside the castle.";
			else if((room == NPC) && (oldMan.getHp() <= 0))
				cout << "You're speaking to the corpse of an old man... Weirdo.";
			else if((room == NPC) && (oldMan.getHp() < 10) && (oldMan.getHp() > 0))
				cout << "The old man is hostile and refuses to talk to you.";
			// NPC 2: The Soldier
			else if((room == NPC2) && (you.getShield() == 0) && (soldier.getHp() == 80))
				cout << "Soldier:" << endl << " 'Hello. You're here to kill the dragon lord too?" << endl << " You're probably confused about what's going on, right?" << endl << " This castle use to be our home, until the dragon lord came and claimed it." << endl << " I use to be the guard's captain... and I recall you were a prisoner." << endl << " Can't remember why though. Well, that all doesn't matter right now." << endl << " If you want to stop the Dragon Lord, go ahead," << endl << " but your not gonna go far without a shield." << endl << " I think there's a shield somewhere in the rubbles of this castle.'";
			else if((room == NPC2) && (you.getShield() == 1) && (soldier.getHp() == 80))
				cout << "Soldier:" << endl << " 'Oh, you found a shield? Good, that should give you some leverage.'";
			else if((room == NPC2) && (soldier.getHp() <= 0))
				cout << "You're speaking to the corpse of a soldier... Freak.";
			else if((room == NPC2) && (soldier.getHp() < 80) && (soldier.getHp() > 0))
				cout << "The Soldier is now hostile, and refuses to speak with you.";
			// MOBs
			else if((room == EGG))
				cout << "Fairy:" << endl << " 'Hey, listen! You found an easter egg..." << endl << " What ever that means.'";
			else if((room == MOB) && (lambentChicken.getHp() > 0))
				cout << "You just tried to talk to a chicken... Sadly, chickens can't speak.";
			else if((room == MOB) && (lambentChicken.getHp() <= 0))
				cout << "You just tried to talk to a dead chicken... Sadly, dead chickens can't speak.";
			else if((room == MOB2) && (dragon.getHp() > 0) && (dragon.getHp() < 100))
				cout << "The dragon seems to understand what you are saying, but is hostile regardless.";
			else if((room == MOB2) && (dragon.getHp() == 100))
				cout << "Do you really want to disturb a sleeping dragon?";
			else if((room == MOB2) && (dragon.getHp() <= 0))
				cout << "What are you? Dovahkiin? Dragon Born? Fus Ro Dah?! Silly player, only Alduin can talk to dead dragons.";
			else if((room == BOSS) && (dragonLord.getHp() > 0))
				cout << "Dragon Lord:" << endl << " 'Fool, you dare enter my new kingdom?! Prepare to die!'";
			else if((room == BOSS) && (dragonLord.getHp() <= 0))
				cout << "You stood over the Dragon Lord body and started to squat up and down repeatedly. How's that for talking?";
			else
				cout << "Talk to who? Yourself?";
		}
		// Attacking an npc, based on location.
		else if(strcmp(cmd, "attack") == 0)
		{
			if(room == NPC)
				oldMan.attack(you, room);
			else if(room == NPC2)
				soldier.attack(you, room);
			else if (room == MOB)
				lambentChicken.attack(you, room);
			else if (room == MOB2)
				dragon.attack(you, room);
			else if (room == BOSS)
				dragonLord.attack(you, room);
			else if(room == END)
				cout << endl << "You shouldn't attack the dragon egg, it could be useful. Try using that flute of yours.";
			else if(room == EGG)
				cout << endl << "You attacked and killed the fairy, but somehow it magically came back to life." << endl << "Fairy:" << endl << " 'Ouch! That hurt, but lucky for me, fairies can only die by using" << endl << " their souls to heal others.'";
			else
				cout << "There's nothing to attack.";
		}
		// Other Commands
		else if(strcmp(cmd, "yes") == 0)
			cout << endl << "Alrighty then...";
		else if(strcmp(cmd, "no") == 0)
			cout << endl << "Too bad.";
		else if(strcmp(cmd, "killself") == 0)
		{
			cout << endl << "Suicide is not the answer.";
		}
		// Easter Egg command
		else if(strcmp(cmd, "xyzzy") == 0)
		{
			cout << endl;
			if(room == EASTER)
			{
				cout << "Saying those magic words teleported you to a strange balcony." << endl << "The balcony has a strange fairy floating at its edge. It is small, blue," << endl << "and emitting a soft light.";
				room = EGG;
			}
			else if(room == EGG)
			{
				cout << "Saying those magic words teleported you back into the hallway.";
				room = EASTER;
			}
			else
				cout << "Professor Oak:" << endl << " 'Now's not the time to use that.'";
		}
		else
			cout << endl << "ERROR: Invalid input:" << endl << "'" << cmd << "' is not a command." << endl << "Type in 'help' for a list of commands.";
		// Losing
		if(you.getHp() <= 0)
		{
			cout << endl << endl << "You died." << endl << "Game Over." << endl << endl << "HINT: Have you tried using your 'observe' skill?" << endl;
			break;
		}
		// Winning
		if(winrarIsYou == 1)
		{
			cout << endl << endl << "Congratz! Winner is you!" << endl << "Game Over." << endl;
			break;
		}
		// Quit
		else if(strcmp(cmd, "quit") == 0)
		{
			cout << endl << "You then stood there, idle, staring blankly forward..." << endl << "You then spontaneously explode into a million pieces." << endl << "The End." << endl;
			break;
		}
		cout << endl << endl << "> ";
	}
}

/** ----- Functions, Methods, Main ----- **/

/**
* Main function that initializes the program.
* 
* @params none
* @return none
*/
void main()
{
	// Local Variables
	int room = START;	// Primitive integer that will hold the current location of the player
	char beginAndEnd = 'x';	// Character that will be used to start the game.
	// Local Instances of classes and structures.
	Room rooms[22] =
	{
		// Rooms, char *name become the area labels, and int move[7] are the possible movement directions
		{"Null"},
		{"the beginning.",								{WOODEN, DECOR, STEEL, DARK, NONE, DOWNSTAIRS, START}},
		{"a plain wooden room.",						{NONE, NONE, NONE, NONE, NONE, NONE, WOODEN}},
		{"a completely steel room.",					{NONE, NONE, NONE, NONE, NONE, NONE, STEEL}},
		{"a decorated room.",							{NONE, NONE, NONE, NONE, NONE, NONE, DECOR}},
		{"the dark hallway.",							{NONE, NONE, NONE, NONE, NONE, NONE, DARK}},
		{"the hidden lower level.",						{NONE, RIDDLE, NONE, NONE, START, NONE, DOWNSTAIRS}},
		{"the riddle room.",							{DOWNSTAIRS, NONE, NONE, NPC, NONE, NONE, RIDDLE}},
		{"the Elder's House.",							{KEY, NONE, RIDDLE, NONE, SWORD, NONE, NPC}},
		{"the abandoned blacksmith.",					{NONE, NONE, NONE, NONE, NONE, NPC, SWORD}},
		{"the abandoned guard station.",				{MOB, NPC, NONE, NONE, NONE, NONE, KEY}},
		{"the giant lambent chicken's nest.",			{NONE, KEY, EASTER, NONE, ARMOR, NONE, MOB}},
		{"the armory.",									{NONE, NONE, NONE, NONE, NONE, MOB, ARMOR}},
		{"a plain hallway.",							{NONE, NONE, MOB2, MOB, EGG, NONE, EASTER}},
		{"the dragon's den.",							{NONE, NONE, POTION, EASTER, NONE, NONE, MOB2}},
		{"the alchemy lab.",							{NONE, NPC2, NONE, MOB2, NONE, NONE, POTION}},
		{"the crestfallen soldier's room.",				{POTION, BOSS, NONE, SHIELD, NONE, NONE, NPC2}},
		{"the legendary shield's cavern.",				{NONE, NONE, NPC2, NONE, NONE, NONE, SHIELD}},
		{"the Dragon Keeper's lair.",					{NPC2, NONE, NONE, TREASURE, NONE, NONE, BOSS}},
		{"the Dragon Keeper's booty room.",				{NONE, NONE, BOSS, NONE, END, NONE, TREASURE}},
		{"the ending.",									{NONE, NONE, NONE, NONE, NONE, NONE, END}},
		{"a weird balcony.",							{NONE, NONE, NONE, NONE, NONE, EASTER, EGG}},
	};
	Game world(1, 1, 1, 1, 1, 1);
	Player you(100, 1, 0, 0, 0, 0, 0, 0, 0);
	Npc oldMan(10, 5, 0, "innocent old man");
	Npc soldier(80, 60, 30, "kind hearted soldier");
	Npc lambentChicken(50, 10, 0, "lambent chicken");
	Npc dragon(100, 75, 25, "dragon");
	Npc dragonLord(75, 70, 30, "dragon lord");
	GameCommands userInput(0);

	// Intro
	cout << "Hello player! Welcome to Ye Dungeon Game, a Text based adventure game." << endl << "Here are the list of commands:" << endl << endl << "================================================================================" << endl << "Instructions:" << endl << "- 'move ?' to move to a specified location." << endl << "   where '?' is 'north', 'south', 'east', 'west', 'up', and 'down'." << endl << "   or 'n', 's' ,'e', 'w', 'u', and 'd'." << endl << "- 'observe' to take a closer look at the room and possibly find secrets." << endl << "- 'whereami' to redisplay the decription of the your current room." << endl << "- 'help' to display this list of commands." << endl << "- 'stats' to view your status." << endl << "- 'take ?' to add an item to your inventory." << endl << "   where '?' is the item name." << endl << "- 'inventory' to view all of your items." << endl << "- 'use ?' to use a usable item from your inventory." << endl << "   where '?' is the item name." << endl << "- 'talk' to speak to any NPCs and enemies in the current area." << endl << "- 'attack' to fight any enemies and NPCs in the current area." << endl << endl << "================================================================================" << endl << "Press enter begin the adventure: ";
	while(beginAndEnd != '\n')
	{
		cin.get(beginAndEnd);
	}
	beginAndEnd = 'x';
	freopen("Ye_Dungeon_Receipt.txt","w",stdout);
	cout << endl << "You awaken in a small dark room, it is hard for you to see and you have no clue where you are or what happened to you. Suddenly tourches light up in the room." << endl;
	userInput.storyLine(room, you, world, oldMan, lambentChicken, soldier, dragon, dragonLord);
	cout << endl << endl << "> ";
	userInput.userCommands(room, rooms, you, world, oldMan, lambentChicken, soldier, dragon, dragonLord);
	cout << endl << "Press enter to exit the game: ";
	while(beginAndEnd != '\n')
	{
		cin.get(beginAndEnd);
	}
}