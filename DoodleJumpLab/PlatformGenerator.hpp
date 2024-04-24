/*******************************************************************************
 * Programmers: Jacob Fox, Ben Metzger, Travis Takushi
 * Class: CptS 122
 * Programming Assignment: PA9
 * Date:4/24/2024
 *
 * Description: This program plays a version of the hit mobile game Doodle Jump,
 * we call it Andy Jump!
 *
 * Project section: Platform Generator; This file contains the class 
 * PlatformGenerator which generates 6 random platforms to the screen and 
 * creates more as needed.
 ******************************************************************************/
#pragma once
#include "Platform.hpp"
#include "Alien.hpp"
#include <vector>
#include <math.h>
using std::vector;


class PlatformGenerator {
public:

/*************************************************************
 * Function: PlatformGenerator
 * Date Created: 04/18/2024
 * Date Last Modified: 04/24/2024
 * Description: default constructor
 * Input parameters: void
 * Returns:	void
 *************************************************************/
	PlatformGenerator():mPlatformCount(0) {
		for (int i = 1; i <= 6; i++) {
			platformTexture.loadFromFile("R.png");
			sf::Vector2f size(100.0f, 20.0f);
			sf::Color green = sf::Color(0, 255, 0, 0);
			sf::Vector2f position;
			if (i == 1) {//04/18/2024 sets 1st platform lowest
				position = sf::Vector2f(450.0f, 900.0f);
			}
			else {
				if (i % 2 == 0) {//04/18/2024 every other platform spawns at a different height from the previous to ensure that platforms don't overlap
					position = sf::Vector2f((rand() % 400) + 1.0f, 1000 - ((rand() % 250) + 150.0f * i));
				}
				else {
					position = sf::Vector2f((rand() % 400) + 400 + 1, 1000 - ((rand() % 250) + 150 * i));
				}
			}
			Platform* newP = new Platform(size, position, green, platformTexture);
			mPlatforms.push_back(*newP);
			mPlatformCount++;
		}



	}

/*************************************************************
* Function: drawPlatforms
* Date Created: 04/18/2024
* Date Last Modified: 04/20/2024
* Description: draws platforms
* Input parameters: sf::RenderWindow& window
* Returns:	void
*************************************************************/
	void drawPlatforms(sf::RenderWindow& window) {//04/18/2024 iterates through vector and draws all of them to load in platforms into game
		for (int i = 0; i < mPlatformCount; i++) {
			window.draw(mPlatforms[i]);
		}

	}

/*************************************************************
* Function: generateNew
* Date Created: 04/18/2024
* Date Last Modified: 04/20/2024
* Description: generates a new platform
* Input parameters: sf::Texture& t1
* Returns:	Platform& (a new platform)
*************************************************************/
	Platform& generateNew(sf::Texture& t1) {//04/18/2024 General generator for platforms, returns reference to created platform
		sf::Vector2f size(100.0f, 20.0f);
		sf::Vector2f position((rand() % 800), 0.0f);
		sf::Color green = sf::Color::Green;
		return *(new Platform(size, position, green, platformTexture));
	}

/*************************************************************
* Function: checkPlatformCollision
* Date Created: 04/19/2024
* Date Last Modified: 04/20/2024
* Description: checks to see if a player collides with a platform
* Input parameters: void
* Returns:	bool collides
*************************************************************/
	bool checkPlatformCollsion(Player& p1) {//04/19/2024 Checks if the player collides with the platform, returns true if they touch

		bool collides = false;

		for (int i = 0; i < 6; i++) {

			if (p1.getGlobalBounds().intersects(mPlatforms[i].getGlobalBounds())) {
				collides = true;
			}

		}

		return collides;
	}


/*************************************************************
* Function: MovePlatformsUp
* Date Created: 04/19/2024
* Date Last Modified: 04/20/2024
* Description: moves platforms up the screen
* Input parameters: Alien& alien
* Returns: void
*************************************************************/
	void MovePlatformsUp(Alien& alien) {//04/19/2024 moves platforms up when the player reaches a certain point, **04/20/2024 updated to remove platforms when off screen, and add another platform to the back of the vector, thus replacing it at the top, **04/20/2024 condensed down function to simply move platforms, **04/22/2024 added aliens to platforms

		for (int i = 0; i < 6; i++) {
			mPlatforms[i].move(0, 1);
		}
		alien.move(0, 1);

	}

/*************************************************************
* Function: void CheckForNewPlatforms
* Date Created: 04/19/2024
* Date Last Modified: 04/20/2024
* Description: moves platforms up the screen
* Input parameters: Alien& alien, sf::Texture& t1
* Returns: void
*************************************************************/
	void CheckForNewPLatforms(Alien& alien, sf::Texture& t1) {//04/19/2024 checks if platforms are below a certain point then deletes them, adds new platform at back of vector, **04/22/2024 added aliens to platforms

		for (int i = 0; i < 6; i++) {


			if (mPlatforms[i].getPosition().y > 800) {
				mPlatforms.erase(mPlatforms.begin());
				mPlatforms.push_back(generateNew(t1));
				if (alien.getPosition().y > 1500)
				{
					sf::Vector2f alPos(mPlatforms.back().getPosition().x, mPlatforms.back().getPosition().y - 100);
					alien.setPosition(alPos);
				}

			}

		}

	}

/*************************************************************
* Function: void isEmpty
* Date Created: 04/19/2024
* Date Last Modified: 04/20/2024
* Description: checks to see if the platform count is empty
* Input parameters: void
* Returns: bool
*************************************************************/
	bool isEmpty() {//04/19/2024 added to check if there were no platforms on screen for test cases
		if (this->mPlatformCount = 0) {
			return true;
		}
	}


private:
	int mPlatformCount;
	vector<Platform> mPlatforms;
	sf::Texture platformTexture;
};