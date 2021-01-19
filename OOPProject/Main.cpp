//iostream gets the console
#include <iostream>
//map is a data structure used for differentiating
//between the player and the enemy
#include <map>
//ctime gets the clock time
#include <ctime>
//windows h is for the sleep function
#include <windows.h>
//game structure holds all the classes
#include "GameStructure.h"
//character is the base class for all playable characters
#include "Character.h"
//pirate is one of the characters
#include "Pirate.h"
//ninja is another character
#include "Ninja.h"

//these are prototype functions so the computer knows they exist
void introduction();
void pause(std::map<std::string, Character*>& character, std::string name);
int randomRoll(int min, int max);
int characterSelection();

//this is the main function that runs first
int main() {
	//declaring and intializing all the variables needed
	//game running keeps the while loop going
	bool GameRunning = true;
	//waittime is the time in milliseconds used in each sleep
	int waitTime = 1500;
	//attack roll stores the result of a D20
	int attackRoll;
	//damage stores the amount do damage the player or enemy takes
	int damage;
	//name stores the player's name
	std::string name;
	//this map stores all the characters and matches it with player or enemy
	std::map<std::string, Character*> characters;
	//sets the seed for the random number generator
	srand(time(0));
	//calls the introduction
	introduction();
	//gets the user's choice
	int choice = characterSelection();
	//get's the user's name
	std::cout << "Enter your name: ";
	std::cin >> name;

	//if the user chose the pirate
	if (choice == 1) {
		//sets player key to the pirate value and passes in the name
		characters["player"] = new Pirate(name);
		//sets the enemy key to the ninja value
		characters["enemy"] = new Ninja("enemy");
	}
	//if the user chose the ninja
	else {
		//sets the player key to the ninja value and passes in the name
		characters["player"] = new Ninja(name);
		//sets the enemy key to the pirate value
		characters["enemy"] = new Pirate("enemy");
	}

	//main game loop
	while (GameRunning) {
		//waits for 300 milliseconds
		Sleep(300);
		//displays new round and each character's health
		std::cout << "\n\n\t\t --- New Round! ---\n     Player's health: " << characters["player"]->ReturnHealth() << " | Enemy's health: " << characters["enemy"]->ReturnHealth() << std::endl;
		std::cout << "-----------------------\n\nPlayer's turn!\n\n-----------------------\n";

		//pauses for user input
		pause(characters, "player");


		std::cout << "\nrolling a D20 to attack\n";
		//waits 1.5 seconds
		Sleep(waitTime);
		//gets attack roll
		attackRoll = randomRoll(1, 20);

		std::cout << "You rolled a " << attackRoll << "! \n";
		//waits 1.5 seconds
		Sleep(waitTime);

		//if the attack roll is higher the the enemy's armor class
		if (attackRoll > characters["enemy"]->ac) {

			std::cout << "That's a hit!\n";
			//waits 1.5 seconds
			Sleep(waitTime);

			//does 1d6 damage
			damage = randomRoll(1, 6);
			//alters enemy's health
			characters["enemy"]->ChangeHealth(damage);
			std::cout << "You did " << damage << " points of damage!\n";
			//waits 1.5 seconds
			Sleep(waitTime);
			//if the enemy's health is less than or equal to 0
			if (characters["enemy"]->ReturnHealth() <= 0) {
				//enemy dies
				std::cout << "The enemy is dead!";
				//exits the loop which stops the game
				break;
			}
			else {
				//displays remaining health
				std::cout << "The enemy has " << characters["enemy"]->ReturnHealth() << " left!\n";
			}
		}
		else {
			std::cout << "Oh no! You missed!\n";
		}
		//waits 1.5 seconds
		Sleep(waitTime);
		std::cout << "-----------------------\n\nEnemy's turn!\n\n-----------------------\n";

		//get enemy's attack roll
		attackRoll = randomRoll(1, 20);
		//waits 1.5 seconds
		Sleep(waitTime);

		std::cout << "The enemy rolled a " << attackRoll << "! \n";
		//checks if attack roll is greater than player's ac
		if (attackRoll > characters["player"]->ac) {
			std::cout << "That's a hit!\n";
			//waits 1.5 seconds
			Sleep(waitTime);
			//get's damage
			damage = randomRoll(1, 6);
			//decreases player's health
			characters["player"]->ChangeHealth(damage);
			std::cout << "The enemy did " << damage << " points of damage!\n";
			//checks if player's health is less than or equal to 0
			if (characters["player"]->ReturnHealth() <= 0) {
				//player dead
				std::cout << "You are dead!";
				//exits the loop stopping the game
				break;
			}
			else {
				//displays the remaining health of the player
				std::cout << "You have " << characters["player"]->ReturnHealth() << " left!\n";
			}
		}
		else {
			std::cout << "The enemy missed!\n";
		}
	}

	return 0;
}

//pause function to stop the program temporarily
void pause(std::map<std::string, Character*>& character, std::string name) {
	//declare command variable
	std::string cmd;
	while (1) {
		//asks the user to type /stats
		std::cout << "\nType '/stats' to see player stats or press any enter to continue...\n";
		//gets user input
		std::getline(std::cin, cmd);
		//if the user types /stats
		if (cmd == "/stats") {
			//displays user's stats
			character[name]->DisplayStats();
		}
		else {
			//breaks out of the loop
			break; 
		}
	}
}

//introduction
void introduction() {
	std::cout << "\n\n\t\tWelcome to Pirates Vs Ninjas!\n\n";
	std::cout << "Prepare for War\n\n";
	
}

//get's character's selection
int characterSelection() {
	//stores option in this variable
	int option = 0;
	std::cout << "Select your character : \n1.Pirate\n2.Ninja\n";
	//keeps asking to enter 1 or 2
	while (option != 1 && option != 2) {
		std::cout << "Enter 1 or 2: \n";
		//gets user's option
		std::cin >> option;
	}
	
	return option;
}


//gets a random number given a minimum and maximum
int randomRoll(int min, int max) {
	//gets random number and stores in random variable
	int random = (std::rand() % (max-min)) + min;
	return random;
}