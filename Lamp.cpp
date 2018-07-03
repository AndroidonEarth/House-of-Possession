/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Lamp.cpp, implementation file for the Lamp class.
*********************************************************************/

#include "Lamp.hpp"

using std::cout;

Lamp::Lamp() {

	itemName = "Lamp";
}

Lamp::~Lamp() {}

/*
*
*/
void Lamp::examine() {

	cout << "\nThis Antique Lamp is old, and has seen much usage in the dark of"
		<< "\nof the night, but it's wax wick still burns brilliantly."
		<< "\n\nPress enter to continue...";
	getchar();
}