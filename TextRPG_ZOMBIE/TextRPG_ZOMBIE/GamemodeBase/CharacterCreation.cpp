#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    int choice;
    cout << "����� ĳ���� �̸��� �Է��ϼ���: ";
    cin >> playerName;

    while (true) {
        cout << "���� ����(1. ����, 2. ������): ";
        cin >> choice;
        if (choice == 1) {
            return Character(playerName, "����", 30, 80);
        }
        else if (choice == 2) {
            return Character(playerName, "������", 20, 100);
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
        }
    }
}