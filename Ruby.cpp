/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ruby.cpp, implementation file for the Ruby class.
*********************************************************************/

#include "Ruby.hpp"

using std::cout;

Ruby::Ruby() {

	itemName = "Ruby";
}

Ruby::~Ruby() {}

/*
*
*/
void Ruby::examine() {

	cout << "\nA one-of-a-kind Flawless Ruby, expertly cut and radiating with"
		<< "\nearthly energies. Those who gaze upon it become lost in the crimson"
		<< "\nuniverse sparkling within."
		<< "\n\nPress enter to continue...";
	getchar();
}