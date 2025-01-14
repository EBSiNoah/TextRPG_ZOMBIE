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
	Max
};

class Items // 아이템 설정 및 사용효과
{
protected:
	string Name;
	ItemType itemtype;
	int Price;
	int CurrentStack;
	int MaxStack;
	// getter setter 필요 상점에서 써야됨
public: 

	Items(ItemType type);

	virtual void use(Character* chara);

	// 상점용 getter
	string getName() const { return Name; }
	ItemType getItemType() const { return itemtype; }
	int getPrice() const { return Price; }
	int getCurrentStack() const { return CurrentStack; }
	int getMaxStack() const { return MaxStack; }

	// 상점용 setter
	void setName(const string& newName) { Name = newName; }
	void setItemType(ItemType newType) { itemtype = newType; }
	void setPrice(int newPrice) { Price = newPrice; }
	void setCurrentStack(int newCurrentStack) { CurrentStack = newCurrentStack; }
	void setMaxStack(int newMaxStack) { MaxStack = newMaxStack; }
};

// 드랍테이블 컴파일때문에 해놓은 임시 인벤토리
// 캐릭터 단위에서 인벤토리가 생기면 지울것
class Inventory 
{
public:
	Items item[ItemType::Max];
};
