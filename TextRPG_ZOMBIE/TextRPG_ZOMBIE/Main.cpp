#include "GamemodeBase/OpeningScene.h"
#include "GamemodeBase/CharacterCreation.h"
#include "ZombieFactory.h"
#include "GamemodeBase/MenuScene.h"
#include "GamemodeBase/BattleScene.h"
#include "Character.h"
#include "ZombieFactory.h"
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

    openingScene.showOpening(); // 오프닝
    Character player = characterCreation.createCharacter(); // 캐릭터 생성
    system("cls");
    menuScene.showMenu(player, battleScene, zombieFactory, shop); // 선택메뉴

    return 0;
}
