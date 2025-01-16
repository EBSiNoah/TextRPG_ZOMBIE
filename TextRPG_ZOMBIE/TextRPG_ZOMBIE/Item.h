#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Actor.h"

using namespace std;

class Character; // 캐릭터 전방 선언

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
	string Explain;
	bool UseType;

public:
	ItemSetting(ItemType type);

	virtual void use(Character* chara);

	// onHit가 호출될 때 방패 사용 여부를 확인하는 정적 함수 추가
	static bool ShieldCheck(Character* chara, int inputAttackPower);

	// 상점용 getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }
	bool getUseType() const { return UseType; }
	string getExplain() const { return Explain; }


	// 상점용 setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }

};