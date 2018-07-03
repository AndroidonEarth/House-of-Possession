/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: Game.hpp, specification file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"

class House;
class Player;
class Ghost;

class Game {

private:
	House* house;
	Player* player;
	Ghost* ghost;
	bool gameOver;
	bool gameWon;

	void printScreen();
	void update();
	Direction getMoveDir();
	void handleExtraOptions(char&);

public:
	Game();
	~Game();

	void runGame();
	
};

#endif // !GAME_HPP