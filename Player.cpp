/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Player.cpp, implementation file for the Player class.
*********************************************************************/

#include "Player.hpp"
#include "Space.hpp"

using std::cout;
using std::pair;

// Default constructor.
Player::Player() {}

/*
*
*/
Player::Player(Location loc, Space* room) {

	this->coords = loc;
	this->currRoom = room;

	// Create the player's inventory.
	inventory = new Inventory();

	// Initialize the player's knowledge.
	knowledge.insert(pair <ReadType, bool>(BOOK, false));
	knowledge.insert(pair <ReadType, bool>(NOTE, false));
	knowledge.insert(pair <ReadType, bool>(LETTER, false));
	knowledge.insert(pair <ReadType, bool>(PHOTO, false));
	knowledge.insert(pair <ReadType, bool>(PAINTING, false));

	health = 3;
	keys = 0;
}

/*
*
*/
Player::~Player() {

	delete inventory;
}

/*
* Does not check if capable of moving in indicated direction.
*/
void Player::move(Direction dir) {

	Space* moveToSpace = getMoveToSpace(dir);

	// Update the players current position.
	currRoom = moveToSpace;
	updateLocation(dir);
}

/*
*
*/
bool Player::canMove(Direction dir) {

	Space* moveToSpace = getMoveToSpace(dir);

	// Check if the space is out of bounds.
	if (moveToSpace == nullptr) {

		cout << "\nThere's only a wall in that direction.";

		cout << "\n\nPress enter to continue...";
		getchar();
		return false;
	}
	// Check if the space to move to is locked.
	else if (moveToSpace->isLocked()) {

		cout << "\n" << moveToSpace->getLockDesc();

		cout << "\n\nPress enter to continue...";
		getchar();
		return false;
	}

	return true;
}

/*
*
*/
void Player::use(Item* item) {

}

/*
*
*/
void Player::takeItem(ItemType itemKey, Item* item) {

	// Put the selected item in the player's inventory.
	inventory->addItem(itemKey, item);

	// And remove from the current room.
	currRoom->removeItem(itemKey);
}

// Mutators.
void Player::decHealth() { health--; }
void Player::incKeys() { keys++; }
void Player::read(ReadType clue) { knowledge[clue] = true; }

// Getters.
Inventory* Player::getInventory() { return this->inventory; }
bool Player::hasRead(ReadType clue) { return knowledge[clue]; }
int Player::getItemCount() { return this->inventory->getCount(); }
int Player::getHealth() { return this->health; }
int Player::getKeys() { return this->keys; }