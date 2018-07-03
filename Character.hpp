/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Character.hpp, specification file for the Character class.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Space;

enum Direction { UP, RIGHT, DOWN, LEFT };

struct Location {

	int col;
	int row;
};

class Character {

protected:
	// Member variables.
	Location coords;
	Space* currRoom;

	// Utility function.
	Space* getMoveToSpace(Direction);
	void updateLocation(Direction);

public:
	// Constructors/destructors.
	Character();
	~Character();

	// Getters.
	Location getCoords();
	Space* getCurrRoom();
};

#endif // !CHARACTER_HPP
