/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Trophyroom.cpp, implementation file for the Trophyroom class.
*********************************************************************/

#include "Trophyroom.hpp"
#include "Spear.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Trophyroom::~Trophyroom() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
* 
*/
Trophyroom::Trophyroom() {

	spaceName = "Trophyroom";
	spaceType = ROOM;

	// Spawn the spear.
	Item* spear = new Spear();
	items.insert(pair <ItemType, Item*>(SPEAR, spear));

	interactName = "trophies";

	lockDesc = "\nThere's a fancy-looking door, with a unique looking doorknob and";
	lockDesc += "\nkeyhole. However, the doorknob doesn't turn, as it appears there";
	lockDesc += "\nis something wedged in the keyhole preventing it from turning.";

	readableName = "note";

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
void Trophyroom::link(Space* library) {

	// Pointer to the bedroom to unlock it when the button is pressed.
	libraryPtr = library;
}

/*
*
*/
void Trophyroom::examine() {

	cout << "\nIt appears to have been a Trophyroom filled with all kinds of ancient"
		<< "\nand valuable trophies.";
	
	// Check if the trophies have been interacted with.
	if (!(libraryPtr->isLocked())) {

		cout << "\nThe numerous trophies that once lay scattered on the ground"
			<< "\nhave now been neatly placed back into their proper positions.";
	}
	else {
		cout <<	"\nWhile they used to all be placed on the wall, "
			<< "\nmost of them now lay scattered on the floor.";
	}

	// Check if the spear is still in the room.
	if (items.find(SPEAR) != items.end()) {
	
		cout << "\n\nThe exception to this is an Ancient Spear,"
			<< "\nstill resting in the center of the wall.";
	}

	cout << "\n\nAlso, on the table appears to be a hastily scribbled note.";

	readable = true;
	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
ReadType Trophyroom::read() {

	cout << "\n\nYou read the note, and it seems like a kind of decree to the kitchen staff"
		<< "\ndemanding that the food scale must always remain full, and if the weight"
		<< "\never drops below a certain threshold then the kitchen staff will be hung."
		<< "\n\nYou're puzzled as to why someone would demand that of them, but you make"
		<< "\na mental note of it.";

	cout << "\n\nPress enter to continue...";
	getchar();

	return NOTE;
}

/*
*
*/
void Trophyroom::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case PITCHER:

		cout << "\nYou put the Ornate Pitcher up on wall with the trophies."
			<< "\nIt doesn't really fit in though and nothing happens, so you take"
			<< "\nit back down and put it in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou put the Flawless Ruby on the wall with the trophies."
			<< "\nBut nothing happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nThis is where you first picked up the Ancient Spear, so you're"
			<< "\nnot sure what good would come from putting it back."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou try to put the Marble Statue up on the wall but it's so heavy"
			<< "\nyou're afraid it make break the trophy platforms, so you put it back"
			<< "\nin your inventory."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou're not thirsty and there's nothing to water in here, so you"
			<< "\nstand there for a moment holding the filled Ornate Pitcher before"
			<< "\nyou put it back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Trophyroom::unlock(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou slide the Decorated Hairpin into the lock and hear something"
			<< "\nfall out on the otherside!"
			<< "\n\nAs you slide the hairpin back out it snags and snaps in two"
			<< "\nso you discard it. But it seems like the doorknob will still turn"
			<< "\nnow.";

		locked = false;

		player->getInventory()->removeItem(itemKey);
		delete item;

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou try to use the Bejeweled Knife to pick the lock of the door"
			<< "\nbut the knife is too large."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou could try to burn the door down with the Antique Lamp, but"
			<< "\nthat might also burn down whatever contents are inside, so you"
			<< "\ndecide not to do that."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou try smashing the doorknob with the Ornate Pitcher, but the knob"
			<< "\nis made of solid metal and you don't even make a dent."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou try pushing the Flawless Ruby through the lock to dislodge it,"
			<< "\nbut then the ruby might get stuck too and you would be back at square"
			<< "\none, so you put the ruby back into your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou could try to smash the doorknob with the Marble Statue, but if"
			<< "\nyou break the doorknob and it still doesn't open then you're afraid"
			<< "\nyou'll never be able to get it open, so you decide to try and find"
			<< "\na different way to simply unlock it instead."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou could try to pour some water on it to rust it and then maybe"
			<< "\nthe lock could simply be broken, but you don't have that many days"
			<< "\nto wait for it to rust."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Trophyroom::interact() {

	if (libraryPtr->isLocked()) {

		cout << "\nYou place the trophies back onto the wall the way they're pictured"
			<< "\nin the charred photograph, and you hear gears begin to turn in the"
			<< "\nwalls, followed by a thunk and click."
			<< "\n\nIt sounds like you hear another clicking noise coming from the"
			<< "\ndirection of the library!";

		libraryPtr->unlock();

		cout << "\n\nPress enter to continue...";
		getchar();
	}
	else {

		cout << "\nThe trophies have already been placed back on the wall, so"
			<< "\nthere's nothing else to interact with in here."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}