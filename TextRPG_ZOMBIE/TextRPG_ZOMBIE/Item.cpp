#include "Item.h"
#include "Character.h"

// ������ ���� (�ʱ�ȭ ���� �ְų�, �⺻�� ����)
<<<<<<< Updated upstream
Items::Items(ItemType type)
    : Name(""), itemtype(type), Price(0), CurrentStack(0), MaxStack(0)
=======
ItemSetting::ItemSetting(ItemType type)
    : Name(""), itemtype(type), Price(0)
>>>>>>> Stashed changes
{
    switch (itemtype)
    {
    case Morphine:
        Name = "����";
        Price = 50;
        break;

    case Epinephrine:
        Name = "���ǳ�����";
        Price = 60;
        break;

    case Methylamphetamine:
        Name = "�޽�����Ÿ��";
        Price = 70;
        break;

    case Fentanyl:
        Name = "��Ÿ��";
        Price = 80;
        break;

    case Revital:
        Name = "����Ż";
        Price = 100;
        break;

    case WoodenSword:
        Name = "���";
        Price = 75;
        break;

    case Shield:
        Name = "��ȸ�� ����";
        Price = 70;
        break;

    case Vaccine:
        Name = "���̷��� ���";
        Price = 50;
        break;
    }
}

<<<<<<< Updated upstream
void Items::use(Character* chara)
{
    if (CurrentStack < 1)
        return;
    // ������ ��� �� ����
    --CurrentStack;
=======
void ItemSetting::use(Character* chara)
{
    //CurrentStack�� ĳ���� �κ��丮�� ���������� ����
    //if (CurrentStack < 1)
    //    return;
    //// ������ ��� �� ����
    //--CurrentStack;
>>>>>>> Stashed changes

    switch (itemtype)
    {
    case Morphine:
        cout << "ü�� 50 ȸ��!";
        chara->HP += 50;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Epinephrine:
        cout << "���ݷ� 10 ����!";
        chara->AttackPower += 10;
        break;

    case Methylamphetamine:
        cout << "���ݷ� 50 ����!";
        chara->AttackPower += 50;
        break;

        // ü�� 30 �����϶� ��Ÿ�� ���� ����ó��
    case Fentanyl:
        cout << "�ִ� ü�� 30 ����, ü�� 5000 ȸ��!";
        chara->MaxHP -= 30;
        chara->HP += 5000;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Revital:
        cout << "�ִ� ü�� 80 ����!";
        chara->MaxHP += 80;
        chara->HP += 80;
        break;
<<<<<<< Updated upstream
=======

    case WoodenSword:
        if (chara->boostedTurns == 0)
        {
            auto it = chara->Inventory2.find("���");
            if (it != chara->Inventory2.end() && it->second > 0)
            {
                chara->boostedTurns = 3; // 3�� ���� ȿ�� ����
                it->second--;     // ��� �Ҹ�
                if (it->second == 0)
                {
                    chara->Inventory2.erase(it); // ���� ������ 0�̸� ����
                }
                cout << Name << "��(��) ����� ����߽��ϴ�! 3�� ���� ���ݷ��� 2��� �����մϴ�." << endl;
            }
        }
        break;

    case Shield:

        break;

    case Vaccine:
        if (chara->getCondition() == "�ǰ�") {
            cout << "���� ���°� �ƴմϴ�." << endl;
        }
        else if (chara->getCondition() == "����") {
            chara->setCondition("�ǰ�");
            cout << "���� ���°� ȸ���Ǿ����ϴ�!" << endl;
        }
        break;
>>>>>>> Stashed changes
    }
}