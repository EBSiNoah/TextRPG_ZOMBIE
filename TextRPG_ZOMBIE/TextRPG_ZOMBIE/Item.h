#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Actor.h"

using namespace std;

class Character; // ĳ���� ���� ����

enum ItemType // ��� ������ ���
{
	Morphine,
	Epinephrine,
	Methylamphetamine,
	Fentanyl,
	Revital,
	WoodenSword,
	Shield,
	Vaccine,
	Max
};

class ItemSetting // ������ ���� �� ���ȿ��
{
protected:
	string Name;
	ItemType itemtype;
	int Price;

public:
	ItemSetting(ItemType type);

	virtual void use(Character* chara);

	// ������ getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }


	// ������ setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }

};