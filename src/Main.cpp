#include <iostream>

#include "RarityHandler.h"

int main() {

	int elements = 5;
	int tries = 1000;

	RarityHandler<double> rh;

	std::vector<double> elementList;
	std::vector<int> rarities;
	std::vector<int> counts;

	for (int i = 1; i <= elements; i++) {
		elementList.push_back(i);
		rarities.push_back(i);
		counts.push_back(0);
	}

	rh.addList(elementList, rarities);

	for (int x = 0; x < tries; x++) {
		int idx = rh.selectRandomObject();
		counts[idx - 1]++;
	}

	std::cout << "1: " << (counts[0] / (float)tries) * 100 << " 5: " << 100 * counts[4] / (float)tries << std::endl;

	rh.clear();
	counts.clear();

	for (int i = 1; i <= elements; i++) {
		double value = i;
		rh.addObject(value, i);
		counts.push_back(0);
	}

	for (int x = 0; x < tries; x++) {
		int idx = rh.selectRandomObject();
		counts[idx - 1]++;
	}

	std::cout << "1: " << (counts[0] / (float)tries) * 100 << " 5: " << 100 * counts[4] / (float)tries << std::endl;

	return 0;
}