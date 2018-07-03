/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: inputValidation.cpp, implementation file for the
		inputValidation helper functions.
*********************************************************************/

#include "inputValidation.hpp"
#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/**
* Helper function to validate a particular menu choice by the user.
* This function is used right after a menu is printed to prompt the user for input.
* Takes a char as a parameter, the number of the max menu choice, for use in
* comparison with the user input as well as printing out an accurate error statement
* when validation fails.
*/
char getMenuChoice(char maxChoice) {

	bool errFlag = false;		// Set error flag member varaible.
	string input;				// Declare a string to hold the line of input.
	char validOpt;				// Valid int in char form for the function to return.

	// This do-while loop will loop until the user enters a valid input.
	do {
		// Read line of input to the string variable.
		getline(cin, input);

		// Initialize stringstream with input string.
		stringstream sStream(input);

		// If able to convert to a char and nothing left over.
		if (sStream >> validOpt && !(sStream >> input)) {

			// Check if valid selection.
			if (validOpt < '1' || validOpt > maxChoice) {

				// Message used when there only two menu options.
				if (maxChoice == '2') {
					cout << "\nSorry, you must select either 1 or "
						<< maxChoice << ". Please re-enter selection.\n" << endl;
				}
				// Message for more than two options.
				else {
					cout << "\nSorry, you must select an option between "
						<< "1 and " << maxChoice << ". Please re-enter selection.\n"
						<< endl;
				}
			}
			else {		// Converted and valid selection. This will end the loop.

				errFlag = true;
			}
		} 
		else {		// User did not enter a character or number.

			// Message used when there only two menu options.
			if (maxChoice == '2') {
				cout << "\nSorry, you must select either 1 or "
					<< maxChoice << ". Please re-enter selection.\n" << endl;
			}
			// Message for more than two options.
			else {
				cout << "\nSorry, you must select an option between "
					<< "1 and " << maxChoice << ". Please re-enter selection.\n"
					<< endl;
			}
		}
	} while (errFlag == false);		// Loop again if no valid input.

	return validOpt;
}

/**
* Helper function to validate whether a user input is an integer between 
* another two specified integers. This function is used right after a prompt 
* to enter an integer within a range. Takes two ints as parameters to use as the
* min and max of the range for comparison with the user input, as well as printing
* out an accurate error statement when validation fails.
*/
int getValidIntInRange(int min, int max) {

	bool errFlag = false;		// Set error flag member varaible.
	string input;				// Declare a string to hold the line of input.
	int validInt;				// Valid integer for the function to return.

	// This do-while loop will loop until the user enters a valid input.
	do {
		// Read line of input to the string variable.
		getline(cin, input);

		// Initialize stringstream with input string.
		stringstream sStream(input);

		// If able to convert to int and nothing left over.
		if (sStream >> validInt && !(sStream >> input)) {

			// Check if within bounds.
			if (validInt < min || validInt > max) {

				cout << "\nSorry, you must enter an integer between "
					<< min << " and " << max << ". "
					<< "Please re-enter choice.\n" << endl;
			}
			else {		// Converted and within bounds.

				errFlag = true;
			}
		}
		else {		// User did not enter an integer value.

			cout << "\nSorry, you must enter an integer between "
				<< min << " and " << max << ". "
				<< "Please re-enter choice.\n" << endl;
		}
	} while (errFlag == false);		// Loop again if no valid input.

	return validInt;
}

/**
* Helper function to validate whether a user input is a char that is either
* a lower case or upper case version of the first letter of the valid options.
* This function is used right after a prompt to enter the first letter of one of two
* options (ie, 'y' or 'Y' for YES or 'n' or 'N' for NO). Takes two strings as
* parameters, the two options, in order to extract the upper case and lower case
* versions of the first letter of the options, for use in comparison with the 
* user input as well as printing an accurate error statement if validation fails.
*/
char getValidChar(string opt1, string opt2) {

	// To hold the upper and lowercase versions of the two possible options.
	char opt1U, opt1L, opt2U, opt2L;

	bool errFlag = false;		// Set error flag member varaible.
	string input;				// Declare a string to hold the line of input.
	char validChar;				// Valid char for the function to return.

	// Get the upper and lowercase versions of the first letter
	// of the options for comparison.
	opt1U = toupper(opt1[0]);
	opt1L = tolower(opt1[0]);
	opt2U = toupper(opt2[0]);
	opt2L = tolower(opt2[0]);

	do {
		// Read line of input to the string variable.
		getline(cin, input);

		// Initialize stringstream with input string.
		stringstream sStream(input);

		// If able to convert and nothing left over.
		if (sStream >> validChar && !(sStream >> input)) {

			// Check if valid selection.
			if (validChar != opt1U && validChar != opt1L &&
				validChar != opt2U && validChar != opt2L) {

				cout << "\nSorry, you must select either "
					<< opt1 << "('" << opt1L << "'/'" << opt1U << "')"
					<< " or " << opt2 << "('" << opt2L << "'/'" << opt2U << "').\n" 
					<< "Please re-enter selection.\n" << endl;
			}
			else {		// Converted and valid selection.

				errFlag = true;
			}
		}
		else {		// User did not enter a valid character.

			cout << "\nSorry, you must enter a valid character, either "
				<< "('" << opt1L << "'/'" << opt1U << "')"
				<< " or " << "('" << opt2L << "'/'" << opt2U << "').\n"
				<< "Please re-enter selection.\n" << endl;
		}
	} while (errFlag == false);		// Loop again if no valid input.

	return validChar;
}