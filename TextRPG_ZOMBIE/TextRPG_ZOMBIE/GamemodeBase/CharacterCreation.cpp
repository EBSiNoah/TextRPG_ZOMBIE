#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    int choice;

    cout << "����� �����Դϱ�? �̸��� ���⼼��. �װ��� ����� ������ ������ ������ �𸨴ϴ�. : ";
    cin >> playerName;

    while (true) {
        cout << "�������� �����Ͻðڽ��ϱ�? [1. ����, 2. ������] : ";
        cin >> choice;
        if (choice == 1) {
            return Character(playerName, "����", 30, 80);
        }
        else if (choice == 2) {
            return Character(playerName, "������", 20, 100);
        }
        else {
            cout << "���ð����� �������� ������ϴ�. �ٽ� �������ּ���. : " << endl;
        }
    }
}