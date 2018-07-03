/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Statue.cpp, implementation file for the Statue class.
*********************************************************************/

#include "Statue.hpp"

using std::cout;

Statue::Statue() {
	
	itemName = "Statue";
}

Statue::~Statue() {}

/*
*
*/
void Statue::examine() {

	cout << "\nA very heavy Marble Statue carved in the likeness of"
		<< "\nMs. Greyhardt herself. Even for it's smaller size, the details are"
		<< "\nimmaculate, and one would imagine the crafter may have feared for"
		<< "\nfor their life during it's creation- afraid of displeasing the"
		<< "\nmodel."
		<< "\n\nPress enter to continue...";
	getchar();
}