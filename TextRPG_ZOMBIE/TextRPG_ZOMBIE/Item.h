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
	string Explain;
	bool UseType;

public:
	ItemSetting(ItemType type);

	virtual void use(Character* chara);

	// onHit�� ȣ��� �� ���� ��� ���θ� Ȯ���ϴ� ���� �Լ� �߰�
	static bool ShieldCheck(Character* chara, int inputAttackPower);

	// ������ getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }
	bool getUseType() const { return UseType; }
	string getExplain() const { return Explain; }


	// ������ setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }

};