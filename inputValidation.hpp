/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: inputValidation.hpp, specification file for the 
		inputValidation helper functions.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

#include <string>
using std::string;

char getMenuChoice(char maxChoice);
int getValidIntInRange(int min, int max);
char getValidChar(string opt1, string opt2);

#endif