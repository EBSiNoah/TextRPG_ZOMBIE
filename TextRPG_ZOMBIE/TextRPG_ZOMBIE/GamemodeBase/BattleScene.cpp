#include "BattleScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include "../MonsterDropItem.h"


using namespace std;

void BattleScene::startBattle(Character& player, unique_ptr<Actor>& zombie) {
    cout << "===== ������ ���۵˴ϴ�! =====" << endl;
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

            break;
        }
    }
}
