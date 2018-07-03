/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Diningroom.cpp, implementation file for the Diningroom class.
*********************************************************************/

#include "Diningroom.hpp"
#include "Pitcher.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Diningroom::~Diningroom() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Diningroom::Diningroom() {

	spaceName = "Diningroom";
	spaceType = ROOM;

	// Spawn the pitcher.
	Item* pitcher = new Pitcher();
	items.insert(pair <ItemType, Item*>(PITCHER, pitcher));

	readableName = "photo";
	keyName = "bronze key";

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
void Diningroom::link(Space* trophyroom) {

	trophyroomPtr = trophyroom;
}

/*
*
*/
void Diningroom::examine() {

	cout << "\nA gradiose dining table sits in the middle with a dozen sets"
		<< "\nof fine china and golden utensils neatly arranged, as if awaiting"
		<< "\na communion of guests that never occured.";

	// Check if the pitcher of water has been used in the room.
	if (itemUsed) {

		takeableKey = true;

		// Check if the key has been taken.
		if (!keyTaken) {

			cout << "\n\nNow that the fire in the fireplace has been extinguished"
				<< "\nyou spot a Bronze Key resting in the back corner.";
		}

		cout << "\n\nThere's also a charred photograph half burried in the ashes"
			<< "\nof the fireplace.";

		readable = true;
		
	}
	// Otherwise print the default description of the room.
	else {

		cout << "\n\nA fire rages in the nearby fireplace, and you spot something"
			<< "\nglimmering behind the flames just out of reach.";
	}

	// Check if the pitcher is still in the room.
	if (items.find(PITCHER) != items.end()) {

		cout << "\n\nFinally, in the center of the table is a dusty but"
			<< "\nOrnate Pitcher, it's contents now evaporated.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
ReadType Diningroom::read() {

	cout << "\nYou take a look at the charred photograph... It appears to be a photo"
		<< "\nof the Trophyroom. In particular the wall containing all the trophies,"
		<< "\nperhaps indicating the original positions of all the trophies.";

	trophyroomPtr->setInteractable();

	cout << "\n\nPress enter to continue...";
	getchar();
	return PHOTO;
}

/*
*
*/
void Diningroom::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou take out the Decorated Hairpin, but there's nothing to use it"
			<< "\nit on so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou take out the Bejeweled Knife but it's much too large to be used"
			<< "\nas a dinner utensil, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou put the Antique Lamp on the table. It makes a nice center piece"
			<< "\nbut nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nThis is where you first got the Ornate Pitcher so nothing would"
			<< "\nhappen now if you put it back. You decide to keep it."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou take out the Flawless Ruby but nothing happens so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou take out the Ancient Spear but there's nothing in here to use it"
			<< "\non so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou put the Marble Statue above the fireplace. Nothing happens."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou pour the dirty water over the fire and extinguish it!"
			<< "\n\nYou're not sure what else you would need the empty pitcher for now,"
			<< "\nso you discard it.";

		player->getInventory()->removeItem(itemKey);
		delete item;

		itemUsed = true;

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	}
}