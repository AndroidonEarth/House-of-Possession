/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: main.cpp, driver for the game.
*********************************************************************/

#include "Game.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

#include <ctime>

int main() {

	Game* game;
	char choice;	// To hold the user choice.

	// Setup seed and srand for use with rand().
	unsigned seed = time(0);
	srand(seed);

	// Display the intro to the program.
	displayTitle();

	// Prompt user to play or exit.
	choice = getMenuChoice(mainMenu());

	// Start the game.
	while (choice == '1') {

		game = new Game();
		game->runGame();

		// Prompt to play again?
		choice = getMenuChoice(playAgainMenu());

		delete game;
	}

	// If user decided to immediately exit or not play again, display the outro.
	displayOutro();
	getchar();
	return 0;
}