/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Pitcher.hpp, specification file for the Pitcher class.
*********************************************************************/

#ifndef PITCHER_HPP
#define PITCHER_HPP

#include "Item.hpp"

class Pitcher : public Item {

public:
	Pitcher();
	~Pitcher();

	void examine();
};

#endif // !PITCHER_HPP