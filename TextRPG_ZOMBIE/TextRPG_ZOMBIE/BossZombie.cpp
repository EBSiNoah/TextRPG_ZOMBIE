#include "BossZombie.h"
#include "RandomUtil.h"

using namespace std;

BossZombie::BossZombie(const int playerLevel) : Actor("", 0, 0)
{
	Name = "좀비들의 왕";
	MaxHP = RandomUtil::GetRandomInt(playerLevel * 20 * 1.5, playerLevel * 30 * 1.5);
	AttackPower = RandomUtil::GetRandomInt(playerLevel * 5 * 1.5, playerLevel * 10 * 1.5);
	HP = MaxHP;
}

string BossZombie::GetName() const
{
	return Name;
}

int BossZombie::GetMaxHP() const
{
	return MaxHP;
}

int BossZombie::Attack() const
{
	return AttackPower;
}

void BossZombie::onHit(int inputAttackPower)
{
	Actor::onHit(inputAttackPower);

	cout << "날카로운 무기가 " << Name << "의 피부를 찢습니다." << Name << "은 " << inputAttackPower << "의 피해를 받았습니다." << endl;

	if (isDead())
	{
		cout << Name << "의 마지막 숨소리가 멈췄습니다.당신의 심장은 아직도 고동치며, 살아있음을 외치고 있습니다." << endl;
		cout << "이제 세상은 당신의 용기로 인해 새로운 날을 맞이합니다.당신의 여정은 끝났지만, 당신의 이야기는 영원히 남을 것입니다." << endl;
	}
		
}

void BossZombie::printStatus() const
{
	cout << "Name : " << Name << endl;
	cout << "Attack power : " << AttackPower << endl;
	cout << "Current health point : " << HP << endl;
}
