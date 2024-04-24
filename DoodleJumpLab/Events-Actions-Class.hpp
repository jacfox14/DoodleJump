/*
Project Section: Events and Actions class
Purpose: Focuses on general functionality of the game, prioritizes keeping player in screen, updated, and moving around; works on detection of certain special events happening, like player death by alien or falling, when to end game, and shooting bullets
Date Started: 04/14/2024
Updates: 04/15/2024-04/22/2024
Referenced: main.cpp, test.hpp
*/
#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "Alien.hpp"
class Events//04/14/2024 Events class created to handle user input, as well as detection of interactions between objects
{
private:
public:
	void movementInput(sf::RenderWindow& window, Player& obj1) {//user presses left and right arrows, changes direction of where the player is going
		
		int x = 0, y = 0;
		int direction = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//04/14/2024 function detects A key being pressed, changes direction to left, player moves to left
			direction = -1;
			obj1.move(0.3 * direction, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//04/14/2024 function detects D key being pressed, changes direction to right, player moves to right
			obj1.move(0.3 * direction, 0);
		}
	}

	void shoot(Bullet& obj1) {//user presses space bar, sprite is changed to face upward, bullet sprite is loaded and moves upwards	
			obj1.move(0, -0.8);
	}

	void shotAlien(Bullet& bull, Alien& al) {//04/22/2024 when bullet collides with alien, moves alien off screen and destroys object

		if (bull.getGlobalBounds().intersects(al.getGlobalBounds())) {
			al.move(1000, 0);
		}

	}

	void deathByAlien(Player& p, Alien& al) {//04/22/2024 when player collides with alien, moves player into deathbox off-screen, shows game over message

		if (p.getGlobalBounds().intersects(al.getGlobalBounds())) {
			p.move(0,2000);
		}

	}
	
};

class Actions//04/14/2024 Actions class created as a general wrapper for "rules" of game, making sure player is inbound, objects can collide with one another, and checking for if the game should be terminated
{
private:
public:
	void inBounds(sf::RenderWindow& window, Player& obj) {//04/14/2024 checks players position and puts them on the other side of the screen if they move out of bounds to simulate a looping screen
		if (obj.getPosition().x > 1000) {//04/14/2024 checks to see if player moves past right side of screen, puts player on very left if moved too far
			obj.setPosition(0, obj.getPosition().y);
		}
		else if (obj.getPosition().x < 0) {//04/14/2024 checks to see if player moves past left side of screen, puts player on very right if moved too far
			obj.setPosition(1000, obj.getPosition().y);
		}
	}
	bool endGame(Player& player1) {//04/14/2024 detects whether or not player is off screen to end game **04/22/2024 updated to be a bool to function in main, returns true if player is below the screen
		if (player1.getPosition().y >= 1000) {
			return true;
		}
	}
	bool collisionDetection(sf::RenderWindow& window, sf::RectangleShape& obj1, sf::CircleShape& obj2) {//04/14/2024 checks to see if two objects are colliding, returns true if they are intersecting
		bool success = false;
		if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) {
			success = true;
		}
		return success;
	}
};