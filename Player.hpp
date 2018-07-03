/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Player.hpp, specification file for the Player class.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Inventory.hpp"
#include "Space.hpp"

class Player : public Character {

private:
	Inventory* inventory;
	map<ReadType, bool> knowledge;
	int health;
	int keys;

public:
	// Constructors/destructors.
	Player();
	Player(Location, Space*);
	~Player();

	// Primary actions.
	bool canMove(Direction);
	void move(Direction);
	void use(Item*);
	void takeItem(ItemType, Item*);

	// Mutators.
	void read(ReadType);
	void decHealth();
	void incKeys();

	// Getters.
	Inventory* getInventory();
	bool hasRead(ReadType);
	int getItemCount();
	int getHealth();
	int getKeys();
};

#endif // !PLAYER_HPP