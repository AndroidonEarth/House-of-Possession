/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Diningroom.hpp, specification file for the Diningroom class.
*********************************************************************/

#ifndef DININGROOM_HPP
#define DININGROOM_HPP

#include "Space.hpp"

class Diningroom : public Space {

private:
	Space* trophyroomPtr;

protected:
public:
	Diningroom();
	~Diningroom();

	void link(Space*);
	void examine();
	void useItem(ItemType, Item*, Player*);
	ReadType read();
};

#endif // !DININGROOM_HPP