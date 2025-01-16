#include "NormalZombie.h"
#include "RandomUtil.h"

using namespace std;

NormalZombie::NormalZombie(const int playerLevel) : Actor("", 0, 0)
{
    Name = "조무래기 좀비";
    MaxHP = RandomUtil::GetRandomInt(playerLevel * 20, playerLevel * 30);;
    AttackPower = RandomUtil::GetRandomInt(playerLevel * 5, playerLevel * 10);
    HP = MaxHP;
}


string NormalZombie::GetName() const
{
    return Name;
}

int NormalZombie::GetMaxHP() const
{
    return MaxHP;
}

int NormalZombie::Attack()
{
    int missChance = 40;  // 공격 미스 확률
    int randomMiss = RandomUtil::GetRandomInt(1, 100);

    if (randomMiss <= missChance)
    {
        cout << Name << "이(가) 공중에서 허우적거립니다." << endl;
        return 0;
    }

    return AttackPower;
}

void NormalZombie::onHit(int inputAttackPower)
{
    Actor::onHit(inputAttackPower);

    cout << Name << "은(는) " << inputAttackPower << "의 상처를 입고 고통스러운 신음소리를 내며 비틀거립니다.. (" << HP << "/" << MaxHP << ")" << endl;

    if (isDead())
        cout << Name << "은(는) " << "당신의 공격으로 바닥에 쓰러진 후 더 이상 움직이지 않습니다." << endl;
}

void NormalZombie::printStatus() const
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}
