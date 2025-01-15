#include "GamemodeBase/OpeningScene.h"
#include "GamemodeBase/CharacterCreation.h"
#include "ZombieFactory.h"
#include "GamemodeBase/MenuScene.h"
#include "GamemodeBase/BattleScene.h"
//#include "../EndingScene.h"
#include "Character.h"
#include "Shop.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    OpeningScene openingScene;
    BattleScene battleScene;
    ZombieFactory zombieFactory;
    Shop shop;
    CharacterCreation characterCreation;
    MenuScene menuScene;

    openingScene.showOpening(); // ������
    Character player = characterCreation.createCharacter(); // ĳ���� ����
    system("cls");
    player.gainMoney(1000);
    menuScene.showMenu(player, battleScene, zombieFactory, shop); // ���ø޴�
    
    //EndingScene endingScene;
    //endingScene.showEnding(player.getHP() > 0, player.getName(), "���� ����"); // ����

    return 0;
}
//������ -> ���� -> ���ø޴� -> ����
