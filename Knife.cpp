/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Knife.cpp, implementation file for the Knife class.
*********************************************************************/

#include "Knife.hpp"

using std::cout;

Knife::Knife() {

	itemName = "Knife";
}

Knife::~Knife() {}

/*
*
*/
void Knife::examine() {

	cout << "\nA razor sharp chef's knife, engraved and bedazzled with numerous"
		<< "\nmulti-colored gems of various shapes and sizes. It's truly a sight"
		<< "\nto behold."
		<< "\n\nPress enter to continue...";
	getchar();
}