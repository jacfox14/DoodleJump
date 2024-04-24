/*
Project Section: PLayer class
Purpose: Initializing player objects for user to control
Date Started: 04/14/2024
Updates: 04/15/2024-04/23/2024
Referenced: main.cpp, test.hpp, Events-Actions-Class.hpp, player.hpp
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Player : public sf::RectangleShape{

public:
	/*************************************************************
 * Function: Player(                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

	Player(const sf::Vector2f& size, sf::Vector2f& pos, const sf::Color& color, sf::Texture& texture) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&texture);
        this->size = size;
        velocity = 0.0;
	}

	bool isFalling() {
		return (velocity < 0);
	}


private:
	double velocity;
    sf::Texture texture;
    sf::Vector2f size;
    sf::Vector2f pos;
};


