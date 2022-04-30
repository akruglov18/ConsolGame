#include "map_menu.h"

MapMenu::MapMenu() {
    color = sf::Color(255, 0, 0);
}

View_mode MapMenu::Run(sf::RenderWindow& window) {
    sf::Event event;
    window.waitEvent(event);
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::MouseButtonPressed)
            return View_mode::GAME;

        window.clear(color);
        window.display();
        play_music();
    }
}
