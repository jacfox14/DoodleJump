#include "SFML/Graphics.hpp"
#include "Player.hpp"
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
	void endGame(sf::RenderWindow& window, sf::Sprite& obj1, sf::Sprite& obj2) {
		if (obj1.getPosition().y < obj2.getPosition().y) {
			window.clear();
		}
	}
	bool collisionDetection(sf::RenderWindow& window, sf::Sprite& obj1, sf::Sprite & obj2) {
		bool success = false;
		if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) {
			success = true;
		}
		return success;
	}
};