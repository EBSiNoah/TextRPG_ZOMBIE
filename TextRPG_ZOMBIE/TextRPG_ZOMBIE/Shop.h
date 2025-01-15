#pragma once
#ifndef SHOP_H
#define SHOP_H
#include "Character.h"

class Shop {
private:
	Character* character;

public:
	Shop(Character* character);
	~Shop();

	void displayMenu();
	void displayItems(/*Character& character*/);
	void buyItem();
	void sellItem();


};
#endif
