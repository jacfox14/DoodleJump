#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "Alien.hpp"
class Events
{
private:
public:
	void movementInput(sf::RenderWindow& window, Player& obj1) {//user presses left and right arrows, changes direction of where the player is going
		
		int x = 0, y = 0, yPrime = 0;
		int direction = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			direction = -1;
			obj1.move(0.3 * direction, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			obj1.move(0.3 * direction, 0);
		}

		

	}

	void shoot(Bullet& obj1) {//user presses space bar, sprite is changed to face upward, bullet sprite is loaded and moves upwards	
			obj1.move(0, -0.8);
	}

	void shotAlien(Bullet& bull, Alien& al) {

		if (bull.getGlobalBounds().intersects(al.getGlobalBounds())) {
			al.move(1000, 0);
		}

	}

	void deathByAlien(Player& p, Alien& al) {

		if (p.getGlobalBounds().intersects(al.getGlobalBounds())) {
			p.move(0,1000);
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
	bool endGame(Player& player1, Alien& alien) {
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