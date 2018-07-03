/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Inventory.hpp, specification file for the Inventory class.
*********************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"

#include <map>
using std::map;

class Item;

class Inventory {

private:
	map<ItemType, Item*> items;
	int capacity;

public:
	Inventory();
	~Inventory();

	// Mutators.
	void addItem(ItemType, Item*);
	void removeItem(ItemType);

	// Getters.
	map<ItemType, Item*>::iterator getBeginIter();
	map<ItemType, Item*>::iterator getEndIter();
	int getCount();

};

#endif // !INVENTORY_HPP