#include "MenuScene.h"

void MenuScene::showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop) {
 
 
    while (true) {
        cout << "**********  ������ ���� ����  **********" << endl;
        cout << "1. ���� �¼���(����)" << endl;
        cout << "2. �ʿ��� ���ڸ� ã�´�(����)" << endl;
        cout << "3. �ſ�� ���¸� �����Ѵ�(���� Ȯ��)" << endl;
        cout << "0. ��� ���� ������...(���� ����) " << endl;
        cout << "����� ������ �����Դϱ�? :";

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
            cout << "��� ���� ���½��ϴ�. ���� ����鵵 ����� ã�� ���� �̴ϴ�." << endl;
            return;
        default:
            cout << "���ð����� �������� ������ϴ�. �ٽ� �������ּ���. : " << endl;
        }
    }
}