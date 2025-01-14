#include "MenuScene.h"

void MenuScene::showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop) {
 
 
    while (true) {
        cout << " =====메뉴창===== " << endl;
        cout << " 1. 전투 시작 " << endl;
        cout << " 2. 상점 " << endl;
        cout << " 3. 상태 확인 " << endl;
        cout << " 0. 게임 종료 " << endl;
        cout << " 선택: ";

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
            cout << "게임을 종료합니다." << endl;
            return;
        default:
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
        }
    }
}