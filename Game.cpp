/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Game.cpp, implementation file for the Game class.
*********************************************************************/

#include "Game.hpp"
#include "House.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::advance;

/*
* 
*/
Game::Game() {

	// Create the house.
	house = new House();

	// Create the player.
	Location playerLoc;
	playerLoc.col = 4;
	playerLoc.row = 4;
	Space* playerSpace = house->getSpace(playerLoc.col, playerLoc.row);
	player = new Player(playerLoc, playerSpace);

	// Create the ghost.
	Location ghostLoc;
	ghostLoc.col = 0;
	ghostLoc.row = 0;
	Space* ghostSpace = house->getSpace(ghostLoc.col, ghostLoc.row);
	ghost = new Ghost(ghostLoc, ghostSpace, player);

	// Initialize game over flag.
	gameOver = false;
	gameWon = false;
}

/*
* 
*/
Game::~Game() {

	// Deallocate memory.
	delete house;
	delete player;
	delete ghost;
}

/*
* Displays the introduction lore, and then starts the game by printing the screen
* and calling update, and continues to do this until the game is over.
*/
void Game::runGame() {

	// Display the intro to the game.
	displayIntro();

	// Display the initial screen.
	printScreen();

	while (!gameOver) {

		// Execute one time step (movement, item gain, or item use).
		update();
	}

	// Display the game result.
	if (gameWon) {

		cout << "\n\n\nYOU WIN!";
	}
	else {

		cout << "\n\n\nGAME OVER!";
	}
}

/*
* Executes one time step of the game.
*/
void Game::update() {

	char selection;
	int convertedSelection;
	Direction dir;
	Space* playerRoom;

	selection = getMenuChoice(actionSelectMenu(player->getCurrRoom()));

	// If a dynamic menu option was selected, change to corresponding switch case.
	if (selection > '3') {

		handleExtraOptions(selection);
	}

	// Handle menu selection.
	switch (selection) {

	// Option 1) Move was selected.
	case '1':

		// Get the direction the player wants to move.
		dir = getMoveDir();

		// Check if the player will be able to move in that direction.
		if (player->canMove(dir)) {

			// If so attempt to move the ghost first if its able to.
			if (ghost->move()) {

				cout << "\nMs. Greyhardt moves first!"
					<< "\n\nPress enter to continue...";
				getchar();

				// Update the screen if the ghost moved.
				printScreen();

				cout << "\nPress enter to continue...";
				getchar();

				// Check if ghost's move causes the player to take damage.
				if (ghost->getCurrRoom() == player->getCurrRoom()) {

					cout << "\nMs. Greyhardt attacks and takes a piece of your soul!!"
						<< "\n\nPress enter to continue...";
					getchar();
					player->decHealth();

					// Update the screen if the player took damage.
					printScreen();

					cout << "\nPress enter to continue...";
					getchar();
				}
			}

			// If the player didn't die, execute the player's chosen movement.
			if (player->getHealth() > 0) {

				player->move(dir);
				ghost->incCounters();

				// Print the new screen after the player moves.
				printScreen();

				// Check if player's move causes the player to take damage.
				if (ghost->getCurrRoom() == player->getCurrRoom()) {

					cout << "\nPress enter to continue...";
					getchar();

					cout << "\nMs. Greyhardt attacks and takes a piece of your soul!!"
						<< "\n\nPress enter to continue...";
					getchar();

					player->decHealth();

					// Update the screen if the player took damage.
					printScreen();
					
					cout << "\nPress enter to continue...";
					getchar();
				}
			}
			
			// If the player did not die from the attack check if the player
			// reached the entryway with all three keys to win.
			if (player->getHealth() > 0 
				&& player->getKeys() == 3 
				&& player->getCurrRoom()->getName() == "Entryway") {

				displayWinMessage();
				gameOver = true;
				gameWon = true;
			}
			// If the player died, set the game over flag.
			else if (player->getHealth() == 0) {

				cout << "\nYOU HAVE DIED!"
					<< "\n\nPress enter to continue...";
				getchar();

				gameOver = true;
			}
		}
		// If the player cannot move, reprint the screen after stating why.
		else {

			printScreen();
		}
		break;

	// Option 2) Use item was selected.
	case '2':

		// If the player doesn't have any items to use, indicate so.
		if (player->getItemCount() == 0) {

			cout << "\nYou don't have any items to use!"
				<< "\n\nPress enter to continue...";
			getchar();
		}
		else {

			playerRoom = player->getCurrRoom();

			// Get which item the player wants to use.
			selection = getMenuChoice(useItemMenu(player->getInventory()));

			// Convert the selection to an integer in zero scale.
			convertedSelection = selection - '0';
			convertedSelection--;

			// Get an iterator to the player's items.
			auto iter = player->getInventory()->getBeginIter();

			// Advance by the 'i-th' selection.
			advance(iter, convertedSelection);

			playerRoom->useItem(iter->first, iter->second, player);	
		}

		// Print the screen before getting the next action.
		printScreen();
		break;

	// Option 3) Examine was selected.
	case '3':

		playerRoom = player->getCurrRoom();

		// Check if the player has potential items to examine.
		if (player->getItemCount() != 0) {

			// Display examine menu.
			selection = getMenuChoice(examineMenu());

			// If Option 1) Examine an item is selected.
			if (selection == '1') {

				selection = getMenuChoice(examineItemMenu(player->getInventory()));

				// Convert the selection to an integer in zero scale.
				convertedSelection = selection - '0';
				convertedSelection--;

				// Get an iterator to the player's items.
				auto iter = player->getInventory()->getBeginIter();

				// Advance by the 'i-th' selection.
				advance(iter, convertedSelection);

				// Examine the item at the 'i-th' selection.
				iter->second->examine();
			}
			// Otherwise if Option 2) Examine the room is selected.
			else if (selection == '2') {

				playerRoom->examine();
			}
		}
		// Otherwise just examine the room.
		else {

			playerRoom->examine();
		}

		// Print the screen before getting the next action.
		printScreen();
		break;

	// Read option was selected.
	case '4':

		// Display the text of the readable item in the room and pass type to the
		// player to update their knowledge.
		player->read(player->getCurrRoom()->read());

		// Print the screen before getting the next action.
		printScreen();
		break;

	// Interact option was selected.
	case '5':

		player->getCurrRoom()->interact();

		// Print the screen before getting the next action.
		printScreen();
		break;

	// Take option was selected.
	case '6':

		playerRoom = player->getCurrRoom();
		auto iter = playerRoom->getBeginIter();

		// Check if there is only one item in the room to take.
		if (playerRoom->getItemCount() == 1) {

			// Pass the item key and pointer for the player to take.
			player->takeItem(iter->first, iter->second);
		}
		// Or if there are no items but there is a key that can be taken
		// then the player selected to take the key.
		else if (playerRoom->getItemCount() == 0) {

			playerRoom->takeKey(player);
		}
		// Otherwise if there is more than one item and maybe a key, 
		// let the player select which to take.
		else {

			selection = getMenuChoice(takeItemMenu(playerRoom));
			
			// Convert the selection to an integer.
			convertedSelection = selection - '0';
			convertedSelection--;

			// Advanced the iterator by the 'i-th' selection converted to zero scale.
			advance(iter, convertedSelection);

			// If the iterator advanced passed the end of available items
			// then the player selected to take a key instead.
			if (iter == playerRoom->getEndIter()) {

				playerRoom->takeKey(player);
			}
			else {

				// Have the player take the item at the 'i-th' selection.
				player->takeItem(iter->first, iter->second);
			}
		}

		// Print the screen before getting the next action.
		printScreen();
		break;
	}
}

/*
* 
*/
Direction Game::getMoveDir() {

	char selection = getMenuChoice(dirSelectMenu());

	switch (selection) {

	// Option 1) North was selected.
	case '1':
		return UP;
		break;
	// Option 2) East was selected.
	case'2':
		return RIGHT;
		break;
	// Option 3) South was selected.
	case '3':
		return DOWN;
		break;
	// Option 4) West was selected.
	case '4':
		return LEFT;
		break;
	}
}

/*
* Handle the various combinations of different extra menu options and change to
* "correct" menu selection to execute the appropriate action.
*/
void Game::handleExtraOptions(char& selection) {

	Space* currRoom = player->getCurrRoom();

	// Option 4) interact was selected.
	if (!(currRoom->hasReadable()) && currRoom->hasInteractable() && selection == '4') {

		// Change to true interact option.
		selection = '5';
	}
	// Option 4) take was selected.
	else if (!(currRoom->hasReadable()) && !(currRoom->hasInteractable()) && selection == '4') {

		// Change to true take option.
		selection = '6';
	}
	// Option 5) take was selected.
	else if ((!(currRoom->hasReadable()) || !(currRoom->hasInteractable())) && selection == '5') {

		// Change to to true take option.
		selection = '6';
	}

}

/*
*
*/
void Game::printScreen() {

	int ghostCol = ghost->getCoords().col;
	int ghostRow = ghost->getCoords().row;
	int playerCol = player->getCoords().col;
	int playerRow = player->getCoords().row;

	auto invIter = player->getInventory()->getBeginIter();
	auto invEnd = player->getInventory()->getEndIter();

	// Print the top border.
	cout << '\n';
	for (int i = 0; i < 22; i++) {
		cout << "-";
	}
	cout << endl;

	/*****************
	** First row
	*****************/

	// Check if the ghost is in the Study.
	if (ghostCol == 0 && ghostRow == 0) {

		cout << "| #  |";
	}
	else {

		cout << "|    |";
	}

	// Check if the ghost is in the first Hallway.
	if (ghostCol == 1 && ghostRow == 0) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Bedroom.
	if (ghostCol == 2 && ghostRow == 0) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Check if the ghost is in the second Hallway.
	if (ghostCol == 3 && ghostRow == 0) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Trophyroom.
	if (ghostCol == 4 && ghostRow == 0) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Print player's health.
	cout << "  Health: " << player->getHealth() << "/3" << endl;

	/*****************
	** Second row
	*****************/

	// Check if the player is in the Study.
	if (playerCol == 0 && playerRow == 0) {

		cout << "|  @ | ";
	}
	else {

		cout << "|    | ";
	}

	// Check if the player is in the first Hallway.
	if (playerCol == 1 && playerRow == 0) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Bedroom.
	if (playerCol == 2 && playerRow == 0) {

		cout << "@ | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the player is in the second Hallway.
	if (playerCol == 3 && playerRow == 0) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Trophyroom.
	if (playerCol == 4 && playerRow == 0) {

		cout << "@ |";
	}
	else {

		cout << "  |";
	}

	// Print the player's keys.
	cout << "    Keys: " << player->getKeys() << "/3" << endl;

	/*****************
	** Third row
	*****************/

	// Print the walls.
	cout << "------  ------  ------" << endl;

	/*****************
	** Fourth row
	*****************/

	// Check if the ghost is in the first Hallway.
	if (ghostCol == 0 && ghostRow == 1) {

		cout << "| #";
	}
	else {

		cout << "|  ";
	}

	// Check if the player is in the first Hallway.
	if (playerCol == 0 && playerRow == 1) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the second Hallway.
	if (ghostCol == 1 && ghostRow == 1) {

		cout << "#";
	}
	else {
		
		cout << " ";
	}

	// Check if the player is in the second Hallway.
	if (playerCol == 1 && playerRow == 1) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the third Hallway.
	if (ghostCol == 2 && ghostRow == 1) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the third Hallway.
	if (playerCol == 2 && playerRow == 1) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the fourth Hallway.
	if (ghostCol == 3 && ghostRow == 1) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the fourth Hallway.
	if (playerCol == 3 && playerRow == 1) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the fifth Hallway.
	if (ghostCol == 4 && ghostRow == 1) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the fifth Hallway.
	if (playerCol == 4 && playerRow == 1) {

		cout << "@ |";
	}
	else {

		cout << "  |";
	}

	// Print the player's item count.
	cout << "   Items: " << player->getItemCount() << "/3" << endl;

	/*****************
	** Fifth row
	*****************/

	// Print the walls.
	cout << "------  ------  ------";

	// Print the Inventory separator.
	cout << "   -----------" << endl;

	/*****************
	** Sixth row
	*****************/

	// Check if the ghost is in the Library.
	if (ghostCol == 0 && ghostRow == 2) {

		cout << "| #  |";
	}
	else {

		cout << "|    |";
	}

	// Check if the ghost is in the first Hallway.
	if (ghostCol == 1 && ghostRow == 2) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Kitchen.
	if (ghostCol == 2 && ghostRow == 2) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Check if the ghost is in the second Hallway.
	if (ghostCol == 3 && ghostRow == 2) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Diningroom.
	if (ghostCol == 4 && ghostRow == 2) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Print player's first item if they have one.
	if (invIter != invEnd) {

		cout << "   " << invIter->second->getItemName();
		invIter++;
	}
	cout << endl;

	/*****************
	** Seventh row
	*****************/

	// Check if the player is in the Library.
	if (playerCol == 0 && playerRow == 2) {

		cout << "|  @ | ";
	}
	else {

		cout << "|    | ";
	}

	// Check if the player is in the first Hallway.
	if (playerCol == 1 && playerRow == 2) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Kitchen.
	if (playerCol == 2 && playerRow == 2) {

		cout << "@ | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the player is in the second Hallway.
	if (playerCol == 3 && playerRow == 2) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Diningroom.
	if (playerCol == 4 && playerRow == 2) {

		cout << "@ |";
	}
	else {

		cout << "  |";
	}

	// Print the Player's second item if they have one.
	if (invIter != invEnd) {

		cout << "   " << invIter->second->getItemName();
		invIter++;
	}
	cout << endl;

	/*****************
	** Eigth row
	*****************/

	// Print the walls.
	cout << "------  ------  ------";

	// Print the player's third item if they have one.
	if (invIter != invEnd) {

		cout << "   " << invIter->second->getItemName();;
		invIter++;
	}
	cout << endl;

	/*****************
	** Ninth row
	*****************/

	// Check if the ghost is in the first Hallway.
	if (ghostCol == 0 && ghostRow == 3) {

		cout << "| #";
	}
	else {

		cout << "|  ";
	}

	// Check if the player is in the first Hallway.
	if (playerCol == 0 && playerRow == 3) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the second Hallway.
	if (ghostCol == 1 && ghostRow == 3) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the second Hallway.
	if (playerCol == 1 && playerRow == 3) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the third Hallway.
	if (ghostCol == 2 && ghostRow == 3) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the third Hallway.
	if (playerCol == 2 && playerRow == 3) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the fourth Hallway.
	if (ghostCol == 3 && ghostRow == 3) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the fourth Hallway.
	if (playerCol == 3 && playerRow == 3) {

		cout << "@  ";
	}
	else {

		cout << "   ";
	}

	// Check if the ghost is in the fifth Hallway.
	if (ghostCol == 4 && ghostRow == 3) {

		cout << "#";
	}
	else {

		cout << " ";
	}

	// Check if the player is in the fifth Hallway.
	if (playerCol == 4 && playerRow == 3) {

		cout << "@ |" << endl;
	}
	else {

		cout << "  |" << endl;
	}

	/*****************
	** Tenth row
	*****************/

	// Print the walls.
	cout << "------  ------  ------";

	// Print the current room title.
	cout << "   Curr. Room:" << endl;

	/*****************
	** Eleventh row
	*****************/

	// Check if the ghost is in the Bathroom.
	if (ghostCol == 0 && ghostRow == 4) {

		cout << "| #  |";
	}
	else {

		cout << "|    |";
	}

	// Check if the ghost is in the first Hallway.
	if (ghostCol == 1 && ghostRow == 4) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Ballroom.
	if (ghostCol == 2 && ghostRow == 4) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Check if the ghost is in the second Hallway.
	if (ghostCol == 3 && ghostRow == 4) {

		cout << "# | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the ghost is in the Entryway.
	if (ghostCol == 4 && ghostRow == 4) {

		cout << "#  |";
	}
	else {

		cout << "   |";
	}

	// Print the current room title separator.
	cout << "   -----------" << endl;
	

	/*****************
	** Twelfth row
	*****************/

	// Check if the player is in the Bathroom.
	if (playerCol == 0 && playerRow == 4) {

		cout << "|  @ | ";
	}
	else {

		cout << "|    | ";
	}

	// Check if the player is in the first Hallway.
	if (playerCol == 1 && playerRow == 4) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Ballroom.
	if (playerCol == 2 && playerRow == 4) {

		cout << "@ | ";
	}
	else {

		cout << "  | ";
	}

	// Check if the player is in the second Hallway.
	if (playerCol == 3 && playerRow == 4) {

		cout << "@|  ";
	}
	else {

		cout << " |  ";
	}

	// Check if the player is in the Entryway.
	if (playerCol == 4 && playerRow == 4) {

		cout << "@ |";
	}
	else {

		cout << "  |";
	}

	// Print the player's current location.
	cout << "   " << player->getCurrRoom()->getName() << endl;

	/*****************
	** Thirteenth row
	*****************/

	// Print the bottom border.
	for (int i = 0; i < 22; i++) {
		cout << "-";
	}
	cout << endl;
}