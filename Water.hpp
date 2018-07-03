/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Water.hpp, specification file for the Water class.
*********************************************************************/

#ifndef WATER_HPP
#define WATER_HPP

#include "Item.hpp"

class Water : public Item {

public:
	Water();
	~Water();

	void examine();
};

#endif // !WATER_HPP