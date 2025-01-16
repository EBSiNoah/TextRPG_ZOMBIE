#include "Item.h"
#include "Character.h"

// ������ ���� (�ʱ�ȭ ���� �ְų�, �⺻�� ����)
ItemSetting::ItemSetting(ItemType type)
    : Name(""), itemtype(type), Price(0), Explain(""), UseType(0)
{
    switch (itemtype)
    {
    case Morphine:
        Name = "����";
        Price = 50;
        Explain = "���ɿ� ���� ���� �Դϴ�";
        UseType = 1;
        break;

    case Epinephrine:
        Name = "���ǳ�����";
        Price = 60;
        Explain = "���ǳ������� ���� ���� �Դϴ�";
        UseType = 0;
        break;

    case Methylamphetamine:
        Name = "�޽�����Ÿ��";
        Price = 70;
        Explain = "�޽�����Ÿ�ο� ���� ���� �Դϴ�";
        UseType = 0;
        break;

    case Fentanyl:
        Name = "��Ÿ��";
        Price = 80;
        Explain = "��Ÿ�ҿ� ���� ���� �Դϴ�";
        UseType = 1;
        break;

    case Revital:
        Name = "����Ż";
        Price = 100;
        Explain = "����Ż�� ���� ���� �Դϴ�";
        UseType = 0;
        break;

    case WoodenSword:
        Name = "���";
        Price = 75;
        Explain = "��˿� ���� ���� �Դϴ�";
        UseType = 1;
        break;

    case Shield:
        Name = "��ȸ�� ����";
        Price = 70;
        Explain = "��ȸ�� ���п� ���� ���� �Դϴ�";
        UseType = 0;
        break;

    case Vaccine:
        Name = "���̷��� ���";
        Price = 50;
        Explain = "���̷��� ��ſ� ���� ���� �Դϴ�";
        UseType = 1;
        break;
    }
}

void ItemSetting::use(Character* chara)
{
    int key = static_cast<int>(itemtype);

    // ĳ���� �κ��丮
    vector<pair<const int, const int>> inv = chara->getInventory();

    // �������� ���� ���� ���� üũ
    int count = 0;
    bool found = false;
    for (const auto& p : inv)
    {
        if (p.first == key)
        {
            count = p.second;
            found = true;
            break;
        }
    }

    // �������� ���ų� ������ 0�ϰ�� ����
    if (!found || count < 1)
        return;

    // ������ ���� ���� -1
    chara->setInventory(key, count - 1);

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

    case Fentanyl:
        if (chara->MaxHP < 31)
        {
            // �ִ� ü���� 30���϶�� �ִ� ü���� 1�� ����ϴ�.
            chara->MaxHP = 1;
            cout << "�๰ �������� �ִ� ü���� 1�� �Ǿ����ϴ�." << endl;
            chara->HP += 5000;
            if (chara->HP > chara->MaxHP)
                chara->HP = chara->MaxHP;
        }
        else
        {
            cout << "�ִ� ü�� 30 ����, ü�� 5000 ȸ��!" << endl;
            chara->MaxHP -= 30;
            chara->HP += 5000;
            if (chara->HP > chara->MaxHP)
                chara->HP = chara->MaxHP;
        }
        break;

    case Revital:
        cout << "�ִ� ü�� 80 ����!";
        chara->MaxHP += 80;
        chara->HP += 80;
        break;

    case WoodenSword:
        if (chara->getBoostedTurns() == 0)
        {
            chara->setBoostedTurns(3);
            cout << "3�� ���� ���ݷ��� 2��� �����մϴ�!" << endl;
        }
        break;

    case Shield:

        break;

    case Vaccine:
        if (chara->getCondition() == "�ǰ�")
        {
            cout << "���� ���°� �ƴմϴ�." << endl;
        }
        else if (chara->getCondition() == "����")
        {
            chara->setCondition("�ǰ�");
            cout << "���� ���°� ȸ���Ǿ����ϴ�!" << endl;
        }
        break;
    }
}


bool ItemSetting::ShieldCheck(Character* chara, int inputAttackPower)
{
    // ĳ���� �κ��丮 ��������
    auto inventory = chara->getInventory();

    // ��ȸ�� ���и� ã�´�
    // (enum ���� Shield �̰�, inventory������ <itemIndex, amount> ����)
    // Shield�� enum ���� 6 �̹Ƿ� (ItemType::Shield)
    int shieldKey = static_cast<int>(ItemType::Shield);

    // ���а� 1�� �̻� �ִ��� Ȯ��
    for (auto& item : inventory)
    {
        if (item.first == shieldKey && item.second > 0)
        {
            // ���� ü�°� ���ݷ��� ��
            if (chara->getHP() <= inputAttackPower)
            {
                // ���� ��� => ���� -1
                chara->setInventory(shieldKey, item.second - 1);

                // ���� ��� �� ���� ��ȿȭ
                cout << chara->Name << "��(��) ��ȸ�� ���и� ����Ͽ� ���ظ� ����߽��ϴ�!" << endl;
                return true;
            }
            break;
        }
    }
    // ���и� ����� ��Ȳ�� �ƴϸ� false
    return false;
}