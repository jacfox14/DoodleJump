#include "Events-Actions-Class.hpp"
#include "Alien.hpp"
#include "PlatformGenerator.hpp"
#include "window.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "bullet.hpp"
#include "PlatformGenerator.hpp"
#include "Alien.hpp"

class Test : public Window
{
public:
	bool testMovement();
	bool testFalling();
	bool testAlien();
	bool testPlatform();
	bool testGeneratePlat();
	void generateBase();
private:
	sf::RenderWindow mWindow;
	Player p1;
	Platform plat1;
	Alien a1;
};