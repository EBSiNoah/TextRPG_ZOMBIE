#include "Item.h"

// ������ ���� (�ʱ�ȭ ���� �ְų�, �⺻�� ����)
Items::Items(ItemType type)
    : Name(""), itemtype(type), Price(0), CurrentStack(0), MaxStack(0)
{
    switch (itemtype)
    {
    case Morphine:
        Name = "����";
        Price = 50;
        MaxStack = 5;
        break;

    case Epinephrine:
        Name = "���ǳ�����";
        Price = 60;
        MaxStack = 1;
        break;

    case Methylamphetamine:
        Name = "�޽�����Ÿ��";
        Price = 70;
        MaxStack = 1;
        break;

    case Fentanyl:
        Name = "��Ÿ��";
        Price = 80;
        MaxStack = 2;
        break;

    case Revital:
        Name = "����Ż";
        Price = 100;
        MaxStack = 1;
        break;
    }
}

void Items::use(Character* chara)
{
    if (CurrentStack < 1)
        return;
    // ������ ��� �� ����
    --CurrentStack;

    switch (itemtype)
    {
    case Morphine:
        cout << "���: ����, ü�� 50 ȸ��.";
        chara->HP += 50;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Epinephrine:
        cout << "���: ���ǳ�����, ���ݷ� 10 ����.";
        chara->AttackPower += 10;
        break;

    case Methylamphetamine:
        cout << "���: �޽�����Ÿ��, ���ݷ� 50 ����.";
        chara->AttackPower += 50;
        break;

        // ü�� 30 �����϶� ��Ÿ�� ���� ����ó��
    case Fentanyl:
        cout << "���: ��Ÿ��, �ִ� ü�� 30 ����, ü�� 5000 ȸ��";
        chara->MaxHP -= 30;
        chara->HP += 5000;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Revital:
        cout << "���: ����Ż, �ִ� ü�� 80 ����";
        chara->MaxHP += 80;
        chara->HP += 80;
        break;
    }
}