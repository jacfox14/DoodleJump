#pragma once
#include "cScreen.hpp"

class Menu : public cScreen {
public:
	Menu(){}
	virtual int Run(sf::RenderWindow& window);
private:
	bool running;
};