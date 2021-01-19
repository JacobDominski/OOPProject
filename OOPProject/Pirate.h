#pragma once
#include "Character.h"
//pirate class that inherits character
class Pirate : public Character
{
	//public properties
public:
	//pirate constructor
	Pirate(std::string name) {
		//initializes the name and weapon
		this->name = name;
		this->weapon = "Sword";
	}
	//method prototypes
	void sing();
	void UseSword();
	
};

