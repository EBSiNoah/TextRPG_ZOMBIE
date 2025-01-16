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
#include <Windows.h>

using namespace std;

int main() {
    // 콘솔의 출력 및 입력 인코딩을 UTF-8로 변경
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    OpeningScene openingScene;
    BattleScene battleScene;
    ZombieFactory zombieFactory;
    Shop shop;
    CharacterCreation characterCreation;
    MenuScene menuScene;

    openingScene.showOpening(); // 오프닝
    Character player = characterCreation.createCharacter(); // 캐릭터 생성
    system("cls");
    player.gainMoney(1000);
    menuScene.showMenu(player, battleScene, zombieFactory, shop); // 선택메뉴
    
    //EndingScene endingScene;
    //endingScene.showEnding(player.getHP() > 0, player.getName(), "좀비 보스"); // 엔딩

    return 0;
}
//오프닝 -> 생성 -> 선택메뉴 -> 전투
