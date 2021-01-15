#pragma once
#include <string>
#include "GameStructure.h"
class Character : public GameStructure
{
public:
	std::string name = "";
	int health;
	void DisplayStats();
	void Talk(std::string message);
};

