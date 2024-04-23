#include "window.hpp"

Window::Window()
{
    this->createWindow();
}

sf::RenderWindow& Window::getWindow()
{
    return mWindow;
}

void Window::createWindow()
{
    mWindow.create(sf::VideoMode(800, 1000), "Andy jump!");
   //mWindow.setFramerateLimit(60);
    sf::View camera;
    sf::Vector2f center(400.0f,500.0f);
    camera.reset(sf::FloatRect(0, 0, 800.0f, 1000.0f));
   // camera.setCenter(center);
    mWindow.setView(camera);
}