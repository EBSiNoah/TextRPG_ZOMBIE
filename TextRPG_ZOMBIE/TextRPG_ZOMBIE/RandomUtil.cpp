#include "RandomUtil.h"

using namespace std;

namespace RandomUtil
{
	default_random_engine generator(random_device{}());

	int GetRandomInt(int min, int max)
	{
		uniform_int_distribution<int> randomValue(min, max);
		return randomValue(generator);
	}
}