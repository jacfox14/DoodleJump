/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Test; Contains a class that holds our 5 test cases
 ******************************************************************************/

#include "test.hpp"
#include <iostream>

/*************************************************************
* Function: testMovement
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the movement of the character
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testMovement() {

	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");
	sf::View camera;
	sf::Vector2f center(500.0f, 500.0f);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500.0f, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);
	bool success = false;
	Events e;
	sf::Vector2f testPos = p1.getPosition();
	while (mWindow.isOpen()) {
		mWindow.draw(p1);
		e.movementInput(mWindow, p1);
		mWindow.display();
		if (p1.getPosition() != pos) {
			//return true;
		}
	}
	mWindow.clear();
}

/*************************************************************
* Function: testFalling
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the falling movement
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testFalling() {
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);
	bool success = false;
	Actions a;
	while (mWindow.isOpen()) {
		mWindow.draw(p1);
		p1.move(0, 0.1);
		a.endGame(p1);
		mWindow.display();
	}
	mWindow.clear();
}

/*************************************************************
* Function: testAlien
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of an alien
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testAlien() {
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Vector2f size(50, 50);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);
	sf::Texture tAlien;
	sf::Vector2f posAlien(1090, 1090);
	tAlien.loadFromFile("Alien.png");
	Alien a1(posAlien, tAlien);
	bool success = false;
	Events e;
	Actions a;
	a1.setPosition(500, 500);
	p1.setPosition(500, 800);
	while (mWindow.isOpen()) {
		if (!p1.getGlobalBounds().intersects(a1.getGlobalBounds())) {
			p1.move(0, -0.1);
		}
		mWindow.draw(p1);
		mWindow.draw(a1);
		e.deathByAlien(p1, a1);
		a.endGame(p1);
		mWindow.display();
	}
}

/*************************************************************
* Function: testPlatform
* Date Created: 04/22/2024
* Date Last Modified: 04/24/2024
* Description: tests the generation of a single platform
* Input parameters: void
* Returns:	void
*************************************************************/
void Test::testPlatform() {
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Texture t;
	sf::Vector2f pos(500, 500);
	sf::Vector2f size(50.0f,50.0f);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	Player p1(size, pos, color, t);
	sf::Texture t1;
	t1.loadFromFile("R.png");
	sf::Vector2f sizePlat(100.0f, 20.0f);
	sf::Vector2f position((rand() % 800), 0.0f);
	sf::Color green = sf::Color::Green;
	Platform plat1(sizePlat, position, green, t1);
	bool success = false;
	PlatformGenerator pg;
	plat1.setPosition(500, 800);
	p1.setPosition(500, 500);
	while (mWindow.isOpen()) {
		mWindow.draw(p1);
		mWindow.draw(plat1);
		if (!p1.getGlobalBounds().intersects(plat1.getGlobalBounds())) {
			p1.move(0, 0.1);
		}
		pg.checkPlatformCollsion(p1);
		mWindow.display();
		if (pg.checkPlatformCollsion(p1) == true) {
			//return true;
		}
	}
	//return success;
}

/*************************************************************
 * Function: testGeneratePlat
 * Date Created: 04/22/2024
 * Date Last Modified: 04/24/2024
 * Description: tests the generation of multiple platforms
 * Input parameters: void
 * Returns:	void
 *************************************************************/
void Test::testGeneratePlat() {
	sf::RenderWindow mWindow(sf::VideoMode(800, 1000), "");
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	PlatformGenerator pg;
	int count = 0;
	bool success = false;
	while (mWindow.isOpen()) {
		pg.generateNew(t1);
	}
}