#include "../RandomUtil.h"
#include "BattleScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include <vector>



using namespace std;
using namespace RandomUtil;

void BattleScene::startBattle(Character& player, unique_ptr<Actor>& zombie) {

    vector<string> battleMentBox = { "�η����� �������������� �ο�����..!", "������", "�ٸ��� �ĵ�Ÿ����� �ο�����..!", "�ٷ����� ���ʴ��� �� �������� �ο�����..."};
    int randomValue = RandomUtil::GetRandomInt(0, battleMentBox.size() - 1);

    cout << "**********  " << zombie->Name << "��(��) �����ƴ�! " << battleMentBox[randomValue] << "  **********" << endl;

    while (true) {
        player.onHit(zombie->Attack());
        Sleep(1000);
        cout << "\n";
        if (player.HP <= 0) break;

        zombie->onHit(player.Attack());
        Sleep(1000);
        cout << "\n";
        if (zombie->HP <= 0) break;
    }
}
