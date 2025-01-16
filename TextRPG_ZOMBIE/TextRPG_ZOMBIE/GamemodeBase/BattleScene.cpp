#include "BattleScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include "../MonsterDropItem.h"


using namespace std;

void BattleScene::startBattle(Character& player, unique_ptr<Actor>& zombie) {
    MonsterDropItem dropSystem;
    Sleep(1000);
    cout << "===== ������ ���۵˴ϴ�! =====" << endl;
    vector<string> battleMentBox = { "�η����� �������������� �ο�����..!", "������", "�ٸ��� �ĵ�Ÿ����� �ο�����..!", "�ٷ����� ���ʴ��� �� �������� �ο�����..." };
    int randomValue = RandomUtil::GetRandomInt(0, battleMentBox.size() - 1);
    Sleep(1000);
    cout << "**********  " << zombie->Name << "��(��) �����ƴ�! " << battleMentBox[randomValue] << "  **********" << endl;
    Sleep(1300);
    while (true) {
        cout << "\n==============================" << endl;
        cout << "1. ����\n2. ������ ���\n> ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            Sleep(1000);
            cout << endl;
            cout << player.Name << "��(��) " << zombie->Name << "��(��) �����մϴ�!" << endl;
            zombie->onHit(player.Attack());
            cout << endl;
        }
        else if (choice == "2") {
            cout << "\n===== ���� ������ =====" << endl;

            vector<pair<const int, const int>> inventory = player.getInventory();
            for (const auto& item : inventory) {
                if (item.second > 0) {
                    ItemSetting tempItem(static_cast<ItemType>(item.first));
                    cout << "[" << item.first << "] " << tempItem.getName()
                        << " - ���� ����: " << item.second << "��" << endl;
                }
            }
            cout << "=======================" << endl;
            cout << "\n����� �������� ��ȣ�� �Է��ϼ��� (���: -1): ";
            int itemIndex;
            cin >> itemIndex;

            if (itemIndex == -1) {
                cout << "������ ����� ����մϴ�." << endl;
            }
            else {
                vector<pair<const int, const int>> inventory = player.getInventory();
                auto it = find_if(inventory.begin(), inventory.end(),
                    [itemIndex](const pair<const int, const int>& item) {
                        return item.first == itemIndex;
                    });

                if (it != inventory.end() && it->second > 0) {
                    ItemSetting item(static_cast<ItemType>(itemIndex));
                    item.use(&player);
                    cout << player.Name << "��(��) �������� ����߽��ϴ�: "
                        << item.getName() << endl;
                }
                else {
                    cout << "�ش� �������� ���ų� ������ �����մϴ�!" << endl;
                }
            }

            Sleep(1000);
            cout << endl;
            cout << player.Name << "��(��) " << zombie->Name << "��(��) �����մϴ�!" << endl;
            zombie->onHit(player.Attack());
            cout << endl;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
            continue;
        }

        // ���� ü�� Ȯ��
        if (zombie->HP <= 0) {
            cout << zombie->Name << "��(��) ���������ϴ�!" << endl;
            dropSystem.dropItem(&player);
            break;
        }

        // ������ �ݰ�
        Sleep(1000);
        cout << "\n" << zombie->Name << "��(��) " << player.Name << "��(��) �����մϴ�!" << endl;
        player.onHit(zombie->Attack());
        cout << endl;

        // �÷��̾� ü�� Ȯ��
        if (player.HP <= 0) {
            cout << player.Name << "��(��) ���������ϴ�! ���� ����!" << endl;
            break;
        }
    }
}
