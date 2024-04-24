/*
Project Section: Bullet class
Purpose: Initializing bullet object which will be shot from player and will collide with aliens to kill them
Date Started: 04/19/2024
Updates: 04/19/2024-04/22/2024
Referenced: main.cpp, test.hpp, Events-Actions-Class.hpp, 
*/
#include "SFML/Graphics.hpp"
class Bullet : public sf::CircleShape{//04/19/2024 Inherited from class CircleShape from SFML
public :
	
	Bullet(sf::Vector2f& pos, const sf::Texture& text) : sf::CircleShape(10)//04/19/2024 Constructor sets general position and texture
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&text);
	}
private: 
};

// test code
///changes
