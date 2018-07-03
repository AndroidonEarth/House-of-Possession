/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ballroom.cpp, implementation file for the Ballroom class.
*********************************************************************/

#include "Ballroom.hpp"
#include "Statue.hpp"
#include "Player.hpp"

using std::cout;
using std::pair;

/*
* Destructor for the Ballroom class. Loops through the items in the room, and if there
* are any, deallocates the memory for the item objects.
*/
Ballroom::~Ballroom() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
* Constructor for the Ballroom class. Initializes the data member variables
* relevant to the specific room.
*/
Ballroom::Ballroom() {

	spaceName = "Ballroom";
	spaceType = ROOM;

	Item* statue = new Statue();
	items.insert(pair <ItemType, Item*>(STATUE, statue));

	lockDesc = "\nThe doorway is open, but it's covered with thick vines and";
	lockDesc += "\nbranches that have sprouted up through the floor somehow.";
	lockDesc += "\nThey're too tough to push past or break, but they're dry";
	lockDesc += "\nand brittle from old age.";

	readableName = "painting";
	keyName = "brass key";

	examined = false;
	locked = true;
	readable = false;
	interactable = false;
	itemUsed = false;
	takeableKey = false;
	keyTaken = false;
}

/*
* examine functions, used when the user examines the room to dynamically
* display a description of the room based on the status flags and contents of the room.
* Sets other status flags to indicate the room has been examined as well as
* whatever the user finds in the room.
*/
void Ballroom::examine() {

	cout << "\nA grand ballroom decorated in brilliant yellows and golds, now covered in"
		<< "\na thick layer of dust, but otherwise exactly as it was left since it's"
		<< "\nlast party that it held."
		<< "\n\nA massive painting adorns the back wall.";

	readable = true;

	// Check if the statue is still in the room.
	if (items.find(STATUE) != items.end()) {

		cout << "\nNext to the painting is also a heavy Marble Statue in the"
			<< "\nlikeness of Ms. Greyhardt herself.";
	}

	// Check if the spear has been used to knock down the chandelabra.
	if (itemUsed) {
	
		cout << "\n\nThe chandelabra lies broken on the floor, bits and pieces of"
			<< "\nmetal, glass, and wax scattered about.";

		takeableKey = true;

		// Check if the key has been taken yet.
		if (!keyTaken) {

			cout << "\nIn the middle of the rubble you spot the final key:"
				<< "\nthe Brass Key!";
		}
	}
	// Otherwise print the default description.
	else {

		cout << "\n\nFinally a fantastically elaborate chandelabra dangles from the ceiling,"
			<< "\nthe chain holding it now rusted and fragile.";
	}

	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
* read functions, displays a description of whatever is readable in the room, and
* returns the ReadType of the text so the player can make a note of it in their
* knowledge banks.
*/
ReadType Ballroom::read() {

	cout << "\nYou look at the painting on the back wall to see none other than"
		<< "\nMs. Greyhardt peering down at you with eyes that seem creepily alive."
		<< "\n\nAround her neck is a gold necklace, in the center of which is a"
		<< "\nmassive ruby, clear intending to relay a message about herself."
		<< "\n\nYou're not sure how anyone could have enjoyed themselves dancing here.";

	cout << "\n\nPress enter to continue...";
	getchar();

	return PAINTING;
}

/*
* useItem functions. Takes an ItemType, and pointers to an Item and Player object.
* Prints a different result depending on the type of object used, and if the correct one
* is used then a special message is displayed, the item is removed from the
* player's inventory and/or deleted, and status flags of the room are changed.
*/
void Ballroom::useItem(ItemType itemKey, Item* item, Player* player) {

	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou take out the Decorated Hairpin... but then realize how"
			<< "\nsilly you feel and put back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou take out the Bejeweled Knife, but the chandelabra is still"
			<< "\ntoo high, and there doesn't seem to be anything else to use it on."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou take out the Antique Lamp. The increased light gives you a"
			<< "\nbetter view of the room, but you don't notice anything new of"
			<< "\nnoteworthy."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou take out the Ornate Pitcher, but there is nothing to use it"
			<< "\non, and nowhere to set it so you put away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou take out the Flawless Ruby, and notice that it happens to look"
			<< "\nremarkably similar to the one on the necklace of the painting!"
			<< "\n\nNow if only you could find where it goes..."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		if (player->hasRead(BOOK)) {

			cout << "\nYou use the Ancient Spear to give the chandelabra a good whack-"
				<< "\nshattering the spear in the process, but snapping the rusted chain"
				<< "\nof the chandelabra and sending it crashing to the ground!";

			itemUsed = true;

			// Remove the spear from the player's inventory and delete it from the game.
			player->getInventory()->removeItem(itemKey);
			delete item;
		}
		else {

			cout << "\nYou take the Ancient Spear out, but you're not sure what to do"
				<< "\nwith it. You could hit the chandelabra but you might break the"
				<< "\nspear in the process and you don't know if you should risk it.";
		}

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou take the Marble Statue out, but this is where you first found"
			<< "\nit, so you're not sure what good it would do to put it back."
			<< "\n\nYou decide to keep it and put it back in your inventory."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou take out the filled Ornate Pitcher, but you're not thirsty and"
			<< "\nand you wouldn't want to waste the water, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}

/*
* unlock function. 
*/
void Ballroom::unlock(ItemType itemKey, Item* item, Player* player) {


	// Print a different result depending on what item is used.
	switch (itemKey) {

	case HAIRPIN:

		cout << "\nYou poke the vines and branches with the Decorated Hairpin,"
			<< "\nbut you're not sure why you did that as nothing happened."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case KNIFE:

		cout << "\nYou take out the Bejeweled Knife, and while you could try cutting"
			<< "\nthe vines and branches, the branches seem much too dense..."
			<< "\n\nIt is only a knife after all, not a machete."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case LAMP:

		cout << "\nYou throw the Antique Lamp at the vines and branches, and the"
			<< "\ndry bark immediately catches fire. Eventually the flames die"
			<< "\ndie down and branches crumble to ash, opening the doorway!";

		locked = false;

		// Remove the lamp from the player's inventory and destroy it.
		player->getInventory()->removeItem(itemKey);
		delete item;

		cout << "\n\nPress enter to continue...";
		getchar();
		break;
	case PITCHER:

		cout << "\nYou take out the Ornate Pitcher and use it to bang on the branches,"
			<< "\nbut they're much too dense and you only scratch up your pitcher."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case RUBY:

		cout << "\nYou hold the Flawless Ruby up and recite a prayer you once read"
			<< "\nin a novel, hoping the branches will magically part the way..."
			<< "\n\nToo bad this is reality and not a fantasy novel, as nothing."
			<< "\nhappens."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case SPEAR:

		cout << "\nYou take out the Ancient Spear and pretend to be an Amazon warrior"
			<< "\ntreading through the jungle."
			<< "\n\nYou start to think you're losing your mind."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	case STATUE:

		cout << "\nYou take out the Marble Statue and smash it on the branches, but"
			<< "\nthe branches simply bounce and bend, and don't break."
			<< "\n\nYou put the statue away, now winded from swinging it around."
			<< "\n\nPress enter to continue...";
		getchar();

		break;
	case WATER:

		cout << "\nYou take out the filled Ornate Pitcher, but you remember you're"
			<< "\ntrying to get rid of the branches and vines, not water them and"
			<< "\nmake them stronger, so you put it away."
			<< "\n\nPress enter to continue...";
		getchar();
		break;
	}
}