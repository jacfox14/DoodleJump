#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"

int main() {

	PlatformGenerator pg;
	Window w;
	sf::RenderWindow& window = w.getWindow();
	Events move;
	sf::Event e;
	Actions a;

	sf::Vector2f size(50.0, 200.0);
	sf::Vector2f pos(500, 500);
	sf::Color color = sf::Color::Green;

	Player p1(size, pos, color);

	sf::Vector2f size1(50.0, 10.0);
	sf::Vector2f pos1(50, 500);
	sf::Color color1 = sf::Color::Green;
	Platform plat1(size1, pos1, color1);

	bool rising = false;
	int riseCounter = 0;

	while (window.isOpen()) {

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed) {
				window.close();
			}

		}

		move.movementInput(window, p1);

		int direction = 1;


		pg.checkPlatformCollsion(p1);

		if (rising) {

			riseCounter++;
			p1.move(0, -0.5);

			if (riseCounter > 600) {
				rising = false;
				riseCounter = 0;
			}

		}
		else {
			p1.move(0, 0.1);
		}


		// does the ball collide with the p2Paddle?
		if (p1.getGlobalBounds().intersects(plat1.getGlobalBounds()))
		{
			// yes, a collision was detected. let's move the ball the opposite direction
			plat1.move(0, 15);
		}

		a.inBounds(window, p1);

		// clear the window with black color
		window.clear();

		// draw everything here...
		window.draw(p1);
		//		window.draw(plat1);
		pg.drawPlatforms(window);

		// end the current frame
		window.display();


	}

	/*sf::Texture texture;
	if (!texture.loadFromFile("image.jpg"))
	{
		std::cout << "failed to open" << std::endl;
	}*/







	return 0;
}