/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Entryway.hpp, specification file for the Entryway class.
*********************************************************************/

#ifndef ENTRYWAY_HPP
#define ENTRYWAY_HPP

#include "Space.hpp"

class Entryway : public Space {

private:
	Space* bedroomPtr;

protected:
public:
	Entryway();
	~Entryway();

	void link(Space*);
	void examine();
	void useItem(ItemType, Item*, Player*);
	void interact();
};

#endif // !ENTRYWAY_HPP