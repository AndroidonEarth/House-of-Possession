/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ruby.hpp, specification file for the Ruby class.
*********************************************************************/

#ifndef RUBY_HPP
#define RUBY_HPP

#include "Item.hpp"

class Ruby : public Item {

public:
	Ruby();
	~Ruby();

	void examine();

};

#endif // !RUBY_HPP