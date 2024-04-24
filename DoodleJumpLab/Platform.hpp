/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Platform; Contains a class that represents a platform object
 ******************************************************************************/
#pragma once
#include "Player.hpp"

class Platform : public sf::RectangleShape
{
public:

/*************************************************************
 * Function: Platform
 * Date Created: 04/14/2024
 * Date Last Modified: 04/22/2024
 * Description: default constructor for platform class
 * Input parameters: const sf::Vector2f& size, sf::Vector2f& pos,
 * const sf::Color& color, sf::Texture& texture
 * returns: void
 *************************************************************/
	Platform(const sf::Vector2f& size, sf::Vector2f& pos, const sf::Color& color, sf::Texture& texture) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
	//	this->setFillColor(color);
		this->setTexture(&texture);
	}

private:
};