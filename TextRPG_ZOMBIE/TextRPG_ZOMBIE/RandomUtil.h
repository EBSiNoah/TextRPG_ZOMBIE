#pragma once
#include <random>

namespace RandomUtil
{
	extern std::default_random_engine generator;
	int GetRandomInt(int min, int max);
}