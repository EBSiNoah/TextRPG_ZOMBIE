#include "MonsterDropItem.h"

void MonsterDropItem::dropItem(Character* chara)
{
    int droptable = RandomUtil::GetRandomInt(0, 100);
    int dropcheck = RandomUtil::GetRandomInt(0, 100);

    // �ʼ� ��������: 30% Ȯ���� ������ ���
    // 30% Ȯ���� droptable���� ����ǰ ȹ�� ���� ����
    // ���� �� ������ ��� Ȯ��
    // ���� : 25%
    // ���ǳ����� : 25%
    // ��� : 20%
    // �޽�����Ÿ�� : 10%
    // ��Ÿ�� : 10%
    // ����Ż : 10%
    chara->setKillCount(chara->getKillCount() + 1);
    chara->gainExp(chara->getLevel() * 80 * 1.5);
    Sleep(1000);
    chara->gainMoney(chara->getLevel() * 80 * 1.5);
    if (droptable <= 30)
    {
        if (dropcheck <= 25)
        {
            // ���� ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Morphine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Morphine), count + 1);
            cout << "����ǰ���� '����'�� ������ϴ�!" << endl;
        }
        else if (dropcheck <= 50)
        {
            // ���ǳ����� ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Epinephrine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Epinephrine), count + 1);
            cout << "����ǰ���� '���ǳ�����'�� ������ϴ�!" << endl;
            {
                ItemSetting DropUse(Epinephrine);
                if (DropUse.getUseType() == 0)
                {
                    DropUse.use(chara);
                }
            }
        }
        else if (dropcheck <= 70)
        {
            // ��� ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Vaccine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Vaccine), count + 1);
            cout << "����ǰ���� '���'�� ������ϴ�!" << endl;
        }
        else if (dropcheck <= 80)
        {
            // �޽�����Ÿ�� ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Methylamphetamine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Methylamphetamine), count + 1);
            cout << "����ǰ���� '�޽�����Ÿ��'�� ������ϴ�!" << endl;
            {
                ItemSetting DropUse(Methylamphetamine);
                if (DropUse.getUseType() == 0)
                {
                    DropUse.use(chara);
                }
            }
        }
        else if (dropcheck <= 90)
        {
            // ��Ÿ�� ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Fentanyl)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Fentanyl), count + 1);
            cout << "����ǰ���� '��Ÿ��'�� ������ϴ�!" << endl;
        }
        else if (dropcheck <= 100)
        {
            // ����Ż ���
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Revital)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Revital), count + 1);
            cout << "����ǰ���� '����Ż'�� ������ϴ�!" << endl;
            {
                ItemSetting DropUse(Revital);
                if (DropUse.getUseType() == 0)
                {
                    DropUse.use(chara);
                }
            }
        }
    }
    Sleep(2000);
    system("cls");
}