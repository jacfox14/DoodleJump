#include "SFML/Graphics.hpp"

class Bullet : public sf::CircleShape{
public :
	Bullet() :sf::CircleShape(10) {
		sf::Vector2f pos(0.0f, 0.0f);
		this->setPosition(pos);
		
	}
	Bullet(sf::Vector2f& pos, const sf::Color& color, sf::Texture& text) : sf::CircleShape(10)
	{
		this->setPosition(pos);
		this->setFillColor(color);
		this->setTexture(&text);
	}
private: 
};

// test code
///changes
