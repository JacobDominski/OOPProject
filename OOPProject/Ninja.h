#pragma once
#include "Character.h"
class Ninja : public Character
{
public:
	Ninja(std::string name) {
		this->name = name;
		this->health = 100;
	}
	void ThrowStars();

};

