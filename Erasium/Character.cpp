#include "Character.h"

Character::Character() {
	name = " ";
	brand = " ";
	sex = " ";
	level = 1;
	current_xp = 0;
	base_xp = 90;
	xp_to_level = base_xp;
	minLevel = 1;
	maxLevel = 60;
	health = 0;
	totalHealth = 0;
	maxHealth = 0;
	heal = 0;
	mapName = " ";
	mapLevel = 0;
	playerBrand = { "nataraj", "apsara", "camlin", "doms", "fabercastle" };
}

void Character::characterCreation() {
	
	std::cout << "In a far away land..." << std::endl;
	Sleep(500);
	std::cout << "where reality wasn't what we see today..." << std::endl;
	Sleep(500);
	std::cout << "Where words meant everything and the people who destroyed them were the evil!" << std::endl;
	std::cout << "The World of Erasium!!! where words were the strength and beckoning of commoners" << std::endl;
	Sleep(500);
	std::cout << "\n";
	Sleep(500);
	system("cls");

	int counter = 3;
	std::cout << "Enter your name PencilWarrior: " << std::endl;
	std::cin >> name;

	std::cout << "Enter your brand name PencilWarrior: " << std::endl;
	std::cout << "Nataraj\n";
	std::cout << "Apsara\n";
	std::cout << "Camlin\n";
	std::cout << "Doms\n";
	std::cout << "FaberCastle\n";
	std::cout << "Type your brand of pencil below \n\n";
	std::cin >> brand;

	std::for_each(brand.begin(), brand.end(), [](char& c) {
		c = ::tolower(c);
		});

	for (int i = 0; i < sizeof(playerBrand); i++) {
		if (brand == "nataraj") {
			health = 80;
			break;
		}
		if (brand == "apsara") {
			health = 120;
			break;
		}
		if (brand == "camlin") {
			health = 60;
			break;
		}
		if (brand == "doms") {
			health = 100;
			break;
		}
		if (brand == "fabercastle") {
			health = 140;
			break;
		}
		else {
			health = 100;
			break;
		}
	}

	std::cout << std::endl;
	std::cout << "Enter your sex PencilWarrior: " << std::endl;
	std::cin >> sex;
	system("cls");

	for (int i = 0; i <= counter; i++) {
		if (i == 0) {
			std::cout << "Creating character.\n";
		}
		if (i == 1) {
			std::cout << "Creating character..\n";
		}
		if (i == 2) {
			std::cout << "Creating character...\n";
			break;
		}

		Sleep(400);
		system("cls");
		counter++;
	}

	name[0] = toupper(name[0]);
	brand[0] = toupper(brand[0]);
	sex[0] = toupper(sex[0]);

	totalHealth = health;
	maxHealth = totalHealth;
}