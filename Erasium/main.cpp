#include "Character.h"


void hud();
void combat();
void combatHud();
void moving();
void createMonster();
void levelUp();


int monsterHp = 0, monsterXp = 0, monsterLevel = 0;
std::string monsterName[] = { "TissuePaper", "Rubber", "Whitener", "PencilEraser", "Tearer", "InkRubber"};
int currentMonsterName = 5;
std::string currentMonster = " ";
int counter = 0;
Character character;

int main() {
	character.characterCreation();
	hud();
	moving();
	return 0;
}

void hud() {
	Sleep(2000);
	system("cls");
	if (character.mapLevel == 0) {
		character.mapName = "Paper";
	}
	else if (character.mapLevel == 1) {
		character.mapName = "Diary";
	}
	else if (character.level == 2) {
		character.mapName = "Journal";
	}
	else if (character.level == 3) {
		character.mapName = "Book";
	}
	else if (character.level == 4) {
		character.mapName = "Anthology";
	}
	else if (character.level == 5) {
		character.mapName = "Biblio";
	}
	std::cout << GREEN;
	std::cout << "Name: " << character.name << "			Health: " << character.totalHealth << "\nBrand: " << character.brand
		<< "\nSex: " << character.sex << "\nLevel: " << character.level << "\nXP: " << character.current_xp << "\nXp to Level: " << character.xp_to_level << 
		"\nName of Location: " << character.mapName << std::endl;
	std::cout << std::endl;
	std::cout << "\n";

	std::cout << WHITE;
	moving();

}

void combatHud() {
	Sleep(2000);
	system("cls");
	std::cout << RED;
	std::cout << "Name: " << character.name << "\t|\tMonster Name: " << currentMonster << "\nTotal Health: " << character.totalHealth << "\t|\tMonster Health: "
		<< monsterHp << "\nLevel: " << character.level << "\t|\tMonster Level: " << monsterLevel << std::endl;
	std::cout << WHITE;
}

void combat() { 

	combatHud();
	int playerAttack;
	int playerDamage = 20 * character.level / 2;
	int monsterAttack = 6 * monsterLevel / 2;

	if (character.totalHealth >= 1 && monsterHp >= 1) {
		std::cout << std::endl;
		std::string first = "What do you wish to do?";
		character.printer(first);
		std::cout << "1. Write\n";
		std::cout << "2. Sharpen\n";
		std::cout << "3. Run away";
		std::cout << std::endl;
		std::cin >> playerAttack;

		if (playerAttack == 1) {
			//attack
			std::cout << "Attacking...you did " << playerDamage << " to the " << currentMonster << std::endl;
			monsterHp = monsterHp - playerDamage;
			Sleep(1000);
			combatHud();
			if (monsterHp >= 1) {
				std::cout << std::endl;
				std::cout << "Monster is Attacking...\n ";
				character.totalHealth = character.totalHealth - monsterAttack;
				std::cout << "You Suffered " << monsterAttack << " hp " << character.totalHealth << std::endl;

				if (character.totalHealth <= 0) {
					character.totalHealth = 0;
					system("cls");
					std::cout << "You died!\nYou were level: " << character.level << "You got killed by " << currentMonster << std::endl;
					Sleep(2000);
					exit(0);
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;

				std::cout << std::endl;
				std::cout << "You defeated " << currentMonster << " You are rewarded with " << monsterXp << "xp.\nWell Written\n";
				character.mapLevel++;

				if (character.level != character.maxLevel) {
					character.current_xp = character.current_xp + monsterXp;
					levelUp();
				}

				Sleep(1000);
				hud();
			}
			Sleep(500);
			combat();
		}
		else if (playerAttack == 2) {
			//block
			std::cout << "Blocking and Sharpening!\n";
			srand(time(0));
			int i = rand() % 100 + 1;
			if(i >= 70) {
				std::cout << "You blocked the incoming attack!\n";
				character.heal = character.level * 10 / 2;
				std::cout << "You have sharpened your pencil tip now for" << character.heal << std::endl;
				character.totalHealth += character.heal;
				Sleep(1000);
				combat();
			}
			else {
				std::cout << "You failed to block the attack\n";
				character.totalHealth -= monsterAttack;
				std::cout << "You words were erased from existence, you took damage for " << monsterAttack << " current HP is " << character.totalHealth << std::endl;
				Sleep(500);
				combat();
			}
		}
		else if (playerAttack == 3) {
			//run
			std::cout << "You try to write somewhere else and run\n";
			srand(time(0));
			int x = rand() % 100 + 1;
			if (x >= 70) {
				std::cout << "You run away for now and live to write next time\n";
				hud();
			}
			else {
				std::cout << "You failed to run away\n";
				std::cout << "The monster has erased some of your words\n";
				character.totalHealth -= monsterAttack + 10;
				std::cout << "The monster has erased some of your words\n";
				std::cout << "You suffered " << monsterAttack + 10 << " Your current health is " << character.totalHealth << std::endl;
				Sleep(500);
				combat();
			}
		}	
		else {
			std::cout << "Invalid Number\n";
			Sleep(500);
			combat();
		}
	}	
}

void moving() {
	int choice;

	std::string first = "What do you wish to do?";
	character.printer(first);
	std::cout << "1. Write Forward\n";
	std::cout << "2. Sharpen\n";
	std::cout << "3. Overwrite Backwards\n";
	std::cout << "\n\n";

	std::cin >> choice;

	if (choice == 1) {
		srand(time(0));
		int temp = rand() % 100 + 1;
		std::cout << "You begin writing forward...\n";
		if (temp >= 60) {
			//encounter a monster
			createMonster();
			std::string tempName = monsterName[rand() % currentMonsterName];
			std::cout << "A " << tempName << "!!! Prepare to fight!\n";
			currentMonster = tempName;
			Sleep(1000);
			combat();
		}
		std::cout << "You find nothing of Interest!\n";
		Sleep(1000);
		hud();
	}
	else if (choice == 2) {
		std::cout << "You want to stop and sharpen yourself for a while ";
		if (character.totalHealth <= 99) {
			character.totalHealth += 10 * character.level;
		}
		std::cout << "You sharpened yourself and your health now is: " << character.totalHealth << std::endl;
		Sleep(1000);
		hud();
	}
	else if (choice == 3) {
		srand(time(0));
		int temp = rand() % 100 + 1;
		std::cout << "You begin overwriting backward...\n";
		if (temp >= 50) {
			//encounter a monster
			createMonster();
			std::string tempName = monsterName[rand() % currentMonsterName];
			std::cout << "A " << tempName << "!!! Prepare to fight!\n";
			currentMonster = tempName;
			Sleep(1000);
			combat();
		}
		std::cout << "You find nothing of Interest!\n";
		Sleep(500);
		hud();
	}
	else {
		std::cout << "Invalid Number\n";
		Sleep(500);
		moving();
	}
}

void levelUp() {

	if (character.current_xp >= character.xp_to_level) {
		character.xp_to_level += floor(character.level + 12 * pow(2, character.level/7));
		character.totalHealth = floor(character.totalHealth + 6 * pow(2, character.level / 8));

		if (character.level >= character.minLevel && character.level <= character.maxLevel) {
			character.level++;
		}
		else {
			character.level = 60;
		}
		character.maxHealth = character.totalHealth;
		std::cout << "Your pencils are now bolder and darker! You are now a level " << character.level << std::endl;
		std::cout << "Your total health increased! Your max health now is " << character.totalHealth << std::endl;
		std::cout << std::endl;
		Sleep(1000);
		levelUp();
	}
	Sleep(2000);
	hud();
}

void createMonster() {
	monsterHp = 30;
	srand(time(0));
	monsterLevel = (rand() % 3) + character.level;
	srand(time(0));
	monsterHp = (rand() % 30) * monsterLevel;
	monsterXp = monsterHp;

	if (monsterHp == 0) {
		createMonster();
	}
	if (monsterLevel == 0) {
		createMonster();
	}
}

void createBoss() {
	int bossHp = 500;
	srand(time(0));
	int bossLevel = (rand() % 3) + character.level;
	srand(time(0));
	bossHp = (rand() % 30) * monsterLevel;
	int bossXp = bossHp;
}

void bossLevel() {
	while (character.mapName == "Biblio") {
		createBoss();
		break;
	}
}