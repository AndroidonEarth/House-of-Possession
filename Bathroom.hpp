/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Bathroom.hpp, specification file for the Bathroom class.
*********************************************************************/

#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include "Space.hpp"

class Bathroom : public Space {

protected:
public:
	Bathroom();
	~Bathroom();

	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
};

#endif // !BATHROOM_HPP