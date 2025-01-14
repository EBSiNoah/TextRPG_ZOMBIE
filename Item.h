#include <string>
#include <vector>
#include <iostream>
#include "Actor.h"
#include "Character.h"

using namespace std;

enum ItemType // ��� ������ ���
{
	Morphine,
	Epinephrine,
	Methylamphetamine,
	Fentanyl,
	Revital,
	Max
};

class Items // ������ ���� �� ���ȿ��
{
protected:
	string Name;
	ItemType itemtype;
	int Price;
	int CurrentStack;
	int MaxStack;
	// getter setter �ʿ� �������� ��ߵ�
public: 

	Items(ItemType type);

	virtual void use(Character* chara);

	// ������ getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }
	int getCurrentStack() const { return CurrentStack; }
	int getMaxStack() const { return MaxStack; }

	// ������ setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }
	void setCurrentStack(int newCurrentStack) { CurrentStack = newCurrentStack; }
	void setMaxStack(int newMaxStack) { MaxStack = newMaxStack; }
};

// ������̺� �����϶����� �س��� �ӽ� �κ��丮
// ĳ���� �������� �κ��丮�� ����� �����
class Inventory 
{
public:
	Items item[ItemType::Max];
};
