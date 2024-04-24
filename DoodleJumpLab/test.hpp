#pragma once
#include "Events-Actions-Class.hpp"
#include "Alien.hpp"
#include "PlatformGenerator.hpp"
#include "window.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "PlatformGenerator.hpp"
#include "Alien.hpp"

class Test
{
public:
	Test();
	void testMovement();
	void testFalling();
	void testAlien();
	void testPlatform();
	void testGeneratePlat();
private:
	sf::Sprite background;
	sf::RenderWindow window;
};