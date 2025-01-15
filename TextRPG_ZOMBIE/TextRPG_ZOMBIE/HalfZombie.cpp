#include "HalfZombie.h"
#include "RandomUtil.h"

using namespace std;

HalfZombie::HalfZombie(const int playerLevel) : Actor("", 0, 0)
{
    Name = "반좀비";
    MaxHP = RandomUtil::GetRandomInt(playerLevel * 20, playerLevel * 30);
    AttackPower = RandomUtil::GetRandomInt(playerLevel * 5, playerLevel * 10);
    HP = MaxHP;
}

string HalfZombie::GetName() const
{
    return Name;
}

int HalfZombie::GetMaxHP() const
{
    return MaxHP;
}

int HalfZombie::Attack() const
{
    return AttackPower;
}

void HalfZombie::onHit(int inputAttackPower)
{
    Actor::onHit(inputAttackPower);

    cout << Name << "는 " << inputAttackPower << "의 상처를 입고 고통스러운 신음소리를 내며 비틀거립니다.." << endl;

    if (isDead())
        cout << Name << "는 " << "당신의 공격으로 좀비가 바닥에 쓰러지고 더 이상 움직이지 않습니다." << endl;
}

void HalfZombie::printStatus() const
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}
