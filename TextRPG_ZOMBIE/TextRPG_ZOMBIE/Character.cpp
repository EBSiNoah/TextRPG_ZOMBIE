#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Item.h"
using namespace std;

Character::Character()
    : Actor(), Job("무직"), Level(1), Exp(0), MaxExp(100), Condition("건강"), Money(0), boostedTurns(0)
{
    initializeInventory();
}

Character::Character(string inputName, string inputJob, int inputAttackPower, int inputMaxHP)
    : Actor(inputName, inputAttackPower, inputMaxHP), Job(inputJob), Level(1), Exp(0), MaxExp(100), Condition("건강"), Money(0), boostedTurns(0)
{
    initializeInventory();
}

// Add item
//void Character::addItem(const string& itemName, int amount)
void Character::addItem(const int itemIndex, const int amount)
{
    /*if (Inventory.find(itemName) != Inventory.end())
    {
        Inventory[itemName] += amount;
    }
    else
    {
        Inventory[itemName] = amount;
    }
    cout << "아이템 추가 : " << itemName << "을(를) " << amount << "개 추가했습니다." << endl;*/
    if (Inventory.find(itemIndex) != Inventory.end())
    {
        Inventory[itemIndex] += amount;
    }
    else
    {
        Inventory[itemIndex] = amount;
    }

    ItemSetting tempItem(static_cast<ItemType>(itemIndex));
    string itemName = tempItem.getName();

    cout << Name << "이(가) " << itemName << "을(를) " << amount << "개 획득했습니다." << endl;
}

// Delete Item
void Character::deleteItem(const int itemIndex, const int amount)
{
    if (Inventory.find(itemIndex) != Inventory.end())
    {
        if (Inventory[itemIndex] > amount)
        {
            Inventory[itemIndex] -= amount;
        }
        else
        {
            // 남은 수량이 제거할 수량보다 적으면 아이템 삭제
            //Inventory.erase(itemIndex);
           /* cout << "아이템이 모두 제거했습니다: "
                << ItemSetting(static_cast<ItemType>(itemIndex)).getName() << endl;*/
            return;
        }

        // 아이템 이름 가져오기
        ItemSetting tempItem(static_cast<ItemType>(itemIndex));
        string itemName = tempItem.getName();

        cout << "아이템 차감: " << itemName << "을(를) " << amount
            << "개 제거했습니다. 남은 수량: " << Inventory[itemIndex] << endl;
    }
    else
    {
        cout << "제거하려는 아이템이 없습니다." << endl;
    }
}

// Gain Exp
void Character::gainExp(int amount)
{
    Exp += amount;

    while (Exp >= MaxExp)
    {
        levelUp();
    }

    cout << "경험치 획득: " << amount << " (현재 EXP: " << Exp << "/" << MaxExp << ")" << endl;
}
// Get HP
int Character::getHP() const
{
    return HP;
}

// Set HP
void Character::setHP(const int amount)
{
    HP = amount;
}

// Get BoostedTurns
int Character::getBoostedTurns() const
{
    return boostedTurns;
}

// Set BoostedTurns
void Character::setBoostedTurns(const int amount)
{
    boostedTurns = amount;
}

// Get MaxHP
int Character::getMaxHP() const
{
    return MaxHP;
}

// Set MaxHP
void Character::setMaxHP(const int amount)
{
    if (amount < getHP())
    {
        HP = amount;
    }
    MaxHP = amount;
}

// Get Condition
string Character::getCondition() const
{
    return Condition;
}

// Set Condition
void Character::setCondition(const string status)
{
    Condition = status;
}


// Get Attack
int Character::getAttackPower() const
{
    return AttackPower;
}

// Set Attack
void Character::setAttackPower(const int amount)
{
    AttackPower = amount;
}

// Get Level
int Character::getLevel() const
{
    return Level;
}

// Get Money
int Character::getMoney() const
{
    return Money;
}

// Set Money
void Character::setMoney(int amount) {
    Money = amount;
}

// Gain money
void Character::gainMoney(int amount)
{
    setMoney(Money + amount);
    cout << "돈 획득: " << amount << " (보유 돈 : " << Money << ")" << endl;
}

// Pay money
bool Character::payMoney(int price)
{
    if (price > Money)
    {
        cout << "보유 골드가 부족합니다!";
        return false;
    }
    else
    {
        setMoney(Money - price);
        cout << price << "원을 지불 했습니다. 잔액 (" << Money << ")";
        return true;
    }
}

// PrintStatus
void Character::printStatus()
{
    cout << "\nLv." << Level << " " << Name << "(" << Job << ")" << endl;
    cout << "HP : " << HP << "/" << MaxHP << "(" << Condition << ")" << endl;
    cout << "AttackPower : " << AttackPower << endl;
    cout << "EXP: " << Exp << "/" << MaxExp << endl;
    cout << "돈 : " << Money << endl;
    printInventory();
    cout << endl;
}

// Level up
void Character::levelUp()
{
    Exp -= MaxExp;
    Level++;
    MaxExp += 50;
    setAttackPower(getAttackPower() + 10);
    setMaxHP(getMaxHP() + 50);
    setHP(getMaxHP());
    cout << "축하합니다! Lv. " << Level << "로 레벨 업했습니다! ( +5 공격력, +100 체력, 체력 회복! )" << endl;
}

// 피격 오버라이딩
void Character::onHit(int inputAttackPower) {
    if (ItemSetting::ShieldCheck(this, inputAttackPower)) // "일회용 방패" 사용 여부
    {
        //cout << "끝까지 버텨야 해!" << endl;
        Sleep(1000);
        cout << Name << "이(가) 일회용 방패를 사용했습니다!" << endl;
        return;
    }

    Actor::onHit(inputAttackPower);

    if (Condition == "건강") {
        cout << Name << "이(가) " << inputAttackPower << " 피해를 입었습니다. (" << HP << "/" << MaxHP << ")" << endl;
        Infect(); // 감염 처리
    }
    else
    {
        int dot = MaxHP * 0.05;
        cout << Name << "이(가) " << inputAttackPower << " 피해를 입었습니다. (" << HP << "/" << MaxHP << ")" << endl;
        Actor::onHit(dot);
        cout << Name << "이(가) 감염되어 " << dot << " 데미지를 추가적으로 받았습니다. (" << HP << " / " << MaxHP << ")" << endl;
    }

    if (isDead())
    {
        cout << Name << "이(가) 피해를 버티지 못하고 쓰러져 버렸습니다. 게임을 종료합니다.";
        exit(0);
    }
}

// 상태이상
void Character::Infect()
{
    int chance = rand() % 100;
    if (chance < 10) // 10% 확률로 감염
    {
        Condition = "감염";
        cout << Name << "이(가) 바이러스를 버티지 못하고 감염되었습니다, (피격 시 최대 체력 5 퍼센트 피해를 더 받습니다.)" << endl;
    }
}

// 공격 오버라이딩
int Character::Attack()
{
    // 목검 효과 적용
    //useWoodenSword(); // 목검 사용 조건 및 효과 처리를 위임

    if (boostedTurns > 0)
    {
        boostedTurns--; // 턴 소모
        //cout << "이게 마지막 희망이다!" << endl;
        cout << Name << "이(가) \"목검\" 효과로 공격력이 2배로 증가했습니다!" << endl;
        Sleep(1000);
        return AttackPower * 2;
    }

    return AttackPower;
}

// Inventory 초기화
void Character::initializeInventory()
{
    for (int i = 0; i < ItemType::Max; ++i)
    {
        Inventory[i] = 0;
    }
}

// Inventory 출력
void Character::printInventory()
{
    cout << "보유 아이템 : ";
    for (const auto& item : Inventory)
    {
        if (item.second > 0)
        {
            // ItemSetting 객체를 생성하여 이름 가져오기
            ItemSetting tempItem(static_cast<ItemType>(item.first));
            string itemName = tempItem.getName();
            cout << itemName << "(" << item.second << "), ";
        }
        else
        {
            continue;
        }
    }
}

// Get Inventory
vector<pair<const int, const int>> Character::getInventory() const
{
    vector<pair<const int, const int>> allItems;

    for (const auto& item : Inventory)
    {
        allItems.emplace_back(item.first, item.second);
    }

    return allItems;
}

// Set Inventory
void Character::setInventory(const int itemIndex, const int amount)
{
    Inventory[itemIndex] = amount;
}
