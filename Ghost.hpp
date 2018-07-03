/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Ghost.hpp, specification file for the Ghost class.
*********************************************************************/

#ifndef GHOST_HPP
#define GHOST_HPP

#include "Character.hpp"

class Player;

class Ghost : public Character {

private:
	// Member variables
	Player* playerPtr;	// For checking if the player is near.
	int moveCounter;	// For determining when to move based on the player's moves.
	int strCounter;		// To determine when to increase the ghosts strength.
	int strength;		// To determine how frequently and agressively to move.

	// Utility functions.
	void randMove();	// Basic movement function, to move in a random direction.
	bool seekMove();	// Special movement to move adjacently to the player's space.

public:
	// Constructors/destructors.
	Ghost();
	~Ghost();
	Ghost(Location, Space*, Player*);

	// Primary action.
	bool move();

	// Mutators.
	void incCounters();
};

#endif // !GHOST_HPP