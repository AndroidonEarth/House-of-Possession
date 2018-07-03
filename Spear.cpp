/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Spear.cpp, implementation file for the Spear class.
*********************************************************************/

#include "Spear.hpp"

using std::cout;

Spear::Spear() {

	itemName = "Spear";
}

Spear::~Spear() {}

/*
*
*/
void Spear::examine() {

	cout << "\nAn Ancient Spear, with a hand-carved wooden shaft and a steel tip-"
		<< "\nhighly advanced for its time and clearly as sharp as when it when it"
		<< "\nit was first crafted. However, the wood did not withstand the test of"
		<< "\ntime as well as the tip... it is lined with cracks and fractures,"
		<< "\nnow resigning the weapon to be nothing more than a decoration."
		<< "\n\nPress enter to continue...";
	getchar();
}