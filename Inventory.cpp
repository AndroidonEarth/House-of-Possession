/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Inventory.cpp, implementation file for the Inventory class.
*********************************************************************/

#include "Inventory.hpp"

using std::cout;
using std::pair;

/*
*
*/
Inventory::Inventory() {

	capacity = 3;
}

/*
*
*/
Inventory::~Inventory() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
void Inventory::addItem(ItemType itemKey, Item* item) {

	// If the player's inventory is not full.
	if (items.size() < capacity) {

		// Add the item.
		items.insert(pair <ItemType, Item*>(itemKey, item));
		cout << "\n" << item->getItemName() << " added to inventory."
			<< "\n\nPress enter to continue...";
		getchar();
	}
	else {

		// Otherwise print an error message.
		cout << "\nInventory is full! Cannot add " << item->getItemName() << "."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}

/*
*
*/
void Inventory::removeItem(ItemType itemKey) {

	// Make sure the item is in the inventory.
	if (items.find(itemKey) != items.end()) {

		items.erase(itemKey);
	}
	// TRACE:
	else {

		cout << "\nError: Item not found in inventory.";
	}
}

// Getters.
map<ItemType, Item*>::iterator Inventory::getBeginIter() { return items.begin(); }
map<ItemType, Item*>::iterator Inventory::getEndIter() { return items.end(); }
int Inventory::getCount() { return items.size(); }