#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Actor.h"
#include "Character.h"

using namespace std;

enum ItemType // 모든 아이템 목록
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

class ItemSetting // 아이템 설정 및 사용효과
{
protected:
	string Name;
	ItemType itemtype;
	int Price;

public:
	ItemSetting(ItemType type);

	virtual void use(Character* chara);

	// 상점용 getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }


	// 상점용 setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }

};