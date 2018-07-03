/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Space.cpp, implementation file for the Space class.
*********************************************************************/

#include "Space.hpp"
#include "Player.hpp"

using std::cout;

Space::Space() {}

/*
*
*/
Space::~Space() {}

/*
*
*/
void Space::link(Space* top, Space* right, Space* bottom, Space* left) {

	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->left = left;
}

/*
*
*/
void Space::removeItem(ItemType itemKey) {

	// Make sure the item is in the room.
	if (items.find(itemKey) != items.end()) {

		items.erase(itemKey);
	}
	// TRACE:
	else {

		cout << "\nError: Tried to remove an item from the room that didn't exist."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}

/*
* Used for rooms that get unlocked remotely by an interactable component.
*/
void Space::unlock() {

	this->locked = false;
}

/*
*
*/
void Space::setInteractable() {

	this->interactable = true;
}

/*
*
*/
void Space::takeKey(Player* player) {

	if (!(this->keyTaken) && (this->takeableKey)) {

		cout << "\nYou got the " << this->keyName << "!";

		player->incKeys();
		this->keyTaken = true;

		cout << "\n\nPress enter to continue...";
		getchar();
	}
	// TRACE:
	else {

		cout << "\nERROR: Tried to take a key that doesn't exist."
			<< "\n\nPress enter to continue...";
		getchar();
	}
}

// Getters for adjacent spaces.
Space* Space::getTop() { return this->top; }
Space* Space::getRight() { return this->right; }
Space* Space::getBottom() { return this->bottom; }
Space* Space::getLeft() { return this->left; }

// Getters for the room name and type.
string Space::getName() { return this->spaceName; }
SpaceType Space::getType() { return this->spaceType; }

// Getters for the locked state and description.
bool Space::isLocked() { return this->locked; }
string Space::getLockDesc() { return this->lockDesc; }

// Getters to determine if the room has been examined.
bool Space::hasBeenExamined() { return this->examined; }

// Getters for the readable component.
bool Space::hasReadable() { return this->readable; }
string Space::getReadableName() { return this->readableName; }

// Getters for the interactable component.
bool Space::hasInteractable() { return this->interactable; }
string Space::getInteractName() { return this->interactName; }

// Getters to determine if an item is in use in the room.
bool Space::itemHasBeenUsed() { return this->itemUsed; }

// Getters for the state of the key in the room if available.
bool Space::canTakeKey() { return this->takeableKey; }
bool Space::keyHasBeenTaken() { return this->keyTaken; }
string Space::getKeyName() { return this->keyName; }

// Getters for the items available in the room for taking.
map<ItemType, Item*>::iterator Space::getBeginIter() { return items.begin(); }
map<ItemType, Item*>::iterator Space::getEndIter() { return items.end(); }
int Space::getItemCount() { return this->items.size(); }