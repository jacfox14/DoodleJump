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