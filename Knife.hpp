/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Knife.hpp, specification file for the Knife class.
*********************************************************************/

#ifndef KNIFE_HPP
#define KNIFE_HPP

#include "Item.hpp"

class Knife : public Item {

public:
	Knife();
	~Knife();

	void examine();
};

#endif // !KNIFE_HPP