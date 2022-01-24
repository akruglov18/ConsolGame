#include "pause_menu.h"

pause_menu::pause_menu() {
    _color = sf::Color(0, 0, 255);
}

View_mode pause_menu::Run(sf::RenderWindow& window) {
    sf::Clock clock;
    while (true) {
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            return View_mode::GAME;
        if (event.type == sf::Event::MouseButtonPressed)
            return View_mode::MAIN_MENU;
        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;

        window.clear(_color);
        window.display();
    }
}