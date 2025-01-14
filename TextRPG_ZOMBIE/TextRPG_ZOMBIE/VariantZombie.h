#pragma once

#include "Actor.h"
#include <string>
#include <istream>

class VariantZombie : public Actor
{
public:
    VariantZombie(const int playerLevel);

    string GetName() const;
    int GetMaxHP() const;
    int Attack() const;
    void onHit(int inputAttackPower) override;
    void printStatus() const;
};
