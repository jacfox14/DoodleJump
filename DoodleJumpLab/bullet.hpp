#include "SFML/Graphics.hpp"

class Bullet : public sf::CircleShape{
public :
	Bullet(sf::Vector2f& pos, const sf::Color& color, const sf::Texture& text) : sf::CircleShape(10)
	{
		this->setPosition(pos);
		this->setFillColor(color);
		this->setTexture(&text);
	}
private: 
};

// test code
///changes
