/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Pitcher.cpp, implementation file for the Pitcher class.
*********************************************************************/

#include "Pitcher.hpp"

using std::cout;

Pitcher::Pitcher() {

	itemName = "Pitcher";
}

Pitcher::~Pitcher() {}

/*
*
*/
void Pitcher::examine() {

	cout << "\nA dusty Ornate Pitcher, decorated with an engraved dinner scene"
		<< "\non the sides of it's curved facade. It was once filled with"
		<< "\nhigh quality drinks for the serving pleasure of guests,"
		<< "\nbut those have since dried up."
		<< "\n\nPress enter to continue...";
	getchar();
}