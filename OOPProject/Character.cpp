#include "Character.h"
#include <iostream>

void Character::DisplayStats() {
	std::cout << "This is the stats\n";
}

void Character::Talk(std::string message) {
	std::cout << message;
}