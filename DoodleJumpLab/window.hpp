/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Window; Contains a class that creates our display window
 ******************************************************************************/

#pragma once
#include <SFML/graphics.hpp>
class Window {
public:

/*************************************************************
 * Function: Window()
 * Date Created: 04/20/2024
 * Date Last Modified: 04/20/2024
 * Description: default window constructor
 * Input parameters: void
 * Returns:	void
 *************************************************************/
	Window();

/*************************************************************
 * Function: getWindow()
 * Date Created: 04/20/2024
 * Date Last Modified: 04/20/2024
 * Description: gets a window
 * Input parameters: void
 * Returns:	void
 *************************************************************/
	sf::RenderWindow& getWindow();
private:

	// RenderWindow object
	sf::RenderWindow mWindow;

/*************************************************************
* Function: createWindow()
* Date Created: 04/20/2024
* Date Last Modified: 04/20/2024
* Description: creates a display window
* Input parameters: void
* Returns:	void
*************************************************************/
	void createWindow();

};