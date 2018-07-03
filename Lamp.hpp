/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Lamp.hpp, specification file for the Lamp class.
*********************************************************************/

#ifndef LAMP_HPP
#define LAMP_HPP

#include "Item.hpp"

class Lamp : public Item {

public:
	Lamp();
	~Lamp();

	void examine();
};

#endif // !LAMP_LAMP