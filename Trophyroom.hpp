/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Trophyroom.hpp, specification file for the Trophyroom class.
*********************************************************************/

#ifndef TROPHYROOM_HPP
#define TROPHYROOM_HPP

#include "Space.hpp"

class Trophyroom : public Space {

private:
	Space* libraryPtr;

protected:
public:
	Trophyroom();
	~Trophyroom();

	void link(Space*);
	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
	ReadType read();
	void interact();
};

#endif // !TROPHYROOM_HPP