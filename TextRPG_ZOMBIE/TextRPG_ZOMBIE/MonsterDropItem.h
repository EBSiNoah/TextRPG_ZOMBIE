#pragma once
#include "Item.h"
#include "Character.h"
#include "RandomUtil.h"

// Character.h의 인벤토리 구현을 보고 dropItem의 경로 수정
class MonsterDropItem
{
public:
	void dropItem(Character* chara);
};