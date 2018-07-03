/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Character.cpp, implementation file for the Character class.
*********************************************************************/

#include "Character.hpp"
#include "Space.hpp"

Character::Character() {}
Character:: ~Character() {}

/*
*
*/
Space* Character::getMoveToSpace(Direction dir) {

	switch (dir) {

	case UP:
		return this->currRoom->getTop();
		break;
	case RIGHT:
		return this->currRoom->getRight();
		break;
	case DOWN:
		return this->currRoom->getBottom();
		break;
	case LEFT:
		return this->currRoom->getLeft();
		break;
	}
}

/*
*
*/
void Character::updateLocation(Direction dir) {

	switch (dir) {

	case UP:
		this->coords.row--;
		break;
	case RIGHT:
		this->coords.col++;
		break;
	case DOWN:
		this->coords.row++;
		break;
	case LEFT:
		this->coords.col--;
		break;
	}
}

// Getters.
Location Character::getCoords() { return this->coords; }
Space* Character::getCurrRoom() { return this->currRoom; }