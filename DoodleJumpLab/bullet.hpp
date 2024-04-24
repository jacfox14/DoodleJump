/*
Project Section: Bullet class
Purpose: Initializing bullet object which will be shot from player and will collide with aliens to kill them
Date Started: 04/19/2024
Updates: 04/19/2024-04/23/2024
Referenced: main.cpp, test.hpp, Events-Actions-Class.hpp
*/
#pragma once
#include "SFML/Graphics.hpp"
class Bullet : public sf::CircleShape{
public :
/*************************************************************
 * Function: Bullet ()                                       *
 * Date Created: 04/19/2024                                  *
 * Date Last Modified: 04/19/2024                            *
 * Description: Basic Constructor for Bullet class		     *
 * Input parameters: reference to sf::Vector2f, reference to *
 *					 sf::Texture							 *
 *************************************************************/
	Bullet(sf::Vector2f& pos, const sf::Texture& text) : sf::CircleShape(10)
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&text);
	}
private: 
};

// test code
///changes
