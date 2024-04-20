#include "Player.hpp"

class Platform : public sf::RectangleShape
{
public:

	Platform(const sf::Vector2f& size, sf::Vector2f& pos, const sf::Color& color, sf::Texture texture) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
		this->setFillColor(color);
		this->setTexture(&texture);
	}

private:
};