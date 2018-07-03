/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Space.hpp, specification file for the Space class.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"

#include <iostream>
#include <string>
#include <map>
using std::string;
using std::map;

enum SpaceType { ROOM, HALLWAY };
enum ReadType { BOOK, NOTE, LETTER, PHOTO, PAINTING, NONE };

class Player;

class Space {

protected:
	// Pointers to connect to the rooms, for easy traversal.
	Space *top, *right, *bottom, *left;

	// Descriptions.
	string spaceName;
	SpaceType spaceType;
	string lockDesc;

	// States of the room.
	bool locked;
	bool examined;
	bool interactable;
	bool readable;
	bool itemUsed;
	bool takeableKey;
	bool keyTaken;

	// Contents of the room.
	string readableName;
	string interactName;
	string keyName;
	map<ItemType, Item*> items;
	
public:
	// Constructors/destructors.
	Space();
	~Space();

	// Initialization utility function.
	void link(Space*, Space*, Space*, Space*);

	// Pure virtual functions.
	virtual void examine() = 0;
	virtual void useItem(ItemType, Item*, Player*) = 0;
	
	// Optional virtual functions.
	virtual void link(Space*) {}
	virtual void unlock(ItemType, Item*, Player*) {}
	virtual ReadType read() { return NONE; }
	virtual void interact() {}

	// Generic mutators.
	void setInteractable();
	void unlock();
	void removeItem(ItemType);
	void takeKey(Player*);

	// Getters.
	Space* getTop();
	Space* getRight();
	Space* getBottom();
	Space* getLeft();

	string getName();
	SpaceType getType();

	bool isLocked();
	string getLockDesc();

	bool hasBeenExamined();

	bool hasReadable();
	string getReadableName();

	bool hasInteractable();
	string getInteractName();

	bool itemHasBeenUsed();

	bool canTakeKey();
	bool keyHasBeenTaken();
	string getKeyName();

	map<ItemType, Item*>::iterator getBeginIter();
	map<ItemType, Item*>::iterator getEndIter();
	int getItemCount();
};

#endif // !SPACE_HPP