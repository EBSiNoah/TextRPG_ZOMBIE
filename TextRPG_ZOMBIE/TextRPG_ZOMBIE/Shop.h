#pragma once
#ifndef SHOP_H
#define SHOP_H
#include "Character.h"

class Shop {

public:
	Shop();
	~Shop();

	//void displayMenu();
	void displayItems(Character& character);
	void buyItem(Character& character);
	void sellItem(Character& character);

};
#endif
