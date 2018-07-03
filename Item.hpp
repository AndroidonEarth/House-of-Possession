/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Item.hpp, specification file for the Item class.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using std::string;

enum ItemType { HAIRPIN, KNIFE, LAMP, PITCHER, RUBY, SPEAR, STATUE, WATER };

class Item {

protected:
	string itemName;

public:
	Item();
	~Item();

	// Pure virtual functions.
	virtual void examine() = 0;

	// Getters.
	string getItemName();
};

#endif // !ITEM_HPP