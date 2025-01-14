#pragma once
#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "../Character.h"
#include "BattleScene.h"
#include "../ZombieFactory.h"
#include "../Shop.h"
#include <iostream>
using namespace std;

class MenuScene {
public:
    void showMenu(Character& player, BattleScene& battleScene, ZombieFactory& zombieFactory, Shop& shop);
};

#endif