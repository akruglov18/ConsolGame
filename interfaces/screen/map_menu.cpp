#include "map_menu.h"

MapMenu::MapMenu() {
    color = sf::Color(255, 0, 0);
}

View_mode MapMenu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::MouseButtonPressed)
            return View_mode::GAME;

        window.clear(color);
        window.display();
    }
}
