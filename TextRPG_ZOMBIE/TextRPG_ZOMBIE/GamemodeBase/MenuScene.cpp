#include "MenuScene.h"

void MenuScene::showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop) {
 
 
    while (true) {
        cout << " =====�޴�â===== " << endl;
        cout << " 1. ���� ���� " << endl;
        cout << " 2. ���� " << endl;
        cout << " 3. ���� Ȯ�� " << endl;
        cout << " 0. ���� ���� " << endl;
        cout << " ����: ";

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
            cout << "������ �����մϴ�." << endl;
            return;
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���." << endl;
        }
    }
}