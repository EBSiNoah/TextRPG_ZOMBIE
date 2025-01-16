#include "CharacterCreation.h"

Character CharacterCreation::createCharacter() {
    string playerName;
    string choice;
    system("PAUSE");
    system("cls");
    cout << "당신은 누구입니까? 이름을 남기세요.\n그것이 당신의 유일한 흔적이 될지도 모릅니다.\n> ";
    while (true) {
        cin >> playerName;
        if (playerName.length() < 8)
        {
            break;
        }
        else
        {
            cout << "8글자 이내로 작성해주세요 : ";
        }
    }

    while (true) {
        cout << endl;
        Sleep(1000);
        cout << "어떤방식으로 생존하시겠습니까?" << endl;
        cout << "1. 사냥꾼 [공격력 특화]" << endl;
        cout << "2. 군인 [체력 특화]" << endl;
        cout << "3. 의사 [모르핀(체력 +50) 아이템을 5개 소지]" << endl;
        cout << "4. 범죄자 [200 골드를 소지]" << endl;
        cout << "> ";
        cin >> choice;
        if (choice == "1") {
            Character player(playerName, "사냥꾼", 50, 500);
            Message(playerName);
            return player;
        }
        else if (choice == "2") {
            Character player(playerName, "군인", 30, 800);
            Message(playerName);
            return player;
        }
        else if (choice == "3") {
            Character player(playerName, "의사", 30, 2000);
            player.addItem(0, 5);
            Message(playerName);
            return player;
        }
        else if (choice == "4") {
            Character player(playerName, "범죄자", 30, 500);
            player.gainMoney(200);
            Message(playerName);
            return player;
        }
        else {
            cout << "선택가능한 범위에서 벗어났습니다. 다시 선택해주세요. : " << endl;
        }
    }
}

void CharacterCreation::Message(string playerName) {
    system("cls");
    Sleep(1000);
    cout << playerName << ", 당신은 마지막 생존자입니다.\n" << endl;
    Sleep(1000);
    cout << "살아남기 위해서 그것들과 맞서 싸우세요";
    Sleep(2000);
}