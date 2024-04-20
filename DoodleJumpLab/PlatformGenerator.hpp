#pragma once
#include "Platform.hpp"
#include <vector>
#include <math.h>
using std::vector;


class PlatformGenerator {
public:
	PlatformGenerator():mPlatformCount(0) {
		for (int i = 1; i <= 6; i++) {
			sf::Vector2f size(100.0f, 20.0f);
			sf::Color green = sf::Color::Green;
			sf::Vector2f position;
			if(i==1){
				position=sf::Vector2f(450.0f, 900.0f);
			}
			else {
				if (i % 2 == 0) {
					position = sf::Vector2f((rand() % 400) + 1, 1000 - ((rand() % 250) + 150 * i));
				}
				else {
					position = sf::Vector2f((rand() % 400)+400 + 1, 1000 - ((rand() % 250) + 150 * i));
				}
			}
			Platform* newP = new Platform(size, position, green);
			mPlatforms.push_back(*newP);
			mPlatformCount++;
		}
	}
	void drawPlatforms(sf::RenderWindow& window) {
		for (int i = 0; i < mPlatformCount; i++) {
			window.draw(mPlatforms[i]);
		}
	}

	Platform& generateNew() {
		sf::Texture t1;
		t1.loadFromFile("Platform.png");
		sf::Vector2f size(100.0f, 20.0f);
		sf::Vector2f position((rand() % 800), 0.0f);
		sf::Color green = sf::Color::Green;
		return *(new Platform(size, position, green, t1));
	}

	bool checkPlatformCollsion(Player& p1) {

		bool collides = false;

		for (int i = 0; i < 6; i++) {

			if (p1.getGlobalBounds().intersects(mPlatforms[i].getGlobalBounds())) {
				collides = true;
			}

		}

		return collides;
	}

	void MovePlatformsUp() {
		
		for (int i = 0; i < 6; i++) {
			mPlatforms[i].move(0, 1);
		}

	}


	void CheckForNewPLatforms() {

		for (int i = 0; i < 6; i++) {

			//mPlatforms[i].move(0, 300);

			if (mPlatforms[i].getPosition().y > 800) {
				mPlatforms.erase(mPlatforms.begin());
				mPlatforms.push_back(generateNew());
				
			}
			/*if (mPlatformCount < 6) {
				while (mPlatformCount < 6)
				{
					mPlatforms.push_back(generateNew());
					mPlatformCount++;
				}
				
			}*/

		}
		
	}

	/*void popFront(vector<Platform> platforms) {

		platforms.front() = platforms.back();
		platforms.pop_back();

	}*/

private:
	int mPlatformCount;
	vector<Platform> mPlatforms;
};