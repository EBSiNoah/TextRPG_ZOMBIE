#pragma once
#ifndef BATTLESCENE_H
#define BATTLESCENE_H
#include "../Character.h"
#include "../ZombieFactory.h"
#include <iostream>
#include <unordered_map>
#include "../RandomUtil.h"
using namespace std;

class BattleScene {
public:
    void startBattle(Character& player, unique_ptr<Actor>& enemy);
};

#endif