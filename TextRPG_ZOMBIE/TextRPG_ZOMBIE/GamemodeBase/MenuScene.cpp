#include "MenuScene.h"

void MenuScene::showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop) {

    while (true) {
        cout << "**********  생존을 위한 선택  **********" << endl;
        if (player.getLevel() != 10)
        {
            cout << "1. 적과 맞선다 (전투)" << endl;
        }
        else
        {
            cout << "1. 좀비의 왕과 맞선다 (전투)" << endl;
        }
        cout << "2. 필요한 물자를 찾는다 (상점)" << endl;
        cout << "3. 거울로 상태를 점검한다 (상태 확인)" << endl;
        cout << "0. 모든 것을 끝낸다... (게임 종료) " << endl;
        cout << "당신의 선택은 무엇입니까? : ";

        string choice;
        cin >> choice;

        if(choice == "1")
        {
            system("cls");
            unique_ptr<Actor> zombie = zombieFactory.CreateZombie(player.getLevel());
            battleScene.startBattle(player, zombie);
        }
        else if (choice == "2") {
            system("cls");
            shop.displayItems(player);
        }
        else if (choice == "3") {
            system("cls");
            player.printStatus();
            system("PAUSE");
            system("cls");
        }
        else if (choice == "0") {
            cout << "모든 것을 끝냈습니다. 이젠 좀비들도 당신을 찾지 못할 겁니다." << endl;
            return;
        }

        else {
            cout << "선택가능한 범위에서 벗어났습니다." << endl;
            Sleep(1000);
            system("cls");
        }
    }
}
