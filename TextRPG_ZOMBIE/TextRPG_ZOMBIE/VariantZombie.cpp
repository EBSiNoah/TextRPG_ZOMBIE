#include "VariantZombie.h"
#include "RandomUtil.h"

using namespace std;

VariantZombie::VariantZombie(const int playerLevel) : Actor("", 0, 0)
{
    Name = "���� ����";
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

int VariantZombie::Attack() const
{
    return AttackPower;
}

void VariantZombie::onHit(int inputAttackPower)
{
    Actor::onHit(inputAttackPower);

    cout << Name << "�� " << inputAttackPower << "�� ��ó�� �԰� ���뽺���� �����Ҹ��� ���� ��Ʋ�Ÿ��ϴ�.." << endl;

    if (isDead())
        cout << Name << "�� " << "����� �������� ���� �ٴڿ� �������� �� �̻� �������� �ʽ��ϴ�." << endl;
}

void VariantZombie::printStatus() const
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}
