#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp";
#include "Events-Actions-Class.hpp"
#include "Platform.hpp"
#include "window.hpp"
#include <iostream>
int main() {

	Window w;
	sf::RenderWindow& window = w.getWindow();
	Events move;
	sf::Event e;
	Actions a;

	

	sf::Vector2f size(50.0, 100.0);
	sf::Vector2f pos(500, 500);
	sf::Color color = sf::Color::Green;

	Player p1(size, pos, color);

	sf::Vector2f size1(200.0, 10.0);
	sf::Vector2f pos1(50, 800);
	sf::Color color1 = sf::Color::Red;
	Platform plat1(size1, pos1, color1);

	sf::Vector2f size2(200.0, 10.0);
	sf::Vector2f pos2(200, 600);
	sf::Color color2 = sf::Color::Red;
	Platform plat2(size2, pos2, color2);

	sf::Vector2f size3(200.0, 10.0);
	sf::Vector2f pos3(100, 900);
	sf::Color color3 = sf::Color::Red;
	Platform plat3(size3, pos3, color3);

	sf::Vector2f size4(200.0, 10.0);
	sf::Vector2f pos4(100, 800);
	sf::Color color4 = sf::Color::Red;
	Platform plat4(size4, pos4, color4);

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

		// does the ball collide with the p2Paddle?
		if (p1.getGlobalBounds().intersects(plat1.getGlobalBounds()))
		{
			// yes, a collision was detected. let's move the ball the opposite direction
			rising = true;

		}
	

		if (p1.getGlobalBounds().intersects(plat2.getGlobalBounds()))
		{
			// yes, a collision was detected. let's move the ball the opposite direction

			rising = true;
			

		}

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

		//if (p1.getPosition().y < 300) {

		//	plat1.move(0, 300);
		//	plat2.move(0, 300);


		//}

		a.inBounds(window, p1);

		// clear the window with black color
		window.clear();
		
		// draw everything here...
		window.draw(p1);
		window.draw(plat1);
		window.draw(plat2);
		//window.draw(plat3);
		//window.draw(plat4);

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