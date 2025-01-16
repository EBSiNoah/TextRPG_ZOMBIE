#include "BossZombie.h"
#include "RandomUtil.h"
#include "GameModeBase/EndingScene.h"

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

int BossZombie::Attack()
{
	return AttackPower;
}

void BossZombie::onHit(int inputAttackPower)
{
	int dodgeChance = 15;
	int dodgeRoll = RandomUtil::GetRandomInt(1, 100);

	if (dodgeRoll <= dodgeChance)
	{
		cout << Name << "이(가) 눈에 보이지 않는 속도로 회피했습니다!" << endl;
		return;
	}

	Actor::onHit(inputAttackPower);

	cout << "날카로운 무기가 " << Name << "의 피부를 찢습니다. " << Name << "은(는) " << inputAttackPower << "의 피해를 받았습니다. (" << HP << "/" << MaxHP << ")" << endl;

	recoverHP();

	if (isDead())
	{
		cout << Name << "의 마지막 숨소리가 멈췄습니다. 당신의 심장은 아직도 고동치며, 살아있음을 외치고 있습니다." << endl;
		Sleep(3000);
		system("cls");
		cout << "이제 세상은 당신의 용기로 인해 새로운 날을 맞이합니다." << endl;
		Sleep(1000);
		cout << "\n";
		Sleep(1000);
		cout << "당신의 여정은 끝났지만," << endl;
		Sleep(1000);
		cout << "\n"; Sleep(1000);
		cout << "당신의 이야기는 영원히 남을 것입니다." << endl;
		Sleep(1000);
		cout << "\n";
		Sleep(2000);
		EndingScene endingScene;
		endingScene.showEnding();
		exit(0);
	}
}

void BossZombie::recoverHP()
{
	int recoveryChance = 20;
	int recoveryRoll = RandomUtil::GetRandomInt(1, 100);

	if (recoveryRoll <= recoveryChance) { // 20% 확률로 회복
		int recoveryAmount = RandomUtil::GetRandomInt(MaxHP * 0.1, MaxHP * 0.2); // 최대 체력의 10~20% 회복
		if (HP + recoveryAmount > MaxHP) {
			recoveryAmount = MaxHP - HP; // 최대 체력을 초과하지 않도록 제한
		}
		HP += recoveryAmount;
		cout << Name << "이(가) 주변 시체를 게걸스럽게 먹어치우며, 체력을 회복합니다! +" << recoveryAmount << " (" << HP << "/" << MaxHP << ")" << endl;
	}
}

void BossZombie::printStatus() const
{
	cout << "Name : " << Name << endl;
	cout << "Attack power : " << AttackPower << endl;
	cout << "Current health point : " << HP << endl;
}
