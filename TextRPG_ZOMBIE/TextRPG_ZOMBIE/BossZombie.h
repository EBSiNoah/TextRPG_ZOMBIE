#pragma once

#include "Actor.h"
#include <iostream>
#include <string>
#include <windows.h>

class BossZombie : public Actor
{
public:
    BossZombie(const int playerLevel);

    std::string GetName() const;
    int GetMaxHP() const;
    int Attack() override;
    void onHit(int inputAttackPower) override;
    void printStatus() const;

private:
    void recoverHP();
};