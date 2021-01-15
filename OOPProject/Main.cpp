#include<iostream>
#include "GameStructure.h"
#include "Pirate.h";

void introduction();
int randomRoll(int min, int max);

int main() {

	introduction();

	Pirate* BlackBeard = new Pirate("BlackBeard");

	BlackBeard->sing();
	std::cout << "My name is " << BlackBeard->name << std::endl;

	return 0;
}


void introduction() {

	std::cout << "\n\n\t\tWelcome to Pirates Vs Ninjas!\n\n";
	std::cout << "Prepare for War" << std::endl;
	
	
}

int randomRoll(int min, int max) {
	int random = (std::rand() % (max-min)) + min;
	return random;
}