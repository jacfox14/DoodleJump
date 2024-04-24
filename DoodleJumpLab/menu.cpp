
#include "menu.hpp"
#include <iostream>
enum Selection {
    __play, __exit, __scores, __test_cases
};

int Menu::Run(sf::RenderWindow& window)
{
    sf::Event Event;
    running = true;
   
    sf::Texture background_texture;
    sf::Sprite background_spr;
    //tracker for selecting 2 of the text options or the 2 boxes in the bottom right
    Selection currentSelection = __play;
    int confirm = 0;
    //to prevent the program from breaking if file is not properly loaded
    if (!background_texture.loadFromFile("main-menu.png")) {
        std::cout << "Error loading file: 'main-menu.png'" << std::endl;
        return -1;
    }
    background_spr.setTexture(background_texture);
    sf::Font Font;
    if (!Font.loadFromFile("Comic Sans MS.ttf")) {
        std::cout << "Error loading file: 'Comic Sans MS.ttf'" << std::endl;
        return -1;
    }
    //Scores is being removed for final push, not enough time to implement correctly 4/24/24
    sf::RectangleShape scores({ 150.0f,100.0f });
    scores.setPosition({ 440.0f,800.0f });
    scores.setFillColor(sf::Color(255, 255, 255, 0));

    sf::RectangleShape test_cases({ 160.0f,180.0f });
    test_cases.setPosition({ 600.0f,760.0f });
    test_cases.setFillColor(sf::Color(255, 255, 255, 0));
    //text customization and positioning
    sf::Text play, exitT;
    play.setFont(Font), exitT.setFont(Font);
    play.setCharacterSize(40),exitT.setCharacterSize(40);
    play.setString("Play!"), exitT.setString("Exit");
    play.setFillColor(sf::Color()), exitT.setFillColor(sf::Color());
    play.setPosition({ 300.0f,300.0f });
    exitT.setPosition({ 300.0f,420.0f });
    while (running) {
        while (window.pollEvent(Event)) {
            //if window gets forcefully closed
            if (Event.type == sf::Event::Closed) {
                running = false;
                window.close();
                return -1;
            }
            //otherwise we are looking for keystrokes that navigate menu
            else if (Event.type == sf::Event::KeyReleased) {
                //switch for keyreleased
                switch (Event.key.code) {
                case sf::Keyboard::Up:
                    currentSelection = __play;
                    play.setFillColor(sf::Color(255, 0, 0, 255));
                    exitT.setFillColor(sf::Color(0, 0, 0, 255));
                    break;
                case sf::Keyboard::Down:
                    currentSelection = __exit;
                    play.setFillColor(sf::Color(0, 0, 0, 255));
                    exitT.setFillColor(sf::Color(255, 0, 0, 255));
                    break;
                case sf::Keyboard::Enter:
                    confirm = 1;
                    break;
                }
            }
            else if (Event.type == sf::Event::MouseButtonPressed) {
                //switch for mouse click
                
                //scores is removed for the time being, not enough time to properly implement | 4/24/24

                //if (sf::Mouse::getPosition(window).x > 440.0f && sf::Mouse::getPosition(window).x < 600.0f) {
                //    if (sf::Mouse::getPosition(window).y > 800.0f && sf::Mouse::getPosition(window).y < 900.0f) {
                //        currentSelection = __scores;
                //        //std::cout << "scores clicked" << std::endl;
                //        confirm = 1;
                //        
                //       
                //    }
                //}
                //test cases box
                if (sf::Mouse::getPosition(window).x > 600.0f && sf::Mouse::getPosition(window).x < 775.0f) {
                    if (sf::Mouse::getPosition(window).y > 760.0f && sf::Mouse::getPosition(window).y < 940.0f) {
                        currentSelection = __test_cases;
                        //std::cout << "test cases clicked" << std::endl;
                        confirm = 1;
                    }
                }

            }
            //here the selected options will direct to the correct place
            if (confirm == 1) {
                switch (currentSelection) {
                case __play:
                    running = false;
                    std::cout << "Play!" << std::endl;
                    return 1;
                    break;
                case __exit:
                    
                    running = false;
                    window.close();
                    return -1;
                    break;
                //inactive
                case __scores:
                    
                    running = false;
                    return 3;
                    break;
                case __test_cases:
                    running = false;
                    return 2;
                    break;
                default:
                    break;
                }
            }
            window.clear();
            window.draw(background_spr);
           // window.draw(scores);
            window.draw(test_cases);
            window.draw(play);
            window.draw(exitT);
            window.display();
        }
        if (!running) {
            //sstd::cout << "breaking out of loop" << std::endl;
            break;
        }
    }
    
    return 0;
}
