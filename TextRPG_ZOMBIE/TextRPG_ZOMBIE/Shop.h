#pragma once
#ifndef SHOP_H
#define SHOP_H

class Shop {
public:
	Shop();
	~Shop();

	void displayMenu();
	void displayItems(/*Character& character*/);
	void buyItem();
	void sellItem();


};
#endif