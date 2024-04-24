#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"
#include "cScreen.hpp"
#include <vector>

class Game:public cScreen{
public:
public:
	/*************************************************************
	 * Function: Run()											 *
	 *									                         *
	 * Description: Holds game event loop						 *
	 * Input parameters: Main window reference					 *
	 * Returns:	Returns to main menu							 *
	 *************************************************************/
	virtual int Run(sf::RenderWindow& window) {
		sf::Texture t1;
		t1.loadFromFile("Platform.png");
		PlatformGenerator pg;
		Events move;
		sf::Event e;
		Actions a;
		int gameScore = 0;

		sf::Text text;
		sf::Font myFont;
		myFont.loadFromFile("Whimsy.ttf");
		text.setPosition(250, 400);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setFont(myFont);
		text.setString("GAME OVER");

		sf::Text scoreText;
		scoreText.setPosition(350, 500);
		scoreText.setCharacterSize(50);
		scoreText.setFillColor(sf::Color::Black);
		scoreText.setFont(myFont);


		sf::Vector2f size(50, 50);
		sf::Texture t;
		sf::Vector2f pos(500, 500);
		sf::Color color(0, 255, 0, 0);
		t.loadFromFile("Andy.png");
		Player p1(size, pos, color, t);

		sf::Texture t2;
		t2.loadFromFile("background.png");
		sf::Sprite background;
		background.setTexture(t2);


		sf::Texture tBullet;
		sf::Vector2f posBullet(1020, 1020);
		tBullet.loadFromFile("bullet.png");
		Bullet bullet(posBullet, tBullet);

		//boxes for game over screen
		sf::Text playAgainTxt, returnMenuTxt;
		playAgainTxt.setString("Play again!"), returnMenuTxt.setString("Main Menu");
		std::vector<sf::Text>textList({ playAgainTxt,returnMenuTxt });
		for (auto& i : textList) {
			i.setFillColor(sf::Color::White);
			i.setCharacterSize(23);
			i.setFont(myFont);
		}
		textList[0].setPosition({ 260.0f,600.0f }), textList[1].setPosition({ 460.0f,600.0f });
		sf::RectangleShape playAgain({ 150.0f,75.0f }), returnMenu({ 150.0f,75.0f });
		playAgain.setFillColor({ 38, 35, 36,170 }), returnMenu.setFillColor({ 38, 35, 36,170 });
		playAgain.setPosition({ 250.0f,600.0f }), returnMenu.setPosition({ 450.0f,600.0f });


		sf::Texture tAlien;
		sf::Vector2f posAlien(1090, 1090);
		tAlien.loadFromFile("Alien.png");
		Alien alien(posAlien, tAlien);

		bool rising = false;
		bool jump = false;
		int riseCounter = 0;
		bool movePlat = false;
		int movePlatCounter = 0;
		bool shot = false;
		bool moveShot = true;
		bool gameOver = false;

		while (window.isOpen()) {

			while (window.pollEvent(e)) {

				if (e.type == sf::Event::Closed) {
					return 0;
					window.close();
					
				}

			}

			gameOver = a.endGame(p1);


			move.movementInput(window, p1);

			int direction = 1;


			rising = pg.checkPlatformCollsion(p1);

			if ((rising || jump)&&(!p1.isFalling())) {

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
				p1.move(0, 0.125f);
			}

			if (movePlat)
			{
				pg.MovePlatformsUp(alien);
				pg.CheckForNewPLatforms(alien, t1);
				movePlatCounter++;

				if (movePlatCounter > 300) {
					movePlat = false;
					movePlatCounter = 0;
					gameScore += 200;
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				shot = true;
				moveShot = true;

			}
			else if (gameOver) {
				if (e.type == sf::Event::MouseButtonReleased) {
					if (sf::Mouse::getPosition(window).x > 250.0f && sf::Mouse::getPosition(window).x < 400.0f) {
						if (sf::Mouse::getPosition(window).y > 600.0f && sf::Mouse::getPosition(window).y < 675.0f) {
							window.clear();
							return 1;
							break;
						}
					}
					else if (sf::Mouse::getPosition(window).x > 450.0f && sf::Mouse::getPosition(window).x < 600.0f) {
						if (sf::Mouse::getPosition(window).y > 600.0f && sf::Mouse::getPosition(window).y < 675.0f) {
							return 0;
							break;
						}
					}
				}
				
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
			move.deathByAlien(p1, alien);
			move.shotAlien(bullet, alien);
			a.inBounds(window, p1);

			// clear the window with black color
			window.clear();

			// draw everything here...
			window.draw(background);
			window.draw(p1);
			pg.drawPlatforms(window);
			window.draw(bullet);
			window.draw(alien);

			if (gameOver == true) {
				window.clear();
				window.draw(background);
				scoreText.setString(std::to_string(gameScore));
				window.draw(text);
				window.draw(scoreText);
				window.draw(playAgain);
				window.draw(returnMenu);
				window.draw(textList[0]);
				window.draw(textList[1]);
			}
			// end the current frame
			window.display();



			/*sf::Texture texture;
			if (!texture.loadFromFile("image.jpg"))
			{
				std::cout << "failed to open" << std::endl;
			}*/

		}

		return 0;
	}
};