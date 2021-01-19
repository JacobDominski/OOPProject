#pragma once
#include "Character.h"
//ninja class that inherits the character
class Ninja : public Character
{
	//public encapsulation
public:
	//ninja constructure
	Ninja(std::string name) {
		//initializes the name and weapon
		this->name = name;
		this->weapon = "Throwing Stars";
	}
	//method prototypes
	void ThrowStars();
	void Talk();
	
};

