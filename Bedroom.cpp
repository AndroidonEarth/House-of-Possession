/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Bedroom.cpp, implementation file for the Bedroom class.
*********************************************************************/

#include "Bedroom.hpp"
#include "Hairpin.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Bedroom::~Bedroom() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Bedroom::Bedroom() {

	spaceName = "Bedroom";
	spaceType = ROOM;

	// Spawn the hairpin.
	Item* hairpin = new Hairpin();
	items.insert(pair <ItemType, Item*>(HAIRPIN, hairpin));

	lockDesc = "\nA massive decorated door blocks your way, but the strangest";
	lockDesc += "\naspect of it is that there doesn't seem to be a keyhole, doorknob,";
	lockDesc += "\nor any other sort of way to open it.";
	lockDesc += "\n\nFrom the design it looks like this might be the master bedroom.";

	keyName = "gold key";

	examined = false;
	locked = true;
	interactable = false;
	readable = false;
	itemUsed = false;
	takeableKey = false;
	keyTaken = false;
}

/*
*
*/
void Bedroom::examine() {

	cout << "\nThe master bedroom of Ms. Greyhardt herself, filled to the brim"
		<< "\nwith every kind of clothing item and piece of jewelry imaginable.";

	// Check if the hairpin is still in the room.
	if (items.find(HAIRPIN) != items.end()) {

		cout << "\n\nOn the vanity you see a pile of accessories including a"
			<< "Decorated Hairpin.";
	}
	
	cout << "\n\nAlso, next to the vanity is a manequin head, wearing a golden"
		<< "\nnecklace larger and more lavish than every other piece of jewelry"
		<< "\nin the room.";
	
	// Check if the ruby has been used.
	if (itemUsed) {
	
		cout << "\nIn the center of the necklace sits the Flawless Ruby,"
			<< "\nwhich opened the locked drawer of the vanity.";

		takeableKey = true;

		// Check if the key has been taken yet.
		if (!keyTaken) {

			cout << "\nThe contents of the drawer are revealed to be none other"
				<< "\nthan the golden key.";
		}
	}
	// Other wise print the default description of the room.
	else {

		cout << "\nHowever, it appears to be missing something very large"
			<< "\nright in the center of the necklace.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
void Bedroom::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nThis is where you first picked up the Decorated Hairpin,"
			<< "\nso nothing would happen if you put it back. You decide to keep it."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou try to pry open the drawer of the vanity with the Bejeweled"
			<< "\nKnife, but it's locked too tightly."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou could simply light the vanity on fire with the Antique Lamp"
			<< "\nbut that might light the whole room on fire and then you would be"
			<< "\ntrapped in a burning room."
			<< "\n\nYou feel it wise not to try this."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou try to break open the vanity with the Ornate Pitcher,"
			<< "\nbut the vanity is too sturdy and you only hurt your hand."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou slide the Flawless Ruby into the empty slot of the gold"
			<< "\nnecklace, and it locks firmly into place."
			<< "\n\nIt sounds like you hear the drawer of the vanity unlock!";

		itemUsed = true;

		// Remove the ruby from the player's inventory and destroy it.
		player->getInventory()->removeItem(itemKey);
		delete item;

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou take out the spear, but there's nothing in here to use it"
			<< "\non, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou put the Marble Statue on the vanity, and while it looks nice"
			<< "\nnothing happens, so you put it back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou take out the filled Ornate Pitcher and pour a little water"
			<< "\non the manqeuin, but nothing happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Bedroom::unlock(ItemType itemKey, Item* item, Player* player) {

	cout << "\nThe door is pretty solid, and doesn't budge no matter"
		<< "\nwhat item you try to use."
		<< "\n\nThere must be a different way of opening it."
		<< "\n\nPress enter to continue...";
	getchar();
}