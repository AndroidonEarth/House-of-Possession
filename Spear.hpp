/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Spear.hpp, specification file for the Spear class.
*********************************************************************/

#ifndef SPEAR_HPP
#define SPEAR_HPP

#include "Item.hpp"

class Spear : public Item {

public:
	Spear();
	~Spear();

	void examine();
};

#endif // !SPEAR_HPP