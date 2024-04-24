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
#include "window.hpp"

/*************************************************************
 * Function: Window()
 * Date Created: 04/20/2024
 * Date Last Modified: 04/20/2024
 * Description: default window constructor
 * Input parameters: void
 * Returns:	void
 *************************************************************/
Window::Window()
{
    this->createWindow();
}

/*************************************************************
 * Function: getWindow()
 * Date Created: 04/20/2024
 * Date Last Modified: 04/20/2024
 * Description: gets a window
 * Input parameters: void
 * Returns:	void
 *************************************************************/
sf::RenderWindow& Window::getWindow()
{
    return mWindow;
}

/*************************************************************
* Function: createWindow()
* Date Created: 04/20/2024
* Date Last Modified: 04/20/2024
* Description: creates a display window
* Input parameters: void
* Returns:	void
*************************************************************/
void Window::createWindow()
{
    mWindow.create(sf::VideoMode(800, 1000), "Andy jump!");
   //mWindow.setFramerateLimit(60);
    sf::View camera;
    sf::Vector2f center(400.0f,500.0f);
    camera.reset(sf::FloatRect(0, 0, 800.0f, 1000.0f));
   // camera.setCenter(center);
    mWindow.setView(camera);
}