#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    int choice;
    cout << "당신은 누구입니까? 이름을 남기세요. 그것이 당신의 유일한 흔적이 될지도 모릅니다. : ";
    cin >> playerName;

    while (true) {
        cout << endl;
        cout << "어떤방식으로 생존하시겠습니까?" << endl;
        cout << "1. 사냥꾼 [공격력 특화]" << endl;
        cout << "2. 군인 [체력 특화]" << endl;
        cout << "3. 의사 [모르핀(체력 +50) 아이템을 5개 소지]" << endl;
        cout << "4. 범죄자 [200 골드를 소지]" << endl;
        cout << "> ";
        cin >> choice;
        if (choice == 1) {
            return Character(playerName, "사냥꾼", 50, 500);
        }
        else if (choice == 2) {
            return Character(playerName, "군인", 30, 800);
        }
        else if (choice == 3) {
            Character player(playerName, "의사", 30, 2000);
            player.addItem(0, 5);
            return player;
        }
        else if (choice == 4) {
            Character player(playerName, "범죄자", 30, 500);
            player.gainMoney(200);
            return player;
        }
        else {
            cout << "선택가능한 범위에서 벗어났습니다. 다시 선택해주세요. : " << endl;
        }
    }
}