#include "GamemodeBase/OpeningScene.h"
#include "GamemodeBase/CharacterCreation.h"
#include "ZombieFactory.h"
#include "GamemodeBase/MenuScene.h"
#include "GamemodeBase/BattleScene.h"
//#include "../EndingScene.h"
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
    
    //Character player(playerName, "군인", 30, 80);
    //BattleScene battleScene;
    //ZombieFactory zombieFactory;
    
    //MenuScene menuScene;

    //menuScene.showMenu(player, battleScene, zombieFactory, shop); // 선택 메뉴

    //EndingScene endingScene;
    //endingScene.showEnding(player.getHP() > 0, player.getName(), "좀비 보스"); // 엔딩

    return 0;
}
//오프닝 -> 생성 -> 선택메뉴 -> 전투
