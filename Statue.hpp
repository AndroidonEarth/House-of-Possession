/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Statue.hpp, specification file for the Statue class.
*********************************************************************/

#ifndef STATUE_HPP
#define STATUE_HPP

#include "Item.hpp"

class Statue : public Item {

public:
	Statue();
	~Statue();

	void examine();
};

#endif // !STATUE_HPP