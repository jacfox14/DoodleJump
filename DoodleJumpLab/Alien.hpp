#pragma once
#include "SFML/Graphics.hpp"

class Alien : public sf::Sprite {

public:

	bool isDead() {
		return (hp <= 0);
	}

private:
	int hp;
};