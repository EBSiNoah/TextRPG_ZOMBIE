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
    cout << "===== 전투가 시작됩니다! =====" << endl;
    vector<string> battleMentBox = { "두려워서 눈물범벅이지만 싸워보자..!", "살려줘요", "다리가 후들거리지만 싸워보자..!", "다래끼로 한쪽눈이 안 보이지만 싸워보자..." };
    int randomValue = RandomUtil::GetRandomInt(0, battleMentBox.size() - 1);
    Sleep(1000);
    cout << "**********  " << zombie->Name << "을(를) 마주쳤다! " << battleMentBox[randomValue] << "  **********" << endl;
    Sleep(1300);
    while (true) {
        cout << "\n==============================" << endl;
        cout << "1. 공격\n2. 아이템 사용\n3. 도망치기\n> ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            Sleep(1000);
            cout << endl;
            cout << player.Name << "이(가) " << zombie->Name << "을(를) 공격합니다!" << endl;
            int dodgeChance = RandomUtil::GetRandomInt(1, 100);
            if (dodgeChance <= 10) {
                Sleep(1000);
                cout << player.Name << "이(가) " << zombie->Name << "에게 겁을 먹고 허공을 휘둘렀다!" << endl;
            }
            else {
                zombie->onHit(player.Attack());
                cout << endl;
            }
        }
        else if (choice == "2") {
            cout << "\n===== 보유 아이템 =====" << endl;

            vector<pair<const int, const int>> inventory = player.getInventory();
            unordered_map<int, int> itemMapping;
            int displayIndex = 1;

            for (const auto& item : inventory) {
                if (item.second > 0 && item.first != 6) {
                    ItemSetting tempItem(static_cast<ItemType>(item.first));
                    cout << "[" << displayIndex << "] " << tempItem.getName()
                        << " - 보유 수량: " << item.second << "개" << endl;
                    itemMapping[displayIndex] = item.first;
                    displayIndex++;
                }
            }

            if (itemMapping.empty()) {
                cout << "사용 가능한 아이템이 없습니다!" << endl;
            }

            cout << "=======================" << endl;
            cout << "\n사용할 아이템의 번호를 입력하세요 (취소: -1): ";
            int userChoice;
            cin >> userChoice;

            if (userChoice == -1) {
                cout << "아이템 사용을 취소합니다." << endl;
            }
            else if (itemMapping.find(userChoice) != itemMapping.end()) {
                int actualItemIndex = itemMapping[userChoice];
                auto it = find_if(inventory.begin(), inventory.end(),
                    [actualItemIndex](const pair<const int, const int>& item) {
                        return item.first == actualItemIndex;
                    });

                if (it != inventory.end() && it->second > 0) {
                    ItemSetting item(static_cast<ItemType>(actualItemIndex));
                    item.use(&player);
                    cout << player.Name << "이(가) 아이템을 사용했습니다: "
                        << item.getName() << endl;
                }
                else {
                    cout << "해당 아이템이 없거나 수량이 부족합니다!" << endl;
                }
            }
            else
            {
                cout << player.Name << "은(는) 겁을 먹어 아이템도 제대로 쓰지 못한다." << endl;
            }

            cout << player.Name << "이(가) " << zombie->Name << "을(를) 공격합니다!" << endl;
            zombie->onHit(player.Attack());
            cout << endl;
        }
        else if (choice == "3") {
            Sleep(1000);
            cout << player.Name << "이(가) 도망쳤습니다!" << endl;
            Sleep(1000);
            system("cls");
            break;
        }

        // 좀비 체력 확인
        if (zombie->HP <= 0) {
            cout << zombie->Name << "이(가) 쓰러졌습니다!" << endl;
            dropSystem.dropItem(&player);
            break;
        }

        // 좀비 반격
        Sleep(1000);
        cout << "\n" << zombie->Name << "이(가) " << player.Name << "을(를) 공격합니다!" << endl;
        int dodgeChance = RandomUtil::GetRandomInt(1, 100);
        if (dodgeChance <= 10) {
            Sleep(1000);
            cout << player.Name << "이(가) 좀비의 공격을 회피했습니다!" << endl;
        }
        else {
            player.onHit(zombie->Attack());
            cout << endl;

            // 플레이어 체력 확인
            if (player.HP <= 0) {
                cout << player.Name << "이(가) 쓰러졌습니다! 전투 종료!" << endl;
                break;
            }
        }
    }
}