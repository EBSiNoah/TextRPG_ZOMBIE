#include "BossZombie.h"
#include "RandomUtil.h"

using namespace std;

BossZombie::BossZombie(const int playerLevel) : Actor("", 0, 0)
{
	Name = "BossZombie";
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

	cout << Name << "는 " << inputAttackPower << "의 데미지를 입었다..!" << "(" << HP << "/" << MaxHP << ")" << endl;

	if (isDead())
		cout << "축하합니다! 보스를 클리어하고 게임의 엔딩을 보셨습니다!" << endl;
}

void BossZombie::printStatus() const
{
	cout << "Name : " << Name << endl;
	cout << "Attack power : " << AttackPower << endl;
	cout << "Current health point : " << HP << endl;
}
