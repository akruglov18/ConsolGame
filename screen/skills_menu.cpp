#include "skills_menu.h"

skills_menu::skills_menu() {
    _color = sf::Color(143, 80, 0);
}

View_mode skills_menu::Run(sf::RenderWindow& window) {
    sf::Clock clock;
    while (true) {
        // auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Tab)
                return View_mode::GAME;
        }            

        window.clear(_color);
        window.display();
    }
}
