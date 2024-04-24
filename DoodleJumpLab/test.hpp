/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Test; Contains a class that holds our 5 test cases
 ******************************************************************************/

#include "Events-Actions-Class.hpp"
#include "Alien.hpp"
#include "PlatformGenerator.hpp"
#include "window.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "PlatformGenerator.hpp"
#include "Alien.hpp"

class Test : public Window
{
public:

/*************************************************************
 * Function: testMovement
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: tests the movement of the character
 * Input parameters: void
 * Returns:	void
 *************************************************************/
	void testMovement();
/*************************************************************
* Function: testFalling
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the falling movement 
* Input parameters: void
* Returns:	void
*************************************************************/
	void testFalling();
/*************************************************************
* Function: testAlien
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of an alien
* Input parameters: void
* Returns:	void
*************************************************************/
	void testAlien();
/*************************************************************
* Function: testPlatform
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of a single platform
* Input parameters: void
* Returns:	void
*************************************************************/
	void testPlatform();
/*************************************************************
 * Function: testGeneratePlat
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: tests the generation of multiple platforms
 * Input parameters: void
 * Returns:	void
 *************************************************************/
	void testGeneratePlat();
private:
};