#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Item.h"
using namespace std;

Character::Character()
    : Actor(), Job("무직"), Level(1), Exp(0), MaxExp(100), Condition("건강"), Money(0), boostedTurns(0)
{
}

Character::Character(string inputName, string inputJob, int inputAttackPower, int inputMaxHP)
    : Actor(inputName, inputAttackPower, inputMaxHP), Job(inputJob), Level(1), Exp(0), MaxExp(100), Condition("건강"), Money(0), boostedTurns(0)
{
}

// Add item
void Character::addItem(const string& itemName, int amount)
{
    if (Inventory.find(itemName) != Inventory.end())
    {
        Inventory[itemName] += amount;
    }
    else
    {
        Inventory[itemName] = amount;
    }
    cout << "아이템 추가 : " << itemName << "을(를) " << amount << "개 추가했습니다." << endl;
}

// Gain Exp
void Character::gainExp(int amount)
{
    Exp += amount;
    cout << "경험치 획득: " << amount << " (현재 EXP: " << Exp << "/" << MaxExp << ")" << endl;

    while (Exp >= MaxExp)
    {
        levelUp();
    }
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
    cout << "EXP: " << Exp << "/" << MaxExp << endl;
    cout << "돈 : " << Money << endl;
    cout << "보유 아이템: ";
    for (const auto& item : Inventory)
    {
        cout << item.first << "(" << item.second << ") ";
    }
    cout << endl;
}

// Level up
void Character::levelUp()
{
    Exp -= MaxExp;
    Level++;
    MaxExp += 50;
    cout << "축하합니다! Lv. " << Level << "로 레벨 업했습니다!" << endl;
}

// 피격 오버라이딩
void Character::onHit(int inputAttackPower) { 
    if (useShield(inputAttackPower)) // "일회용 방패" 사용 여부
    {
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
        cout << Name << "이(가) 감염되었습니다. (피격 시 최대 체력 5 퍼센트 피해를 더 받습니다.)" << endl;
    }
}

// 공격 오버라이딩
int Character::Attack()
{
    // 목검 효과 적용
    useWoodenSword(); // 목검 사용 조건 및 효과 처리를 위임

    if (boostedTurns > 0)
    {
        boostedTurns--; // 턴 소모
        cout << Name << "이(가) \"목검\" 효과로 공격력이 2배로 증가했습니다!" << endl;
        return AttackPower * 2;
    }

    return AttackPower;
}

// 일회용 방패 아이템 : 피해량이 남은 체력보다 크고 && 인벤토리에 "일회용 방패"가 있으면 피해 무효
bool Character::useShield(int inputAttackPower)
{
    if (HP <= inputAttackPower && Inventory.find("일회용 방패") != Inventory.end() && Inventory["일회용 방패"] > 0)
    {
        Inventory["일회용 방패"]--;
        if (Inventory["일회용 방패"] == 0)
        {
            Inventory.erase("일회용 방패");
        }
        cout << Name << "이(가) 일회용 방패를 사용하여 피해를 방어했습니다!" << endl;
        return true;
    }
    return false;
}

// 목검 아이템 : 3턴 동안 피해량 2배
void Character::useWoodenSword()
{
    // 목검 효과가 없고, 인벤토리에 목검이 있는 경우
    if (boostedTurns == 0)
    {
        auto it = Inventory.find("목검");
        if (it != Inventory.end() && it->second > 0)
        {
            boostedTurns = 3; // 3턴 동안 효과 유지
            it->second--;     // 목검 소모
            if (it->second == 0)
            {
                Inventory.erase(it); // 남은 개수가 0이면 제거
            }
            cout << Name << "이(가) 목검을 사용했습니다! 3턴 동안 공격력이 2배로 증가합니다." << endl;
        }
    }
}
