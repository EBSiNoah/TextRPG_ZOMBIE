#pragma once
#ifndef SHOP_H
#define SHOP_H
#include "Character.h"
#include "Item.h"


class Shop {
private:
	std::vector<ItemSetting> itemList;

public:
	Shop();
	~Shop();

	//void displayMenu();
	void displayItems(Character& character);
	void buyItem(Character& character);
	void sellItem(Character& character);

};
#endif
