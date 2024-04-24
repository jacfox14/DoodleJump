/*
Name of Project: Doodle Jump
PA 9
Names of Members: Jacob Fox, Ben Metzger, Travis Takushi
Date Began: 04/14/2024
Language: SFML/C++
Class: CPTS122

*/



#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"


int main(void) {
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	PlatformGenerator pg(t1);
	Window w;
	sf::RenderWindow& window = w.getWindow();
	Events move;
	sf::Event e;
	Actions a;
	int gameScore = 0;
	
	sf::Text text;
	sf::Font myFont;
	myFont.loadFromFile("Whimsy.ttf");
	text.setPosition(325, 400);
	text.setCharacterSize(50);
	text.setFont(myFont);
	text.setString("GAME OVER");

	sf::Text scoreText;
	scoreText.setPosition(450, 500);
	scoreText.setCharacterSize(50);
	scoreText.setFont(myFont);
	

	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);

	sf::Texture t2;
	t2.loadFromFile("image.jpg");
	sf::Sprite background;
	background.setTexture(t2);
	

	sf::Texture tBullet;
	sf::Vector2f posBullet(1020, 1020);
	tBullet.loadFromFile("bullet.png");
	Bullet bullet(posBullet,tBullet);


	sf::Texture tAlien;
	sf::Vector2f posAlien(1090, 1090);
	tAlien.loadFromFile("Alien.png");
	Alien alien(posAlien,tAlien);

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
				window.close();
			}

		}
		
		gameOver = a.endGame(p1);


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
		window.draw(p1);
		window.draw(background);
		pg.drawPlatforms(window);
		window.draw(bullet);
		window.draw(alien);

		if (gameOver == true) {
			scoreText.setString(std::to_string(gameScore));
			window.draw(text);
			window.draw(scoreText);
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