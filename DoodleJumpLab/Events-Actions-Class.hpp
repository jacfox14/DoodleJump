/*
Project Section: Events and Actions class
Purpose: Focuses on general functionality of the game, prioritizes keeping player in screen, updated, and moving around; works on detection of certain special events happening, like player death by alien or falling, when to end game, and shooting bullets
Date Started: 04/14/2024
Updates: 04/15/2024-04/23/2024
Referenced: main.cpp, test.hpp
*/
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
 * Function: movementInput()                                 *
 * Date Created: 04/14/2024                                  *
 * Date Last Modified: 04/20/2024                            *
 * Description: checks if keyboard inputs are given by user	 *
 *				moves player								 *
 * Input parameters: refernece to RenderWindow, reference to *
 *					 Player									 *
 * Returns:													 *
 *************************************************************/
	void movementInput(sf::RenderWindow& window, Player& obj1) {
		
		int x = 0, y = 0;
		int direction = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			direction = -1;
			obj1.move(0.3f * direction, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			obj1.move(0.3f * direction, 0);
		}
	}
/*************************************************************
 * Function: shoot()										 *
 * Date Created: 04/14/2024                                  *
 * Date Last Modified: 04/20/2024                            *
 * Description: moves Bullet type object up screen           *
 * Input parameters: reference to Bullet					 *
 * Returns:													 *
 *************************************************************/
	void shoot(Bullet& obj1) {	
			obj1.move(0, -0.8f);
	}
/*************************************************************
 * Function: shotAlien()									 *
 * Date Created: 04/22/2024                                  *
 * Date Last Modified: 04/22/2024                            *
 * Description: detects if bullet and alien intersect        *
 * Input parameters: refernece to Bullet, reference to Alien *
 * Returns:													 *
 *************************************************************/
	void shotAlien(Bullet& bull, Alien& al) {

		if (bull.getGlobalBounds().intersects(al.getGlobalBounds())) {
			al.move(2000, 0);
		}

	}
/*************************************************************
 * Function: deathByAlien()									 *
 * Date Created: 04/22/2024                                  *
 * Date Last Modified: 04/22/2024                            *
 * Description: detects if bullet and alien intersect        *
 * Input parameters: refernece to Bullet, reference to Alien *
 * Returns:													 *
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
	void inBounds(sf::RenderWindow& window, Player& obj) {
		if (obj.getPosition().x > 1000) {
			obj.setPosition(0, obj.getPosition().y);
		}
		else if (obj.getPosition().x < 0) {
			obj.setPosition(1000, obj.getPosition().y);
		}
	}
	bool endGame(Player& player1) {
		if (player1.getPosition().y >= 1000) {
			return true;
		}
	}
	bool collisionDetection(sf::RenderWindow& window, sf::RectangleShape& obj1, sf::CircleShape& obj2) {
		bool success = false;
		if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) {
			success = true;
		}
		return success;
	}
};