/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Player; Contains a class that represents a player object
 ******************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Player : public sf::RectangleShape{

public:
/*************************************************************
 * Function: Player                                      
 * Date Created: 04/14/2024                                  
 * Date Last Modified: 04/22/2024                            
 * Description: Default Constructor for player class
 * Input parameters: const sf::Vector2f& size, sf::Vector2f& pos,
 * const sf::Color& color, sf::Texture& texture
 * returns: void
 *************************************************************/

	Player(const sf::Vector2f& size, sf::Vector2f& pos, const sf::Color& color, sf::Texture& texture) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
		//this->setFillColor(color);
		this->setTexture(&texture);
        this->size = size;
        velocity = 0.0;
	}
/*************************************************************
 * Function: isFalling                                    
 * Date Created: 04/14/2024                                  
 * Date Last Modified: 04/14/2024                            
 * Description: Checks if player is falling					 
 * Input parameters: void							 
 * Returns: bool								 
 *************************************************************/
	bool isFalling() {
		return (velocity < 0);
	}


private:
	double velocity;
    sf::Texture texture;
    sf::Vector2f size;
    sf::Vector2f pos;
};


