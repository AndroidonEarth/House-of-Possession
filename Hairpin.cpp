/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Hairpin.cpp, implementation file for the Hairpin class.
*********************************************************************/

#include "Hairpin.hpp"

using std::cout;

Hairpin::Hairpin() {

	itemName = "Hairpin";
}

Hairpin::~Hairpin() {}

/*
*
*/
void Hairpin::examine() {

	cout << "\nA a long, slender Decorated Hairpin with an embossed and"
		<< "\nglossy swirl pattern, it's appearance exhumes luxury and class."
		<< "\n\nPress enter to continue...";
	getchar();

}