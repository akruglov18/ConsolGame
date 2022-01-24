#include "main_menu.h"

main_menu::main_menu() {
    _color = sf::Color(255, 0, 0);
}

View_mode main_menu::Run(sf::RenderWindow& window) {
    sf::Clock clock;
    while (true) {
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::MouseButtonPressed)
            return View_mode::GAME;

        window.clear(_color);
        window.display();
    }
}