/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Events and actions; This file contains the class Events
 * which allows for events in the game to occur and the class Actions
 * which completes various actions in the game
 ******************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "Alien.hpp"

class Events
{
private:
public:
/*************************************************************
 * Function: movementInput()                                 
 * Date Created: 04/14/2024                                  
 * Date Last Modified: 04/20/2024                            
 * Description: checks if keyboard inputs are given by user	moves player								 
 * Input parameters: RenderWindow& window, Player& obj1						 
 * Returns:	void 									 
 *************************************************************/
	void movementInput(sf::RenderWindow& window, Player& obj1) {
		
		int x = 0, y = 0;
		int direction = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			direction = -1;
			obj1.move(0.3 * direction, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			obj1.move(0.3f * direction, 0);
		}
	}
/*************************************************************
 * Function: shoot()										 
 * Date Created: 04/14/2024                                  
 * Date Last Modified: 04/20/2024                            
 * Description: moves Bullet type object up screen           
 * Input parameters: reference to Bullet					 
 * Returns: void									 
 *************************************************************/
	void shoot(Bullet& obj1) {	
			obj1.move(0, -0.8);
	}
/*************************************************************
 * Function: shotAlien()									 
 * Date Created: 04/17/2024                                  
 * Date Last Modified: 04/22/2024                            
 * Description: detects if bullet and alien intersect        
 * Input parameters: Bullet& bull, Alien& al
 * Returns: void											 
 *************************************************************/
	void shotAlien(Bullet& bull, Alien& al) {

		if (bull.getGlobalBounds().intersects(al.getGlobalBounds())) {
			al.move(2000, 0);
		}

	}

/*************************************************************
 * Function: deathByAlien()									 
 * Date Created: 04/17/2024                                  
 * Date Last Modified: 04/22/2024                            
 * Description: detects if bullet and alien intersect        
 * Input parameters: Player& p, Alien& al
 * Returns:	void									 
 *************************************************************/
	void deathByAlien(Player& p, Alien& al) {

		if (p.getGlobalBounds().intersects(al.getGlobalBounds())) {
			p.move(0,2000);
		}

	}
	
};

class Actions
{
private:
public:
/*************************************************************
 * Function: inBounds()
 * Date Created: 04/18/2024
 * Date Last Modified: 04/18/2024
 * Description: Checks to see if a player is offscreen on the left 
 * or right of the screen and teleports them to the other side
 * 
 * Input parameters: sf::RenderWindow& window, Player& obj
 * Returns:	void
 *************************************************************/
	void inBounds(sf::RenderWindow& window, Player& obj) {
		if (obj.getPosition().x > 1000) {
			obj.setPosition(0, obj.getPosition().y);
		}
		else if (obj.getPosition().x < 0) {
			obj.setPosition(1000, obj.getPosition().y);
		}
	}
/*************************************************************
 * Function: endGame() 
 * Date Created: 04/18/2024
 * Date Last Modified: 04/22/2024
 * Description: ends the game
 * Input parameters: Player& player1
 * Returns:	bool 
 *************************************************************/
	bool endGame(Player& player1) {
		bool success = false;
		if (player1.getPosition().y >= 1000) {
			success = true;
		}
		return success;
	}
	/*************************************************************
	 * Function: inBounds()
	 * Date Created: 04/18/2024
	 * Date Last Modified: 04/18/2024
	 * Description: detects a collision
	 * Input parameters: sf::RenderWindow& window, sf::RectangleShape& obj1, sf::CircleShape& obj2
	 * Returns:	bool success
	 *************************************************************/
	bool collisionDetection(sf::RenderWindow& window, sf::RectangleShape& obj1, sf::CircleShape& obj2) {
		bool success = false;
		if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) {
			success = true;
		}
		return success;
	}
};