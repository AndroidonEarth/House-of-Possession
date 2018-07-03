/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Entryway.cpp, implementation file for the Entryway class.
*********************************************************************/

#include "Entryway.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Entryway::~Entryway() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Entryway::Entryway() {

	spaceName = "Entryway";
	spaceType = ROOM;

	interactName = "button";

	examined = false;
	locked = false;
	readable = false;
	interactable = false;
	itemUsed = false;
	takeableKey = false;
	keyTaken = false;
}

/*
*
*/
void Entryway::link(Space* bedroom) {

	// Pointer to the bedroom to unlock it when the button is pressed.
	bedroomPtr = bedroom;
}

/*
*
*/
void Entryway::examine() {

	cout << "\nThe entryway where you first entered the mansion."
		<< "\nThe front door is locked by three sturdy-looking deadbolts.";
	
	// If the Statue is on the pedestal print a different message.
	if (items.find(STATUE) != items.end() && itemUsed) {
	
		cout << "\n\nThere are also some pedestals in here, but while two of them"
			<< "\nhave heavy looking vases on them, the third has the Marble Statue"
			<< "\nweighing it down, and pushing the pedestal slightly into the ground.";
	}
	// Otherwise, print the default description.
	else {

		cout << "\n\nThere are also some pedestals in here, but while two of them"
			<< "\nhave heavy looking vases on them, the third is empty and it's"
			<< "\nvase appears to have shattered on the floor.";
	}

	// If the button has been revealed, indicate so in the description.
	if (interactable) {

		cout << "\n\nA button has also appeared on the underside of the pedestal.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}


/*
*
*/
void Entryway::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou place the Decorated Hairpin on the pedestal,"
			<< "\nbut of course nothing happens."
			<< "\n\nYou question your sanity a little."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou place the Bejeweled Knife on the pedestal."
			<< "\nIt looks nice, but nothing happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou place the Antique Lamp on the pedestal."
			<< "\nThe room is certainly more lit up, but nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou place the Ornate Pitcher on the pedestal,"
			<< "\nbut its not heavy enough to push it down."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou place the Flawless Ruby on the pedestal, but of course"
			<< "\nnothing happens."
			<< "\n\nYou're not sure why you thought that would do anything."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou want to put the Ancient Spear on the pedestal,"
			<< "\nbut its way too large, and you wouldn't want to accidentally"
			<< "\nbreak the other two vases."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		// Check if the player has the knowledge to place the statue.
		if (player->hasRead(LETTER)) {

			cout << "\nYou place the Marble Statue on the pedestal, the weight of"
				<< "\nit pushes the pedestal into the ground.";

			// Check if this is the first time the player has placed the statue here.
			if (!itemUsed && !interactable) {

				cout << "\n\nYou hear a click and notice that a small panel has opened"
					<< "\non the underside of the pedestal. It looks like there is a"
					<< "\nbutton inside of it.";

				// Indicate that the player can now interact with the room 
				// (i.e. push the button).
				interactable = true;
				itemUsed = true;
			}
			// Otherwise nothing else should happen.
			else {

				cout << "\n\nHowever, the panel with the button is already open,"
					<< "\nso nothing else happens.";
			}

			// Remove the item from the player's inventory.
			player->getInventory()->removeItem(STATUE);

			// Add it to the room.
			items.insert(pair <ItemType, Item*>(itemKey, item));
		}
		// If the player has not read the letter yet.
		else {

			cout << "\nYou could put the Marble Statue up on the pedestal"
				<< "\nbut it would be difficult, and the statue doesn't really"
				<< "\nmatch the other vases so you're not sure why that would do"
				<< "\nanything in the first place.";
		}

		cout << "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou place the filled Ornate Pitcher on the pedestal,"
			<< "\nbut even with the water inside it, its still not heavy"
			<< "\nenough to weigh the pedestal down."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Entryway::interact() {

	// Check if this is the first time the lever is used.
	if (bedroomPtr->isLocked()) {
	
		cout << "\nYou push the button, and hear gears turning inside the walls."
			<< "\n\nIt sounds like you hear a clicking noise coming from the"
			<< "\nthe direction of the Master Bedroom.";

		bedroomPtr->unlock();

		cout << "\n\nPress enter to continue...";
		getchar();
	}
	// Otherwise nothing should happen.
	else {

		cout << "\nYou push the button again, but nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}