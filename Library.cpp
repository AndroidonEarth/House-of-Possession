/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Library.cpp, implementation file for the Library class.
*********************************************************************/

#include "Library.hpp"

using std::cout;

Library::~Library() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Library::Library() {

	spaceName = "Library";
	spaceType = ROOM;

	lockDesc = "\nThere is a set of double doors with large bronze handles,";
	lockDesc += "\nbut the doors don't budge, and there doesn't appear to be";
	lockDesc += "\nany levers, locks, or keyholes to open them.";
	lockDesc += "\n\nYou peer through the cracks in the door to see what looks";
	lockDesc += "\nlike an old library inside.";

	readableName = "book";

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
void Library::examine() {

	cout << "\nA multistory library, full of iron spiraling staircases and the smell"
		<< "\nof old dusty books. As a professor this is a familiar sight and smell"
		<< "\nbut you know you don't have time to lose yourself in the vast knowledge"
		<< "\ncontained within."
		<< "\n\nThere are piles of normal looking books everywhere, but right in the center"
		<< "\nis one peculiar looking one; a large black tome resting on a pedestal,"
		<< "\nalready opened to a particular page.";

	readable = true;
	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
ReadType Library::read() {

	cout << "\nYou read the opened tome. It seems like this is a very, very old book"
		<< "\nfrom the original owner of the mansion, who predates even Ms. Greyhardt"
		<< "\nherself. It contains some foreign scriptures that look like they might"
		<< "\nbe some kind of spell or curse placed on whoever owns the book..."
		<< "\n\nThere is also information about the final secret of the mansion:"
		<< "\nthe inside the chandelabra of the ballroom might be the last piece"
		<< "\nof the puzzle to escape!";
	cout << "\n\nPress enter to continue...";
	getchar();

	return BOOK;
}

/*
*
*/
void Library::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case RUBY:

		cout << "\nThere's a large slot on the book that looks like it used to contain"
			<< "\nthe Flawless Ruby so you try to insert it back into the book,"
			<< "\nbut it won't stay and nothing seems to happen anyway."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nThere doesn't seem to be anything to use the Ancient Spear on"
			<< "\non in the library, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou're sure the Marble Statue could be an effective paperweight"
			<< "\nin here, but you might need it later so you decide to keep it."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Library::unlock(ItemType itemKey, Item* item, Player* player) {

	cout << "\nThe door is pretty solid, and doesn't budge no matter"
		<< "\nwhat item you try to use."
		<< "\n\nThere must be a different way of opening it."
		<< "\n\nPress enter to continue...";
	getchar();
}