//gets header file
#include "Character.h"
#include <iostream>

//displays the stats for each character
void Character::DisplayStats() {
	std::cout << "_______________\n";
	std::cout << "Character Stats\n";
	std::cout << "---------------\n";
	std::cout << "  Name | " << this->name << std::endl;
	std::cout << "Health | " << this->health << std::endl;
	std::cout << "    AC | " << this->ac << std::endl;
	std::cout << "Weapon | " << this->weapon << std::endl;
	std::cout << "---------------\n";
}

//method for displaying a message for each player
void Character::Talk(std::string message) {
	std::cout << message << std::endl;
}

//decreases health by the inputted damage
void Character::ChangeHealth(int damage) {
	this->health -= damage;
}

//returns the value of the health when called
int Character::ReturnHealth() {
	return this->health;
}