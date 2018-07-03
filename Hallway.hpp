/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Hallway.hpp, specification file for the Hallway class.
*********************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "Space.hpp"

class Hallway : public Space {

protected:
public:
	Hallway();
	~Hallway();

	void examine();
	void useItem(ItemType, Item*, Player*);
};

#endif // !HALLWAY_HPP