#pragma once
#include <string>
//gets the game structure class
#include "GameStructure.h"
//character that inherits from game structure
class Character : public GameStructure
{
	//private properties
private:
	//health set to 20
	int health = 20;
public:
	//initialize all variables both ninja and pirate
	std::string name = "";
	int ac = 13;
	std::string weapon = "";
	//method prototypes
	void DisplayStats();
	void Talk(std::string message);
	void ChangeHealth(int damage);
	int ReturnHealth();
};

