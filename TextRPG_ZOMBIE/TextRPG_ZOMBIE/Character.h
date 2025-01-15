#pragma once
#include "Actor.h"
#include <vector>
#include <map>

class Character : public Actor {
private:
    string Job;
    int Exp;
    int MaxExp;
    int Level;
    int Money;
    string Condition;
    int boostedTurns;
    map<string, int> Inventory;
    map<int, int> Inventory2;

public:
    // 기본 생성자
    Character();

    // 사용자 정의 생성자
    Character(string inputName, string inputJob, int inputAttackPower, int inputMaxHP);

    // 아이템 추가
    void addItem(const string& itemName, int amount);

    // 경험치 획득
    void gainExp(int amount);

    // Get money
    int getMoney() const;

    // Set Money
    void setMoney(int amount);

    // 돈 획득
    void gainMoney(int amount);

    // 돈 소모
    bool payMoney(int price);

    // Get HP
    int getHP() const;

    // Set HP
    void setHP(const int amount);

    // Get MaxHP
    int getMaxHP() const;

    // Set MaxHP
    void setMaxHP(const int amount);

    // Get Attack
    int getAttackPower() const;

    // Set Attack
    void setAttackPower(const int amount);

    // Get Condition
    string getCondition() const;

    // Set Condition
    void setCondition(const string status);

    // 상태 출력
    void printStatus();

    // 피격 오버라이딩
    void onHit(int inputAttackPower) override;

    // 공격 오버라이딩
    int Attack() override;

    // Get level
    int getLevel() const;

    // 아이템
    bool useShield(int inputAttackPower); // 일회용 방패 아이템
    void useWoodenSword(); // 목검 아이템
private:
    // 레벨업 처리
    void levelUp();

    // 감염
    void Infect();
};
