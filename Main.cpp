#include <iostream>

#include "RarityHandler.h"

int main() {

	int elements = 10;
	int tries = 1000;

	RarityHandler<double> rh;

	std::vector<double> elementStorage(elements);
	std::vector<double*> elementPtrs(elements);
	std::vector<int> rarities;
	
	std::vector<int> counts(elements);
	for (int i = 1; i <= elements; i++) {
		elementStorage[i - 1] = i;
		elementPtrs[i - 1] = &elementStorage[i - 1];
		rarities.push_back(i);
		counts[i - 1] = 0;
	}

	rh.addList(elementPtrs, rarities);

	for (int x = 0; x < tries; x++) {
		int idx = *rh.selectRandomObject();
		counts[idx - 1]++;
	}

	std::cout << "1: " << (counts[0] / (float)tries) * 100 << " 5: " << 100 * counts[elements - 1] / (float)tries << std::endl;

	rh.clear();

	for (int i = 1; i <= elements; i++) {
		rh.addObject(elementStorage[i - 1], i);
		counts[i - 1] = 0;
	}

	for (int x = 0; x < tries; x++) {
		int idx = *rh.selectRandomObject();
		counts[idx - 1]++;
	}

	std::cout << "1: " << (counts[0] / (float)tries) * 100 << " 5: " << 100 * counts[elements - 1] / (float)tries << std::endl;

	return 0;
}
