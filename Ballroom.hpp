/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ballroom.hpp, specification file for the Ballroom class.
*********************************************************************/

#ifndef BALLROOM_HPP
#define BALLROOM_HPP

#include "Space.hpp"

class Ballroom : public Space {

protected:

public:
	Ballroom();
	~Ballroom();

	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
	ReadType read();
};

#endif // !BALLROOM_HPP