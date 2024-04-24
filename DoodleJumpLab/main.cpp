#pragma once

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
#include "menu.hpp"
#include "game.hpp"
#include "testCasesMenu.hpp"

 /*************************************************************
  * Function: main
  * Date Created: 04/22/2024
  * Date Last Modified: 04/24/2024
  * Description: runs the main function
  * Input parameters: void
  * returns: int
  *************************************************************/
int main() {

	
	Window w;
	sf::RenderWindow& window = w.getWindow();
	std::vector<cScreen*> Screens;
	int select = 0;
	
	
	Menu menu;
	Game game;
	TestCasesMenu tcMenu;

	Screens.push_back(&menu);
	Screens.push_back(&game);
	Screens.push_back(&tcMenu);
	while (select >= 0) {
		select = Screens[select]->Run(window);
	}
	
	return 0;
	}