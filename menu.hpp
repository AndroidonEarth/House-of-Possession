/*********************************************************************
** Program name: House of Possessions (Final Project)
** Author: Andrew Swaim
** Date: March 20, 2018
** Description: menu.hpp, specification file for the menu helper functions.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

class Space;
class Inventory;

// Function declarations.
void displayTitle();
char mainMenu();
void displayIntro();
char actionSelectMenu(Space*);
char useItemMenu(Inventory*);
char roomSelectMenu(Space*, Space*);
char examineMenu();
char examineItemMenu(Inventory*);
char takeItemMenu(Space*);
char dirSelectMenu();
void displayWinMessage();
char playAgainMenu();
void displayOutro();

#endif