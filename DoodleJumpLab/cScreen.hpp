#pragma once
#include "SFML/Graphics.hpp"
#include "window.hpp"
//abstract class for all menu functions, all menu functions will overwrite Run which will then be called in the main event loop
class cScreen {
public:
/*************************************************************
 * Function: Run()											 *
 *									                         *
 * Description: Pure virtual function that will be 			 *
 *				called in main, holds the event loop for	 *
 *				the given screen							 *
 * Input parameters: Main window reference					 *
 * Returns:	next screen to be loaded by main				 *
 *************************************************************/
	virtual int Run(sf::RenderWindow& window) = 0;
};