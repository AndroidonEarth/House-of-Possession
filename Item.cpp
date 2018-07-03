/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Item.cpp, implementation file for the Item class.
*********************************************************************/

#include "Item.hpp"

Item::Item() {}
Item::~Item() {}

// Getters.
string Item::getItemName() { return this->itemName; }