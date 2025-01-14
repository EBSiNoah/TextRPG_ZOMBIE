#pragma once

#include "Actor.h"
#include <iostream>
#include <string>

class BossZombie : public Actor
{
public:
    BossZombie(const int playerLevel);

    std::string GetName() const;
    int GetMaxHP() const;
    int Attack() const;
    void onHit(int inputAttackPower) override;
    void printStatus() const;
};