/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Kitchen.cpp, implementation file for the Kitchen class.
*********************************************************************/

#include "Kitchen.hpp"
#include "Knife.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Kitchen::~Kitchen() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Kitchen::Kitchen() {

	spaceName = "Kitchen";
	spaceType = ROOM;

	// Spawn the knife.
	Item* knife = new Knife();
	items.insert(pair <ItemType, Item*>(KNIFE, knife));

	interactName = "lever";

	examined = false;
	locked = false;
	interactable = false;
	readable = false;
	itemUsed = false;
	takeableKey = false;
	keyTaken = false;
}

/*
*
*/
void Kitchen::link(Space* bathroom) {

	// Pointer to the bathroom to unlock it when the lever is pulled.
	bathroomPtr = bathroom;
}

/*
*
*/
void Kitchen::examine() {

	cout << "\nA grey and musty kitchen, filled with the overwhelming stench of rotten"
		<< "\nfood and rusted metals.";

	// Check if the knife is still in the room.
	if (items.find(KNIFE) != items.end()) {
	
		cout << "\n\nOn the center island sits a pristine Bewjeweled Knife.";
	}

	// Check if the statue is in use in the room.
	if (items.find(STATUE) != items.end()) {

		cout << "\n\nAlso on the other side of the room is a over-sized food scale"
			<< "\nwith the Marble Statue weighing it down on one side.";
	}
	else {
	
		cout << "\n\nAlso on the other side of the room is the source of the rotten smell;"
			<< "\nan unusually over-sized food scale filled with a moldy slop of what"
			<< "\nused to be food, dripping down the sides. I looks like if the bowl"
			<< "\nhad been stacked high with fresh food, then the scale may have been"
			<< "\nfully compressed.";
	}

	// Check if the lever has been revealed.
	if (interactable) {

		cout << "\n\nA level has also been revealed on the wall next to the"
			<< "\nthe food scale.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
void Kitchen::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou could place the Decorated Hairpin on the food scale, but it"
			<< "\nmight get lost in the goop and you don't have the time or the stomach"
			<< "\nto try to dig it out again."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nThis is where you first picked up the Bejeweled Knife, so you're"
			<< "\npretty sure nothing would happen if you simply put it back."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou place the Antique Lamp in the kitchen, the lights from the flames"
			<< "\nbouncing off the porcelain and metal cookware. Nothing really happens"
			<< "\nthough and you don't see anything additionally, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou take out the Ornate Pitcher and contemplate filling it with"
			<< "\nthe moldy slop, and then almost throw up at the thought and decide"
			<< "\nto put the pitcher away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou could place the Flawless Ruby on the food scale, but it"
			<< "\nmight get lost in the goop and you don't have the time or the stomach"
			<< "\nto try to dig it out again."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou take out he Ancient Spear, but there's nothing to use it on"
			<< "\nso you put it away again."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		// Check if the player has read the note
		if (player->hasRead(NOTE)) {

			cout << "\nYou place the Marble Statue on the food scale, completely"
				<< "\ncompressing it to one side.";

			// Check if this is the first time the player has placed the statue here.
			if (!itemUsed && !interactable) {

				cout << "\n\nYou hear a click and see a panel open up in front"
					<< "\nof the food scale with a lever rising to the surface!";

				// Indicate that the player can now interact with the room 
				// (i.e. pull the lever.).
				interactable = true;
				itemUsed = true;
			}
			// Otherwise nothing else should happen.
			else {

				cout << "\n\nHowever, the panel with the lever is already open,"
					<< "\nso nothing else happens.";
			}

			// Remove the item from the player's inventory.
			player->getInventory()->removeItem(STATUE);

			// Add it to the room.
			items.insert(pair <ItemType, Item*>(itemKey, item));
		}
		else {

			cout << "\nYou could put the Marble Statue on the food scale, but you're"
				<< "\nnot sure what that would accomplish besides covering the statue"
				<< "\nin moldy goo, so you'd rather not waste time.";
		}

		cout << "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou could pour some water on the food scale but all that would do"
			<< "\nis turn the moldy slop into a moldy soup, so you decide to save the"
			<< "\nwater in case you need it elsewhere."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Kitchen::interact() {

	// Check if this is the first time the lever is pressed.
	if (bathroomPtr->isLocked()) {

		cout << "\nYou pull the lever, and hear a rumbling noise inside the walls."
			<< "\n\nIt sounds like you hear a low grinding noise coming from the"
			<< "\nthe direction of the Grand Bathroom.";

		bathroomPtr->unlock();

		cout << "\n\nPress enter to continue...";
		getchar();
	}
	// Otherwise nothing should happen.
	else {

		cout << "\nYou pull the lever again, but nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();
	}

}