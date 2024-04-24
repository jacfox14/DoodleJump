/*
Project Section: Alien class
Purpose: Initializing Alien objects for player to avoid
Date Started: 04/14/2024
Updates: 04/15/2024-04/23/2024
Referenced: main.cpp, test.hpp, Events-Actions-Class.hpp, PlatformGenerator.hpp
*/
#pragma once
#include "SFML/Graphics.hpp"

class Alien : public sf::CircleShape {

public:
	/*************************************************************
	 * Function: Alien()                                         *
	 * Date Created: 04/14/2024                                  *
	 * Date Last Modified: 04/22/2024                            *
	 * Description: Constructor for Alien class,				 *
	 *				sets position, texture, and hp				 *
	 * Input parameters: reference to sf::Vector2f, reference	 *
	 *					 to sf::Texture,						 *
	 *************************************************************/
	Alien(sf::Vector2f& pos, const sf::Texture& texture) : sf::CircleShape(100), hp(0)
	{
		this->setPosition(pos);
		this->setTexture(&texture);
	}
	/*************************************************************
	 * Function: isDead()		                                 *
	 * Date Created: 04/14/2024                                  *
	 * Date Last Modified: 04/14/2024                            *
	 * Description: Checks if Alien is dead						 *
	 * Input parameters:										 *
	 * Returns: boolean											 *
	 *************************************************************/
	bool isDead() {
		return (hp <= 0);
	}

private:
	int hp;
};