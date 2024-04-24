#pragma once
#include "test.hpp"
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/Main.hpp"
#include "SFML/System.hpp"
#include "player.hpp"
#include "Events-Actions-Class.hpp"
#include "window.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"

//Selection by player that will be used in a swtich case to run different test cases
enum Selection {
	__movement, __falling, __alien, __platform, __generatePlat
};
class TestCasesMenu :public cScreen {
public:
	//TestCasesMenu(){}
	virtual int Run(sf::RenderWindow& window) {
		Test testCases;
		sf::Event Event;
		bool running = true;
		//keeps track of which menu option is selected, default is test case for movement
		int selection = 1;

		//if user presses enter and locks in a selection, this will be set to true
		bool hasSelected = false;
		//loading background
		sf::Texture background_texture;
		sf::Sprite background_spr;

		Selection currentSelection = __movement;
		//prevent the program from breaking
		if (!background_texture.loadFromFile("test-cases-menu.png")) {
			std::cout << "Error loading image: 'test-cases-menu.png'" << std::endl;
			return -1;
		}
		background_spr.setTexture(background_texture);
		sf::Font font;
		if (!font.loadFromFile("Comic Sans MS.ttf")) {
			std::cout << "Error loading font: 'Comic Sans MS.ttf'" << std::endl;
			return -1;
		}

		//initializing text
		sf::Text movement, falling, alien, platform, generatePlat;
		std::vector<sf::Text> textList{ movement,falling,alien,platform,generatePlat };
		//Ranged-based for loop initializes each text inside textList vector, position is set outisde the loop
		for (auto i : textList) {
			i.setFont(font);
			i.setCharacterSize(40);
			i.setFillColor(sf::Color());
		}
		movement.setPosition({ 375.0f,340.0f });
		falling.setPosition({ 375.0f,440.0f });
		alien.setPosition({ 375.0f,540.0f });
		platform.setPosition({ 375.0f,640.0f });
		generatePlat.setPosition({ 375.0f,740.0f });

		//event loop
		while (running) {
			while (window.pollEvent(Event)) {
				if (Event.type == sf::Event::Closed) {
					running = false;
					window.close();
					return 1;
				}
				else if (Event.type == sf::Event::KeyReleased) {
					if (!hasSelected) {
						switch (Event.key.code) {
						case sf::Keyboard::Up:
							if (selection != 1) {
								selection -= 1;
								break;
							}
						case sf::Keyboard::Down:
							if (selection != 4) {
								selection += 1;
								break;
							}
						case sf::Keyboard::Return:
							hasSelected = true;
							break;
						default:
							break;
						}
					}
					//directing to test functions
					else {
						running = false;
						switch (selection) {
						//Test case for movement
						case 1:
							testCases.testMovement();
							break;
						//Test case for falling
						case 2:
							testCases.testFalling();
							break;
						//Test case for alien
						case 3:
							testCases.testAlien();
							break;
						//Test case for platform collision
						case 4:
							testCases.testPlatform();
							break;
						//Test cases for generating platforms
						case 5:
							testCases.testGeneratePlat();
							break;
						default:
							break;
						}
						
					}
					//setting color of selection
					for (int i = 0; i < 5; i++) {
						if (i == selection) {
							textList[i].setFillColor({ 255,0,0,255 });
						}
						else {
							//default constructor of sf::Color is black
							textList[i].setFillColor(sf::Color());
						}
					}
				}
			}
			if (!running) {
				break;
			}
		}
		window.clear();
		window.draw(background_spr);
		for (auto i : textList) {
			window.draw(i);
		}
		window.display();
		//returns to main menu
		return 1;
	}
};
