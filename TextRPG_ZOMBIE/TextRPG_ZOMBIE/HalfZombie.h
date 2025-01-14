#pragma once

#include "Actor.h"
#include <string>
#include <iostream>

class HalfZombie : public Actor
{
public:
    HalfZombie(const int playerLevel);

    string GetName() const;
    int GetMaxHP() const;
    int Attack() const;
    void onHit(int inputAttackPower) override;
    void printStatus() const;
};