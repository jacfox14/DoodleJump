#include "test.hpp"

bool Test::testMovement() {
	mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
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
	Events e;
	sf::Vector2f pos = p1.getPosition();
	while (mWindow.isOpen()) {
		mWindow.draw(p1);
		e.movementInput(mWindow, p1);
		mWindow.display();
		if (p1.getPosition() != pos) {
			return true;
		}
	}
	mWindow.clear();
	return success;
}

bool Test::testFalling() {
	mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
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
		p1.move(0,0.1);
		a.endGame(p1);
		mWindow.display();
		if (a.endGame(p1) == true) {
			success = true;
			return success;
		}
	}
	mWindow.clear();
	return success;
}

bool Test::testAlien() {
	mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
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
		if (a.endGame(p1) == true) {
			success = true;
			return success;
		}
	}
	return success;
}

bool Test::testPlatform() {
	mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
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
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	sf::Vector2f size(100.0f, 20.0f);
	sf::Vector2f position((rand() % 800), 0.0f);
	sf::Color green = sf::Color::Green;
	Platform plat1(size, position, green, t1);
	bool success = false;
	PlatformGenerator pg(t1);
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
			return true;
		}
	}
	return success;
}

bool Test::testGeneratePlat() {
	mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
	sf::View camera;
	sf::Vector2f center(500.0, 500.0);
	camera.setCenter(center);
	mWindow.setView(camera);
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	PlatformGenerator pg(t1);
	int count = 0;
	bool success = false;
	while (mWindow.isOpen()) {
		pg.generateNew(t1);
		if (!pg.isEmpty()) {
			return true;
		}
	}
}