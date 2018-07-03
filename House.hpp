/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: House.hpp, specification file for the House class.
*********************************************************************/

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Space.hpp"

class House {

private:
	Space*** house;

	// Utility functions.
	void linkRooms();
	void createRooms();

public:
	// Constructors/Destructors.
	House();
	~House();

	// Getters.
	Space* getSpace(int x, int y);
};

#endif // !HOUSE_HPP