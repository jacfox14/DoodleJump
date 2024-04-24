#pragma once
#include "test.hpp"
#include <iostream>

Test::Test() 
{
	sf::Texture background_t;
	if(!background_t.loadFromFile("background.png")) {
		std::cout << "Error loading file: 'background.png'" << std::endl;
	}
	background.setTexture(background_t);
	/*window.setSize({ 800,1000});
	window.setTitle("TEST CASE");*/
	sf::View camera;
	camera.reset(sf::FloatRect(0, 0, 800.0f, 1000.0f));
	window.setView(camera);
	window.close();
}

void Test::testMovement() {
	sf::Vector2f size(50.0f, 50.0f);
	sf::Texture player;
	sf::Vector2f pos(500.0f, 500.0f);
	sf::Color color(0, 255, 0, 0);
	if (!player.loadFromFile("Andy.png")) {
		std::cout << "Error loading file: 'Andy.png'" << std::endl;
	}
	Player p1(size, pos, color, player);
	bool success = false;
	Events e;
	sf::Event Event;
	/*sf::Vector2f pos = p1.getPosition();*/
	window.create(sf::VideoMode(800, 1000), "TEST CASE");
	while (window.isOpen()) {
		while (window.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.draw(p1);
		e.movementInput(window, p1);
		window.display();
	}
}

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
	t1.loadFromFile("Platform.png");
	size = { 100.0f, 20.0f };
	sf::Vector2f position((rand() % 800), 0.0f);
	sf::Color green = sf::Color::Green;
	Platform plat1(size, position, green, t1);
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
			std::cout << "Success!" << std::endl;
		}
	}
}

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