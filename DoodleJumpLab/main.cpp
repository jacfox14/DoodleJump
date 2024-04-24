#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"
#include "menu.hpp"
#include "game.hpp"
#include "testCasesMenu.hpp"

int main() {

	
	Window w;
	sf::RenderWindow& window = w.getWindow();
	std::vector<cScreen*> Screens;
	int screen = 0;
	
	//PlatformGenerator pg;
	//Events move;
	//sf::Event e;
	//Actions a;
	//Alien alien;
	//Bullet bullet;
	//sf::Text text;
	//sf::Font myFont;
	//myFont.loadFromFile("Whimsy.ttf");

	//sf::Vector2f size(50.0, 100.0);
	//sf::Texture t;
	//sf::Vector2f pos(500, 500);
	//sf::Color color(sf::Color::Red);
	//t.loadFromFile("Andy.png");
	//Player p1(size, pos, color, t);
	//color = sf::Color::Blue;
	Menu menu;
	Game game;
	TestCasesMenu tcMenu;

	Screens.push_back(&menu);
	Screens.push_back(&game);
	while (screen >= 0) {
		screen = Screens[screen]->Run(window);
	}
	
	return 0;
	}