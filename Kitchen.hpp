/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Kitchen.hpp, specification file for the Kitchen class.
*********************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen : public Space {

private:
	Space* bathroomPtr;

protected:
public:
	Kitchen();
	~Kitchen();

	void link(Space*);
	void examine();
	void useItem(ItemType, Item*, Player*);
	void interact();
};

#endif // !KITCHEN_HPP