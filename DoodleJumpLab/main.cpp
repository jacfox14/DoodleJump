/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Main; Runs the main function
 ******************************************************************************/

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

	Screens.push_back(&menu);
	Screens.push_back(&game);
	while (screen >= 0) {
		screen = Screens[screen]->Run(window);
	}
	
	return 0;
	}