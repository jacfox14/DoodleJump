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

	sf::Vector2f size(50.0, 100.0);
	sf::Vector2f pos(500, 500);
	sf::Color color = sf::Color::Green;

	Player p1(size, pos, color);

	bool rising = false;
	bool jump = false;
	int riseCounter = 0;
	bool movePlat = false;
	int movePlatCounter = 0;

	while (window.isOpen()) {

		while (window.pollEvent(e)) {

			if (e.type == sf::Event::Closed) {
				window.close();
			}

		}

		move.movementInput(window, p1);

		int direction = 1;


		rising = pg.checkPlatformCollsion(p1);

		if (rising || jump) {

			if (riseCounter == 0) {
				jump = true;
			}

			riseCounter++;
			p1.move(0, -0.5);

			if (riseCounter > 600) {
				
				jump = false;
				riseCounter = 0;

				if (p1.getPosition().y < 400) {

					movePlat = true;

				}
			}

		}
		else {
			p1.move(0, 0.1);
		}

		if (movePlat)
		{
			pg.MovePlatformsUp();
			pg.CheckForNewPLatforms();
			movePlatCounter++;

			if (movePlatCounter > 300) {
				movePlat = false;
				movePlatCounter = 0;
			}

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