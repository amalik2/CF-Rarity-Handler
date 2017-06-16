#pragma once

#include <vector>
#include <algorithm>

#include "RandomFunctions.h"

template <class T>
class RarityHandler
{

private:
	std::vector<int> rarities;
	std::vector<T> objects;

	// Get the sum of the rarities
	int getSum() {
		return rarities.size() == 0 ? 0 : rarities.back();
	}

public:
	RarityHandler() {
	}
	~RarityHandler() {
	}

	// Add a new object to the list, by specifying the new element's rarity
	void addObject(T& object, int rarity) {
		rarities.push_back(getSum() + rarity);
		objects.push_back(object);
	}

	// Randomly select an element from the list, taking into account each pair's rarity value
	T& selectRandomObject();

	// Reset the list
	void clear() {
		rarities.clear();
		objects.clear();
	}

	// Insert a list of objects into the handler all at once
	// For any element with index i in objList, it's rarity is rarityList[i]
	void addList(std::vector<T> &objList, std::vector<int> &rarityList) {
		objects.insert(objects.end(), objList.begin(), objList.end());

		for (int &rarity : rarityList) {
			rarities.push_back(getSum() + rarity);
		}
	}

};

// Select a random integer, and take the element with the 
// smallest rarity subsequence sum that is >= the chosen number
template<class T>
T & RarityHandler<T>::selectRandomObject()
{
	// Select a random number to choose an element based on
	int rarity = RandomFunctions::randint(1, getSum());

	for (size_t i = 0; i < rarities.size(); i++) {

		// Smallest element where sum of individual rarities of elements[0...i] >= rarity
		if (rarities[i] >= rarity) {
			return objects[i];
		}
		else if (rarities[i] < rarity) {
			// If this element's value is equal to the same value as the last element, there exists no element with a larger rarity
			if (rarities[i] == rarities.back()) {
				return objects[i];
			}
		}
	}
	return objects.front();
}