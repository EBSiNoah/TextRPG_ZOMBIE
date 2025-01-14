#pragma once
#include <iostream>

class Character {
private:
	string name;
	int hp;
	int attackPower;
	int exp;
	int gold;

	public
		void gainExp(int amount) { exp += amount; }
	void gainGold(int amount) { gold += amount; }
};

class Monster {
private:
	string name;
	int hp;
	int attackPower;

	void printStatus() {
		cout << "좀비" << name << " 등장,  체력: " << hp << ", 공격력: " << attackPower << endl;
	}
};

void battle(Character& player, Zombie& zombie)

class ZombieFactory

class Shop