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
    mWindow.create(sf::VideoMode(800, 1000), "Doodle jump!");
    //mWindow.setFramerateLimit(60);
    sf::View camera;
    sf::Vector2f center(500.0, 500.0);
    camera.setCenter(center);
    mWindow.setView(camera);
}