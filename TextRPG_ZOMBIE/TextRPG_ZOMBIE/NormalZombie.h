#pragma once

#include "Actor.h"
#include <string>
#include <iostream>

class NormalZombie : public Actor
{
public:
    NormalZombie(const int playerLevel);

    std::string GetName() const;
    int GetMaxHP() const;
    int Attack() override;
    void onHit(int inputAttackPower) override;
    void printStatus() const;
};