#include "../RandomUtil.h"
#include "BattleScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include "../MonsterDropItem.h"


using namespace std;
using namespace RandomUtil;

void BattleScene::startBattle(Character& player, unique_ptr<Actor>& zombie) {
    MonsterDropItem dropSystem;
    vector<string> battleMentBox = { "두려워서 눈물이 범벅이 되었지만 싸워보자!", "살려줘요", "다리가 후들거리지만 싸워보자!", "다래끼로 한쪽 눈이 안보이지만 싸워보자!"};
    int randomValue = RandomUtil::GetRandomInt(0, battleMentBox.size() - 1);

    cout << "**********  " << zombie->Name << "을(를) 마주쳤다..! " << battleMentBox[randomValue] << "  **********" << endl;

    while (true) {
        player.onHit(zombie->Attack());
        Sleep(1000);
        cout << "\n";
        if (player.HP <= 0) break;

        zombie->onHit(player.Attack());
        Sleep(1000);
        cout << "\n";
        if (zombie->HP <= 0)
        {
            dropSystem.dropItem(&player);
            break;
        }
    }
}
