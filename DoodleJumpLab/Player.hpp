#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Player : public sf::RectangleShape{

public:

	Player(const sf::Vector2f& size, sf::Vector2f& pos, const sf::Color& color, sf::Texture texture) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
	//	this->setFillColor(color);
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


