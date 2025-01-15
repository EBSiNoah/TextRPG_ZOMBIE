#include "BossZombie.h"
#include "RandomUtil.h"

using namespace std;

BossZombie::BossZombie(const int playerLevel) : Actor("", 0, 0)
{
	Name = "������� ��";
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

	cout << "��ī�ο� ���Ⱑ " << Name << "�� �Ǻθ� �����ϴ�." << Name << "�� " << inputAttackPower << "�� ���ظ� �޾ҽ��ϴ�." << endl;

	if (isDead())
	{
		cout << Name << "�� ������ ���Ҹ��� ������ϴ�.����� ������ ������ ��ġ��, ��������� ��ġ�� �ֽ��ϴ�." << endl;
		cout << "���� ������ ����� ���� ���� ���ο� ���� �����մϴ�.����� ������ ��������, ����� �̾߱�� ������ ���� ���Դϴ�." << endl;
	}
		
}

void BossZombie::printStatus() const
{
	cout << "Name : " << Name << endl;
	cout << "Attack power : " << AttackPower << endl;
	cout << "Current health point : " << HP << endl;
}
