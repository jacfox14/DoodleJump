/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Bullet; Contains a class that represents a Bullet object
 ******************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"
class Bullet : public sf::CircleShape{
public :
/*************************************************************
 * Function: Bullet ()                                       
 * Date Created: 04/19/2024                                  
 * Date Last Modified: 04/19/2024                            
 * Description: Basic Constructor for Bullet class		     
 * Input parameters: sf::Vector2f& pos, const sf::Texture& text
 * returns: void
 *************************************************************/
	Bullet(sf::Vector2f& pos, const sf::Texture& text) : sf::CircleShape(10)
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&text);
	}
private: 
};

