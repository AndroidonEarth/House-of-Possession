/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Bedroom.hpp, specification file for the Bedroom class.
*********************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Space.hpp"

class Bedroom : public Space {

protected:
public:
	Bedroom();
	~Bedroom();

	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
};

#endif // !BEDROOM_HPP