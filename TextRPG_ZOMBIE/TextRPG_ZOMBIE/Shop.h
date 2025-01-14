#pragma once
#include "Character.h"

class Shop {
private:
	Character* character;

public:
	Shop(Character* character);
	~Shop();

	void displayItems();
	void buyItem();
	void sellItem();

};