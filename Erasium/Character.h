#pragma once
#include"Header.h"
class Character {

public:
	Character();
	std::string name, brand, sex;
	std::vector<std::string> playerBrand;
	int health;
	int totalHealth;
	int maxHealth;
	int heal;
	int level;
	int current_xp;
	int base_xp;
	int xp_to_level;
	int minLevel;
	int maxLevel;
	int mapLevel = 0;
	std::string mapName;

	void characterCreation();

};

