/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Hallway.cpp, implementation file for the Hallway class.
*********************************************************************/

#include "Hallway.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

using std::cout;

Hallway::~Hallway() {

	auto iter = this->items.begin();

	while (iter != items.end()) {

		delete iter->second;
		iter++;
	}
}

/*
*
*/
Hallway::Hallway() {

	spaceName = "Hallway";
	spaceType = HALLWAY;

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
void Hallway::examine() {

	cout << "\nA dusty hallway lined with glimmering sconces to light the way.";

	if (top->getType() == ROOM && bottom->getType() == ROOM) {

		cout << "\n\nThere's also a room above you and below you.";
	}
	else if (left->getType() == ROOM && right->getType() == ROOM) {

		cout << "\n\nThere's also a room to your left and to your right.";
	}
	else {

		cout << "\n\nThere are only more hallways in your every direction.";
	}
		
	examined = true;

	cout << "\n\nPress enter to continue...";
	getchar();
}

/*
*
*/
void Hallway::useItem(ItemType itemKey, Item* item, Player* player) {

	Space* room1 = nullptr;
	Space* room2 = nullptr;

	// Check if there's a room above and below you.
	if (top != nullptr && bottom != nullptr) {

		if (top->getType() == ROOM && bottom->getType() == ROOM) {

			room1 = top;
			room2 = bottom;
		}
	}
	// Check if there's a room to your left or right.
	else if (left != nullptr && right != nullptr) {

		if (left->getType() == ROOM && right->getType() == ROOM) {

			room1 = left;
			room2 = right;
		}
	}

	// If there are rooms next to you.
	if (room1 != nullptr && room2 != nullptr) {

		// Check if they're both locked.
		if (room1->isLocked() && room2->isLocked()) {

			// If so prompt the user to select which room to try and unlock.
			char selection = getMenuChoice(roomSelectMenu(room1, room2));
			
			switch (selection) {

			case '1':

				// Unlock the first room.
				room1->unlock(itemKey, item, player);
				break;
			case '2':

				// Unlock the second room.
				room2->unlock(itemKey, item, player);
				break;
			}
		}
		// If the first room is locked but not the second.
		else if (room1->isLocked() && !(room2->isLocked())) {

			room1->unlock(itemKey, item, player);
		}
		// If the second room is locked but not the first.
		else if (!(room1->isLocked()) && room2->isLocked()) {

			room2->unlock(itemKey, item, player);
		}
		// Otherwise if both rooms are already unlocked.
		else {

			cout << "\n\nBoth of the rooms near you are already unlocked, and"
				<< "\nthere doesn't seem to be anything else to use the"
				<< item->getItemName() << " on..."
				<< "\n\nPress enter to continue...";
			getchar();
		}
	}
	else {

		cout << "\n\nYou're surrounded by more hallways on each side, and"
			<< "\nthere doesn't seem to be anything around you to use"
			<< "\nthe " << item->getItemName() << " on..."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}