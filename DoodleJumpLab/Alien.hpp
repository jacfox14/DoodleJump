#pragma once
#include "SFML/Graphics.hpp"

class Alien : public sf::CircleShape {

public:

	Alien(sf::Vector2f &pos, const sf::Texture& texture) : sf::CircleShape(50), hp(0)
	{
		this->setPosition(pos);
		this->setTexture(&texture);
	}

	bool isDead() {
		return (hp <= 0);
	}

private:
	int hp;
};