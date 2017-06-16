#include "RandomFunctions.h"

#include <random>

namespace RandomFunctions
{

	int randint(int min, int max) {
		std::random_device device;
		std::mt19937 gen(device());
		std::uniform_int<int> udist(min, max);
		return udist(gen);
	}

	bool randomChance(int chance) {
		return randint(1, 100) <= chance;
	}

	bool randomChance(float chance) {
		return randfloat(0, 100) <= chance;
	}

	float randfloat(float min, float max) {
		std::random_device device;
		std::mt19937 gen(device());
		std::uniform_real<float> udist(min, max);
		return udist(gen);
	}

}
