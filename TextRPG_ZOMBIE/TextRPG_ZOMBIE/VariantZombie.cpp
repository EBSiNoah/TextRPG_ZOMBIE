﻿#include "VariantZombie.h"
#include "RandomUtil.h"

using namespace std;

VariantZombie::VariantZombie(const int playerLevel) : Actor("", 0, 0)
{
    Name = "변종된 좀비";
    MaxHP = RandomUtil::GetRandomInt(playerLevel * 20, playerLevel * 30);
    AttackPower = RandomUtil::GetRandomInt(playerLevel * 5, playerLevel * 10);
    HP = MaxHP;
}

string VariantZombie::GetName() const
{
    return Name;
}

int VariantZombie::GetMaxHP() const
{
    return MaxHP;
}

int VariantZombie::Attack()
{
    int missChance = 20;  // 공격 미스 확률
    int randomMiss = RandomUtil::GetRandomInt(1, 100);

    if (randomMiss <= missChance)
    {
        cout << Name << "의 손톱이 옷자락만 살짝 스쳤습니다!" << endl;
        return 0;
    }

    return AttackPower;

    return AttackPower;
}

void VariantZombie::onHit(int inputAttackPower)
{
    Actor::onHit(inputAttackPower);

    cout << Name << "은(는) " << inputAttackPower << "의 상처를 입고 고통스러운 신음소리를 내며 비틀거립니다.. (" << HP << "/" << MaxHP << ")" << endl;

    if (isDead())
        cout << Name << "은(는) " << "당신의 공격으로 바닥에 쓰러진 후 더 이상 움직이지 않습니다." << endl;
}

void VariantZombie::printStatus() const
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}
