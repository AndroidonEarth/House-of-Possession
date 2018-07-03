/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Study.hpp, specification file for the Study class.
*********************************************************************/

#ifndef STUDY_HPP
#define STUDY_HPP

#include "Space.hpp"

class Study : public Space {

protected:
public:
	Study();
	~Study();

	void examine();
	void useItem(ItemType, Item*, Player*);
	void unlock(ItemType, Item*, Player*);
	ReadType read();
};

#endif // !STUDY_HPP