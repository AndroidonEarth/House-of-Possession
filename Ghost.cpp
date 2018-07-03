/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ghost.cpp, implementation file for the Ghost class.
*********************************************************************/

#include "Ghost.hpp"
#include "Player.hpp"
#include "Space.hpp"

#include <iostream>
using std::cout;

// Default constructor and destructor.
Ghost::Ghost() {}
Ghost::~Ghost() {}

/*
*
*/
Ghost::Ghost(Location loc, Space* room, Player* player) {

	// Initialize member variables.
	this->coords = loc;
	this->currRoom = room;

	playerPtr = player; // Player pointer to determing player's location.
	strength = 1;		// Start strength at level 1 (max is 4).
	moveCounter = 0;	// Initialize counters.
	strCounter = 0;
}

/*
* Returns true if the ghost moved successfully.
*/
bool Ghost::move() {

	// Check if the ghost should move according to its move counter and strength level.
	if ((moveCounter == 3 && strength == 1) || (moveCounter == 2 && strength == 2)) {

		// At level 1 and 2 simply move randomly.
		randMove();

		// Reset move counter.
		moveCounter = 0;
		return true;
	}
	// If at strength level 3 or 4
	else if ((moveCounter == 2 && strength == 3) || (strength >= 4)) {
	
		// Check if the player is near and move to their space.
		if (seekMove()) {}
		// Or simply move randomly if they're not near.
		else {

			randMove();
		}

		// Reset move counter.
		moveCounter = 0;

		return true;
	}
	return false;
}

/*
*
*/
void Ghost::randMove() {
	
	Direction dir;
	Space* moveToSpace;
	bool hasMoved = false;

	// Keep getting random directions until the ghost moves successfuly.
	while (!hasMoved) {
	
		// Get a space in a random direction.
		dir = static_cast<Direction>(rand() % 4);
		moveToSpace = getMoveToSpace(dir);

		// If there is a space in the given direction.
		if (moveToSpace != nullptr) {

			// Update the ghost's current position.
			currRoom = moveToSpace;
			updateLocation(dir);

			// Indicate that the ghost moved successfully.
			hasMoved = true;
		}
	}
}

/*
* Returns true if the ghost moved to the adjacent space the player is in.
*/
bool Ghost::seekMove() {

	Space* playerRoom = playerPtr->getCurrRoom();

	// Check if the player is in an adjacent space.
	if ((currRoom->getTop() == playerRoom)
		|| (currRoom->getRight() == playerRoom)
		|| (currRoom->getBottom() == playerRoom)
		|| (currRoom->getLeft() == playerRoom)) {

		// If so move the ghost the player's space.
		currRoom = playerRoom;
		coords = playerPtr->getCoords();

		return true;
	}
	return false;
}

/*
*
*/
void Ghost::incCounters() { 

	moveCounter++;

	// Stop increasing the strength counter once it hits 91 (already at max strength).
	if (strCounter < 91) {

		strCounter++;
	}

	// Check if the ghost's strength should go up.
	if (strCounter == 30) {

		strength = 2;
		moveCounter = 0;

		cout << "\nThe moon is rising and Ms. Greyhardt's power grows stronger..."
			<< "\n\nBeware! She can move much faster now!"
			<< "\n\nPress enter to continue...";
		getchar();
	}
	if (strCounter == 60) {

		strength = 3;
		moveCounter = 0;

		cout << "\nThe moon has risen more and Ms. Greyhardt's connection"
			<< "\nto the mortal realm has strengthened..."
			<< "\n\nDon't get too close to her or she will seek you out!"
			<< "\n\nPress enter to continue...";
		getchar();
	}
	if (strCounter == 90) {

		strength = 4;
		moveCounter = 0;

		cout << "\nThe moon is full and at it's peak, and so too"
			<< "\nis Ms. Greyhardt's power!"
			<< "\n\nHurry! Your chance of escape is now slim!"
			<< "\n\nPress enter to continue...";
		getchar();
	}
}