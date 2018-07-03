/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Water.cpp, implementation file for the Water class.
*********************************************************************/

#include "Water.hpp"

using std::cout;

Water::Water() {

	itemName = "Pitcher (filled)";
}

Water::~Water() {}

/*
*
*/
void Water::examine() {

	cout << "\nThe Ornate Pitcher, now filled with old mossy bath water. I wouldn't"
		<< "\ntry to drink it though..."
		<< "\n\nPress enter to continue...";
	getchar();
}