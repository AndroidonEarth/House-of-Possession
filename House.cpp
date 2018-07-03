/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: House.cpp, implementation file for the House class.
*********************************************************************/

#include "House.hpp"
#include "Ballroom.hpp"
#include "Bathroom.hpp"
#include "Bedroom.hpp"
#include "Diningroom.hpp"
#include "Entryway.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "Library.hpp"
#include "Study.hpp"
#include "Trophyroom.hpp"

House::House() {

	// Allocate memory.
	house = new Space**[5];
	for (int i = 0; i < 5; i++) {
		
		house[i] = new Space*[5];
	}

	// Create room objects.
	createRooms();

	// Link rooms together.
	linkRooms();
}

/*
*
*/
void House::createRooms() {

	// Row 1
	house[0][0] = new Study();
	house[0][1] = new Hallway();
	house[0][2] = new Bedroom();
	house[0][3] = new Hallway();
	house[0][4] = new Trophyroom();

	// Row 2
	house[1][0] = new Hallway();
	house[1][1] = new Hallway();
	house[1][2] = new Hallway();
	house[1][3] = new Hallway();
	house[1][4] = new Hallway();

	// Row 3
	house[2][0] = new Library();
	house[2][1] = new Hallway();
	house[2][2] = new Kitchen();
	house[2][3] = new Hallway();
	house[2][4] = new Diningroom();

	// Row 4
	house[3][0] = new Hallway();
	house[3][1] = new Hallway();
	house[3][2] = new Hallway();
	house[3][3] = new Hallway();
	house[3][4] = new Hallway();

	// Row 5
	house[4][0] = new Bathroom();
	house[4][1] = new Hallway();
	house[4][2] = new Ballroom();
	house[4][3] = new Hallway();
	house[4][4] = new Entryway();
}

/*
*
*/
void House::linkRooms() {

	// Row 1
	house[0][0]->link(nullptr, house[0][1], house[1][0], nullptr);
	house[0][1]->link(nullptr, house[0][2], house[1][1], house[0][0]);
	house[0][2]->link(nullptr, house[0][3], house[1][2], house[0][1]);
	house[0][3]->link(nullptr, house[0][4], house[1][3], house[0][2]);
	house[0][4]->link(nullptr, nullptr, house[1][4], house[0][3]);

	// Row 2
	house[1][0]->link(house[0][0], house[1][1], house[2][0], nullptr);
	house[1][1]->link(house[0][1], house[1][2], house[2][1], house[1][0]);
	house[1][2]->link(house[0][2], house[1][3], house[2][2], house[1][1]);
	house[1][3]->link(house[0][3], house[1][4], house[2][3], house[1][2]);
	house[1][4]->link(house[0][4], nullptr, house[2][4], house[1][3]);

	// Row 3
	house[2][0]->link(house[1][0], house[2][1], house[3][0], nullptr);
	house[2][1]->link(house[1][1], house[2][2], house[3][1], house[2][0]);
	house[2][2]->link(house[1][2], house[2][3], house[3][2], house[2][1]);
	house[2][3]->link(house[1][3], house[2][4], house[3][3], house[2][2]);
	house[2][4]->link(house[1][4], nullptr, house[3][4], house[2][3]);

	// Row 4
	house[3][0]->link(house[2][0], house[3][1], house[4][0], nullptr);
	house[3][1]->link(house[2][1], house[3][2], house[4][1], house[3][0]);
	house[3][2]->link(house[2][2], house[3][3], house[4][2], house[3][1]);
	house[3][3]->link(house[2][3], house[3][4], house[4][3], house[3][2]);
	house[3][4]->link(house[2][4], nullptr, house[4][4], house[3][3]);

	// Row 5
	house[4][0]->link(house[3][0], house[4][1], nullptr, nullptr);
	house[4][1]->link(house[3][1], house[4][2], nullptr, house[4][0]);
	house[4][2]->link(house[3][2], house[4][3], nullptr, house[4][1]);
	house[4][3]->link(house[3][3], house[4][4], nullptr, house[4][2]);
	house[4][4]->link(house[3][4], nullptr, nullptr, house[4][3]);

	// Link the interactable rooms to the rooms that they unlock.
	house[4][4]->link(house[0][2]);	// Link Entryway to Bedroom.
	house[0][4]->link(house[2][0]); // Link Trophyroom to Library.
	house[2][2]->link(house[4][0]); // Link Kitchen to Bathroom.
	house[2][4]->link(house[0][4]); // Link Diningroom to Trophyroom.
}

/*
*
*/
House::~House() {

	// Deallocate memory.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			delete house[i][j];
		}
		
		delete[] house[i];
	}
	delete[] house;
}

// Getters.
Space* House::getSpace(int x, int y) { return house[x][y]; }