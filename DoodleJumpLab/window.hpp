#include <SFML/graphics.hpp>
class Window {
public:
	Window();
	sf::RenderWindow& getWindow();
private:
	sf::RenderWindow mWindow;
	void createWindow();

};