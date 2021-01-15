#pragma once
#include "Character.h"
class Pirate : public Character
{

public:
	Pirate(std::string name) {
		this->name = name;
		this->health = 100;
	}
	void sing();
	void UseSword();
};

