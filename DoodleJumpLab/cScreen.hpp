/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: cScreen; Contains a abstract class that represents a screen display
 ******************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
#include "window.hpp"
//abstract class for all menu functions, all menu functions will overwrite Run which will then be called in the main event loop
class cScreen {
public:

/*************************************************************
 * Function: Run
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: pure virtual function made for running/displaying
 * a screen
 * 
 * Input parameters: sf::RenderWindow& window
 * returns: int 
 *************************************************************/
	virtual int Run(sf::RenderWindow& window) = 0;
};