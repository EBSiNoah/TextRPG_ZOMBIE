#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    int choice;

    cout << "당신은 누구입니까? 이름을 남기세요. 그것이 당신의 유일한 흔적이 될지도 모릅니다. : ";
    cin >> playerName;

    while (true) {
        cout << "어떤방식으로 생존하시겠습니까? [1. 군인, 2. 생존자] : ";
        cin >> choice;
        if (choice == 1) {
            return Character(playerName, "군인", 30, 80);
        }
        else if (choice == 2) {
            return Character(playerName, "생존자", 20, 100);
        }
        else {
            cout << "선택가능한 범위에서 벗어났습니다. 다시 선택해주세요. : " << endl;
        }
    }
}