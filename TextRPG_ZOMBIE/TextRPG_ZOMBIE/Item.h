#include <string>
#include <vector>
#include <iostream>
#include "Actor.h"
#include "Character.h"

using namespace std;

enum ItemList // 모든 아이템 목록
{
	Morphine,
	Epinephrine,
	Methylamphetamine,
	Fentanyl,
	Revital,
	Max
};

class All_Item // 아이템 설정 및 사용효과
{
protected:
	string Name;
	ItemList ItemType;
	int Price;
	int CurrentStack;
	int MaxStack;
public:

	All_Item(ItemList type);

	virtual void use(Character* chara);
};

class Inventory
{
public:
	All_Item item[ItemList::Max];
};

class MonsterDropItem
{
public:
	void dropitem(Inventory* Inven);
};