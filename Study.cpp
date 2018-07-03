/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Study.cpp, implementation file for the Study class.
*********************************************************************/

#include "Study.hpp"
#include "Lamp.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

Study::~Study() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Study::Study() {

	spaceName = "Study";
	spaceType = ROOM;

	// Spawn the lamp.
	Item* lamp = new Lamp();
	items.insert(pair <ItemType, Item*>(LAMP, lamp));

	lockDesc = "\nThere's pair of small, dusty wooden doors- their handles";
	lockDesc += "\nbound tightly together with some rope. You try but it's";
	lockDesc += "\nimpossible to untie the old rope.";

	readableName = "letter";

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
void Study::examine() {

	cout << "\nAn old dusty Study, littered with papers, inkwells, and covered"
		<< "\nin cobwebs. It doesn't look like the room was used much."
		<< "\n\nHowever, on the desk it looks like someone had been writing a letter.";

	readable = true;

	// Check if the lamp is still in the room.
	if (items.find(LAMP) != items.end()) {

		cout << "\n\nAlso, next to the letter glows an Antique Lamp, hightlighting"
			<< "\nthe cobwebs and the specks of dust floating through the air."
			<< "\nHow it has remained lit all this time you're unsure.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
* Display the text of whatever is readable in the room, and return the type of
* clue that was read.
*/
ReadType Study::read() {

	cout << "\nYou try to read the letter on the desk, and while most of it is too"
		<< "\nsmudged with ink, you can still make out some of the words."
		<< "\n\nIt sounds like it was a letter to the head interior decorator of the"
		<< "\nmansion, explaining that their employee that broke the vase in the"
		<< "\nEntryway was already executed, but if they do not replace the vase"
		<< "\nquickly then their head would be taken as well."
		<< "\n\nIt looks like they specifically mention that the replacement vase"
		<< "\nmust also be very heavy some reason.";

	cout << "\n\nPress enter to continue...";
	getchar();

	return LETTER;
}

/*
*
*/
void Study::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nThere doesn't seem to be anything in here to use the Decorated Hairpin"
			<< "\non so you put it back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nThis is where you first found the Antique Lamp so you're not sure"
			<< "\nwhat good it would do to put it back."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou place the Ornate Pitcher on the desk and stare at it for a little"
			<< "\nwhile before putting it back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nThere doesn't seem to be anything to use the Flawless Ruby on in here"
			<< "\nand it's so dusty in here you wouldn't want to get it dirty."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou use the Ancient Spear to clean up some of the cobwebs in the"
			<< "\nstudy. The spiders are probably angry but nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou place the Marble Statue on the desk. It's so dusty you see"
			<< "\nthe dust already settling on the statue, but nothing else happens."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou could use the water in the Ornate Pitcher to clean the dust from"
			<< "\nthe room, but you might need the water for later so you decide not to."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Study::unlock(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case KNIFE:

		cout << "\nYou use the Bejeweled Knife to slice right through the rope on the"
			<< "\ndoor. It takes a bit of sawing, and when you finally finish cutting"
			<< "\nit the knife handle gives out and breaks, but luckily the door is now"
			<< "\nunlocked for you.";

		locked = false;

		player->getInventory()->removeItem(itemKey);
		delete item;

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou're not really sure how an Ornate Pitcher is supposed to help"
			<< "\nundo the ropes, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}