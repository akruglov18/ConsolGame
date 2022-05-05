#include "map_menu.h"

MapMenu::MapMenu() {
    color = sf::Color(255, 0, 0);
}

View_mode MapMenu::Run(sf::RenderWindow& window) {
    sf::Event event;
    window.pollEvent(event);
    event.type = sf::Event::GainedFocus;
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::MouseButtonPressed)
            return View_mode::GAME;

        window.clear(color);
        Cursor::move(window);
        window.display();
        play_music();
    }
}
