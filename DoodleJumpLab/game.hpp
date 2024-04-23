#pragma once
#include "cScreen.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"
#include "menu.hpp"

class Game : public cScreen {
public:
	virtual int Run(sf::RenderWindow& window) {
		PlatformGenerator pg;
		Events move;
		sf::Event e;
		Actions a;
		Alien alien;
		Bullet bullet;
		sf::Text text;
		sf::Font myFont;
		if (!myFont.loadFromFile("Whimsy.ttf")) {
			std::cout << "Error loading font: 'Whimsy.ttf'" << std::endl;
			return -1;
		};

		sf::Vector2f size(50.0, 100.0);
		sf::Texture player_t;
		sf::Vector2f pos(500, 500);
		sf::Color color(sf::Color(255,0,0,255));
		if(!player_t.loadFromFile("Andy.png")) {
			std::cout << "Error loading image: 'Andy.png'" << std::endl;
			return -1;
		}
		Player p1(size, pos,color, player_t);
		p1.setTexture(&player_t);
		color = sf::Color::Blue;
		Menu menu;

		/*sf::Texture t2;
		if (!t2.loadFromFile("image.jpg")) {
			std::cout << "Error loading image: 'image.jpg'" << std::endl;
			return -1;
		}*/

		sf::Sprite background;
		sf::Texture background_t;
		if (!background_t.loadFromFile("background.png")) {
			std::cout << "Error loading image: 'background.png'" << std::endl;
			return -1;
		}
		background.setTexture(background_t);


		bool rising = false;
		bool jump = false;
		int riseCounter = 0;
		bool movePlat = false;
		int movePlatCounter = 0;
		bool shot = false;
		bool moveShot = true;

		while (window.isOpen()) {

			while (window.pollEvent(e)) {

				if (e.type == sf::Event::Closed) {
					return 0;
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				shot = true;
				moveShot = true;

			}

			if (shot) {

				if (moveShot) {
					bullet.setPosition(p1.getPosition());
					moveShot = false;
				}

				move.shoot(bullet);


				if (bullet.getPosition().y < -30) {
					shot = false;
				}

			}

			a.inBounds(window, p1);

			// clear the window with black color
			window.clear();

			// draw everything here...
			window.draw(background);
			window.draw(p1);
			//		window.draw(plat1);
			pg.drawPlatforms(window);
			window.draw(bullet);
			window.draw(alien);
			//window.draw();

			// end the current frame
			window.display();
			if (p1.getPosition().y > 1000) {
				window.clear();
				text.setCharacterSize(50);
				text.setString("Game Over");
				text.setFont(myFont);
				window.draw(text);
			}
		}
		return 0;
	}
};