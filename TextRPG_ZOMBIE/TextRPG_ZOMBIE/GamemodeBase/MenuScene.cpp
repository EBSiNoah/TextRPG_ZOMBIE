#include "MenuScene.h"

void MenuScene::showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop) {
 
 
    while (true) {
        cout << "**********  생존을 위한 선택  **********" << endl;
        cout << "1. 적과 맞선다(전투)" << endl;
        cout << "2. 필요한 물자를 찾는다(상점)" << endl;
        cout << "3. 거울로 상태를 점검한다(상태 확인)" << endl;
        cout << "0. 모든 것을 끝낸다...(게임 종료) " << endl;
        cout << "당신의 선택은 무엇입니까? :";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            unique_ptr<Actor> zombie = zombieFactory.CreateZombie(player.getLevel());
            battleScene.startBattle(player, zombie);
            break;
        }
        case 2:
            system("cls");
            shop.displayItems();
            break;
        case 3:
            system("cls");
            player.printStatus();
            break;
        case 0:
            cout << "모든 것을 끝냈습니다. 이젠 좀비들도 당신을 찾지 못할 겁니다." << endl;
            return;
        default:
            cout << "선택가능한 범위에서 벗어났습니다. 다시 선택해주세요. : " << endl;
        }
    }
}