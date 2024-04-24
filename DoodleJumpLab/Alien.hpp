/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Alien; Contains a class that represents an alien object
 ******************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

class Alien : public sf::CircleShape {

public:

/*************************************************************
 * Function: Alien()
 * Date Created: 04/11/2024
 * Date Last Modified: 04/17/2024
 * Description: default alien constructor
 * Input parameters: sf::Vector2f &pos, const sf::Texture& texture
 * Returns:	void
 *************************************************************/
	Alien(sf::Vector2f &pos, const sf::Texture& texture) : sf::CircleShape(50), hp(0)
	{
		this->setPosition(pos);
		this->setTexture(&texture);
	}

/*************************************************************
* Function: Alien()
* Date Created: 04/11/2024
* Date Last Modified: 04/11/2024
* Description: checks to see if an alien is dead
* Input parameters: void
* Returns:	bool
*************************************************************/
	bool isDead() {
		return (hp <= 0);
	}

private:
	int hp;
};