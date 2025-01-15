#include "NormalZombie.h"
#include "RandomUtil.h"

using namespace std;

NormalZombie::NormalZombie(const int playerLevel) : Actor("", 0, 0)
{
    Name = "NormalZombie";
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

int NormalZombie::Attack() const
{
    return AttackPower;
}

void NormalZombie::onHit(int inputAttackPower)
{
    Actor::onHit(inputAttackPower);

    cout << Name << "는 " << inputAttackPower << "의 데미지를 입었다..!" << "(" << HP << "/" << MaxHP << ")" << endl;

    if (isDead())
        cout << Name << "는 마지막 일격으로 사망했습니다 !!!" << endl;
}

void NormalZombie::printStatus() const
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}
