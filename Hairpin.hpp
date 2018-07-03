/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Hairpin.hpp, specification file for the Hairpin class.
*********************************************************************/

#ifndef HAIRPIN_HPP
#define HAIRPIN_HPP

#include "Item.hpp"

class Hairpin : public Item {

public:
	Hairpin();
	~Hairpin();

	void examine();
};

#endif // !HAIRPIN_HPP