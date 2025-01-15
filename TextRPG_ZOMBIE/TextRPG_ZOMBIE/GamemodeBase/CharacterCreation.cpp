#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    int choice;
    cout << "당신의 캐릭터 이름을 입력하세요: ";
    cin >> playerName;

    while (true) {
        cout << "직업 선택(1. 군인, 2. 생존자): ";
        cin >> choice;
        if (choice == 1) {
            return Character(playerName, "군인", 30, 80);
        }
        else if (choice == 2) {
            return Character(playerName, "생존자", 20, 100);
        }
        else {
            cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
        }
    }
}