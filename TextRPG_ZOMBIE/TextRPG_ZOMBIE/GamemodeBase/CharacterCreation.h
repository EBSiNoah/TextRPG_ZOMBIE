#pragma once
#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H
#include "../Character.h"
#include <iostream>
#include <windows.h>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

class CharacterCreation {
public:
    Character createCharacter();
    void Message(string playerName);
};

#endif