#pragma once

namespace RandomFunctions
{

	// Returns a random integer from min to max
	// min must be <= max
	int randint(int min, int max);

	// Returns true if an event with the given chance % occurs
	bool randomChance(int chance);
	bool randomChance(float chance);

	// Returns a random float from min to max
	// min must be <= max
	float randfloat(float min, float max);

}