#pragma once
#include "SFML/Graphics.hpp"

class Alien : public sf::CircleShape {

public:
	
	//Alien() : hp(0){

	//	sf::Color yellow = sf::Color::Yellow;
	//	sf::Vector2f alStartPos(500, 500);
	//	this->setFillColor(yellow);
	//	this->setPosition(alStartPos);
	//	hp = 0;

	//}

	Alien(sf::Vector2f &pos, const sf::Texture& texture) : sf::CircleShape(50), hp(0)
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&texture);
	}

	bool isDead() {
		return (hp <= 0);
	}

private:
	int hp;
};