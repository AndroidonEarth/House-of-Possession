/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Bathroom.cpp, implementation file for the Bathroom class.
*********************************************************************/

#include "Bathroom.hpp"
#include "Ruby.hpp"
#include "Water.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

/*
* Destructor for the Ballroom class. Loops through the items in the room, and if there
* are any, deallocates the memory for the item objects.
*/
Bathroom::~Bathroom() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Bathroom::Bathroom() {

	spaceName = "Bathroom";
	spaceType = ROOM;
	
	// Spawn the ruby in the room.
	Item* ruby = new Ruby();
	items.insert(pair <ItemType, Item*>(RUBY, ruby));

	lockDesc = "\nThere's a heavy sliding door, but it doesn't budge no matter";
	lockDesc += "\nhow hard you pull, and there doesn't appear to be any keyholes";
	lockDesc += "\nor knobs to open it.";
	lockDesc += "\n\nThere's a narrow window of fogged glass in the top of the door";
	lockDesc += "\nand while it would be too small to crawl through, you can peer";
	lockDesc += "\nthrough it see what appears to be the grand bathing room.";

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
void Bathroom::examine() {

	cout << "\nIn the grand bathroom, most of the bathing pools are empty and"
		<< "\novergrown with thick weeds and foliage. However, in the middle"
		<< "\nof the room moonlight shines through a stained glass ceiling and"
		<< "\nreflects off the water of a single pool, filling the room with a"
		<< "\nkaleidoscope of shimmering colors.";

	// Check if the ruby is still in the room.
	if (items.find(RUBY) != items.end()) {
		
		cout << "\n\nAt the bottom of the pool, you also catch a glimpse of a red"
			<< "\nglimmering object, clearly distinct from the myriad of colors"
			<< "\naround you.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
void Bathroom::useItem(ItemType itemKey, Item* item, Player* player) {

	Item* water;

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou could throw the Decorated Hairpin in the pool of water,"
			<< "\nbut it would be difficult to get back out so you decide against"
			<< "\ndoing this."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou take out the Bejeweled Knife, but realize there is nothing"
			<< "\nto use it on in here so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou take out the Antique Lamp, but you wouldn't want to put it"
			<< "\nin the pool of water or else it would be extinguished, and you're"
			<< "\nnot sure you would be able to light it again."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou dunk the Ornate Pitcher in the pool of water and fill it to"
			<< "\nthe brim with the mossy, dirty water.";

		// Remove the pitcher from the player's inventory and destroy it.
		player->getInventory()->removeItem(itemKey);
		delete item;

		cout << "\n";

		// Give the player a new filled pitcher of water.
		water = new Water();
		player->getInventory()->addItem(WATER, water);

		break;
	case RUBY:

		cout << "\nThis is where you found Flawless Ruby in the first place,"
			<< "\nso there's no point in throwing it back in the water."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou stick the Ancient Spear in the water and swirl it around,"
			<< "\npretending to be a witch stirring her couldron."
			<< "\n\n...But nothing happens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou take out the Marble Statue, and while you could throw it"
			<< "\nin the water and create a big splash, you decide to keep it instead."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nThe Ornate Pitcher is already full, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
*
*/
void Bathroom::unlock(ItemType itemKey, Item* item, Player* player) {

	cout << "\nThe door is pretty solid, and doesn't budge no matter"
		<< "\nwhat item you try to use."
		<< "\n\nThere must be a different way of opening it."
		<< "\n\nPress enter to continue...";
	getchar();
}