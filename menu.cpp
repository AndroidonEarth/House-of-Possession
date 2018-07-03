/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: menu.cpp, implementation file the menu helper functions.
*********************************************************************/

#include "menu.hpp"
#include "Space.hpp"
#include "Inventory.hpp"

using std::cout;

/**
* Display the title screen of the game.
*/
void displayTitle() {

	cout << "\n\nWELCOME!\n\n"
		<< "To The House Of Possession!\n";
}


/**
* Display the first menu prompt. This is used at the start of the program
* after the introduction in order to prompt the user for their first selection.
*/
char mainMenu() {

	cout << "\n\nMAIN MENU\n\n"
		<< "1) Play game\n"
		<< "2) Quit\n\n";

	return '2';
}

/*
* Display the intro to the game. This is used after the game has started to
* display the introduction to the game and give the player backstory.
*/
void displayIntro() {

	cout << "\nYour name is Jonathan Drawde... a young professor who"
		<< "\nhas recently been informed that he has inherited a mansion"
		<< "\nfrom his long-lost, deceased Aunt Emily Greyhardt.\n";

	cout << "\nPress enter to continue...";
	getchar();

	cout << "\nYou arrive at the mansion to claim the deed to the estate,"
		<< "\nbut as you step inside the door mysteriously closes"
		<< "\nand locks behind him...\n";

	cout << "\nPress enter to continue...";
	getchar();

	cout << "\nUnbeknownst to Jonathan, Ms. Greyhardt was an obsessive collector"
		<< "\nof all kinds of rare and valuable items. Because of this,"
		<< "\nher ghost has been bound to the mortal world, unable to part"
		<< "\nfrom her prized belongings."
		<< "\n\nNow she seeks to defend her home from trespassers,"
		<< "\nand Jonathan must find a way to escape before she steals his soul"
		<< "\nand adds it to her collection of possessions...\n";

	cout << "\nPress enter to continue...";
	getchar();

	cout << "\nYou turn around to examine the door, noticing that there are three"
		<< "\ndeadbolts on the door. Maybe if you can find"
		<< "\nthe three corresponding KEYS, you can unlock the door and"
		<< "\nmake your escape...\n";

	cout << "\nPress enter to continue...";
	getchar();

	cout << "\nBut hurry, as the full moon rises Ms. Greyhardt's other-worldly"
		<< "\npowers grow stronger, and over time it will become more difficult to"
		<< "\nescape her fury!\n";

	cout << "\nPress enter to continue...";
	getchar();
}

/**
* 
*/
char actionSelectMenu(Space* room) {

	char numOfActions = '3';

	// List the basic available actions.
	cout << "\nSELECT AN OPTION"
		<< "\n1) Move"
		<< "\n2) Use item"
		<< "\n3) Examine";

	// If the room has already been examined, check for other dynamic menu options.
	if (room->hasBeenExamined()) {

		// Indicate if there is something the player can read in the room.
		if (room->hasReadable()) {

			numOfActions++;
			cout << "\n" << numOfActions << ") Read " << room->getReadableName();
		}

		// Indicate if there is something interactable in the room.
		if (room->hasInteractable()) {

			numOfActions++;
			cout << "\n" << numOfActions << ") Interact with " << room->getInteractName();
		}

		// Check if there is only one item in the room to take and no key to take.
		auto iter = room->getBeginIter();
		if (room->getItemCount() == 1 && !(room->canTakeKey())) {

			numOfActions++;
			cout << "\n" << numOfActions << ") Take " << iter->second->getItemName();
		}
		// Otherwise if there are no items but there is a key to take.
		else if (room->getItemCount() == 0 && room->canTakeKey() && !(room->keyHasBeenTaken())) {

			numOfActions++;
			cout << "\n" << numOfActions << ") Take " << room->getKeyName();
		}
		// Otherwise display a generic take option.
		else if (iter != room->getEndIter()) {

			numOfActions++;
			cout << "\n" << numOfActions << ") Take...";
		}
	}

	cout << "\n\n";

	// Return the number of possible actions for the player for validation.
	return numOfActions;
}

/*
* Does not validate if the inventory is empty or not - will only be called if
* the inventory object has at least 1 item.
*/
char useItemMenu(Inventory* inventory) {

	char numOfItems = '0';

	cout << "\n\nSELECT AN ITEM TO USE";

	// List the items in the inventory.
	auto iter = inventory->getBeginIter();
	while (iter != inventory->getEndIter()) {

		numOfItems++;
		cout << "\n" << numOfItems << ") Use " << iter->second->getItemName();
		iter++;
	}
	cout << "\n\n";

	// Return the total number of options for validation.
	return numOfItems;
}

/*
*
*/
char roomSelectMenu(Space* room1, Space* room2) {

	cout << "\n\nWHICH ROOM WOULD YOU LIKE TO USE THE ITEM ON?"
		<< "\n1) " << room1->getName()
		<< "\n2) " << room2->getName() << "\n\n";

	return '2';
}

/*
*
*/
char examineMenu() {

	cout << "\n\nWHAT WOULD LIKE TO EXAMINE?"
		<< "\n1) An item in your inventory"
		<< "\n2) The room you are in\n\n";

	return '2';
}

/*
*
*/
char examineItemMenu(Inventory* inventory) {

	char numOfItems = '0';

	cout << "\n\nSELECT AN ITEM TO EXAMINE";

	// List the items in the inventory.
	auto iter = inventory->getBeginIter();
	while (iter != inventory->getEndIter()) {

		numOfItems++;
		cout << "\n" << numOfItems << ") Examine " << iter->second->getItemName();
		iter++;
	}

	cout << "\n\n";

	// Return number of items in the inventory for validation.
	return numOfItems;
}

/*
*
*/
char takeItemMenu(Space* room) {

	char numOfItems = '0';

	cout << "\n\nSELECT AN ITEM TO TAKE";

	// List the items in the room that can be taken.
	auto iter = room->getBeginIter();
	while (iter != room->getEndIter()) {

		numOfItems++;
		cout << "\n" << numOfItems << ") Take " << iter->second->getItemName();
		iter++;
	}

	// Check if a key can be taken and if so list it too.
	if (room->canTakeKey() && !(room->keyHasBeenTaken())) {

		numOfItems++;
		cout << "\n" << numOfItems << ") Take " << room->getKeyName();
	}

	cout << "\n\n";

	// Return total number of items and keys in the room for validation.
	return numOfItems;
}

/*
*
*/
char dirSelectMenu() {

	cout << "\n\nSELECT A DIRECTION TO MOVE"
		<< "\n1) Up"
		<< "\n2) Right"
		<< "\n3) Down"
		<< "\n4) Left\n\n";

	return '4';
}

/*
*
*/
void displayWinMessage() {

	cout << "\n\nYou frantically reach the entryway with all three keys in hand, and"
		<< "\nunlock each deadbolt one-by-one with shaking hands, as you feel Ms. Greyhardt"
		<< "\napproaching fast to steal your soul...";

	cout << "\n\nPress enter to continue...";
	getchar();

	cout << "\n\nYou feel her ghostly breath down your neck as you unlock the last one."
		<< "\nThe heavy wooden door swings open and you make a break for it!";

	cout << "\n\nPress enter to continue...";
	getchar();

	cout << "\n\nYou reach the end of the courtyard, the moon shining bright overhead."
		<< "\nAs you open the gate to leave, you turn to look over your shoulder at the"
		<< "\nmansion one last time.";

	cout << "\n\nPress enter to continue...";
	getchar();

	cout << "\n\nThe last sight you see is the ghostly silhouette of Ms. Greyhardt standing in"
		<< "\nthe shadows of the doorway, her ominous glowing eyes staring at you- piercing"
		<< "\nyou with her rage and fury.";

	cout << "\n\nPress enter to continue...";
	getchar();

	cout << "\n\nYou vow to never return back here again.";

	cout << "\n\nPress enter to continue...";
	getchar();
}

/**
* Display the play again menu prompt.
*/
char playAgainMenu() {

	cout << "\n\nMAIN MENU\n\n"
		<< "1) Play again?\n"
		<< "2) Quit\n\n";

	return '2';
}

/**
* Display the outro to the program. This is used when the program is about to end
* to indicate so to the user.
*/
void displayOutro() {

	cout << "\nGame is exiting."
		<< "\n\nTHANK YOU FOR PLAYING!\n\n";
}