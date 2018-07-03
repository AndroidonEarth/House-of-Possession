/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Library.hpp, specification file for the Library class.
*********************************************************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Space.hpp"

class Library : public Space {

protected:
public:
	Library();
	~Library();

	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
	ReadType read();
};

#endif // !LIBRARY_HPP