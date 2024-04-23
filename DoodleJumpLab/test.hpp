#include "Events-Actions-Class.hpp"
#include "Alien.hpp"
#include "PlatformGenerator.hpp"
#include "window.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "bullet.hpp"

class Test : public Window
{
public:
	bool testMovement();
	bool testFalling();
	bool testAlien();
	bool testPlatform();
	bool testGeneratePlat();
private:
	sf::RenderWindow mWindow;
};