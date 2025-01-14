#pragma once
#include "Actor.h"
#include <memory>

class ZombieFactory
{
public:
    ZombieFactory();
    std::unique_ptr<Actor> CreateZombie(const int playerLevel);
};