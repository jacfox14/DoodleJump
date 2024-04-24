/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Menu; Contains a class that allows for a user interface menu 
 * with options to run the game, test functions and view scores
 ******************************************************************************/
#pragma once
#include "cScreen.hpp"

class Menu : public cScreen {
public:

/*************************************************************
 * Function: Menu
 * Date Created: 04/22/2024
 * Date Last Modified: 04/22/2024
 * Description: default constructor for menu class
 * Input parameters: void
 * returns: void
 *************************************************************/
	Menu(){}

/*************************************************************
 * Function: Run
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: runs the menu
 * Input parameters: sf::RenderWindow& window
 * returns: int
 *************************************************************/
	virtual int Run(sf::RenderWindow& window);
private:
	bool running;
};