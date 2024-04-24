#include "test.hpp"

void Test::generateBase() {
	this->mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
	sf::View camera;
	sf::Vector2f center(500.0f, 500.0f);
	camera.setCenter(center);
	this->mWindow.setView(camera);
	sf::Vector2f size(50.0f, 50.0f);
	sf::Texture t;
	sf::Vector2f pos(500.0f, 500);
	sf::Color color(0, 255, 0, 0);
	t.loadFromFile("Andy.png");
	sf::Texture tAlien;
	sf::Vector2f posAlien(1090, 1090);
	tAlien.loadFromFile("Alien.png");
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	sf::Vector2f size1(100.0f, 20.0f);
	sf::Vector2f position((rand() % 800), 0.0f);
	sf::Color green = sf::Color::Green;
	this->p1.setSize(size);
	this->p1.setFillColor(color);
	this->p1.setTexture(&t);
	this->p1.setPosition(pos);
	this->a1.setPosition(posAlien);
	this->a1.setTexture(&tAlien);
	this->plat1.setTexture(&t1);
	this->plat1.setSize(size1);
	this->plat1.setPosition(position);
}

bool Test::testMovement() {
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
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
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
			return true;
		}
	}
	return success;
}

bool Test::testGeneratePlat() {
	sf::Texture t1;
	t1.loadFromFile("Platform.png");
	PlatformGenerator pg;
	int count = 0;
	bool success = false;
	while (mWindow.isOpen()) {
		pg.generateNew(t1);
		if (!pg.isEmpty()) {
			return true;
		}
	}
}