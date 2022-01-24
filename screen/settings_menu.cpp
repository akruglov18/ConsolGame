#include "settings_menu.h"

settings_menu::settings_menu() {
    _color = sf::Color(30, 101, 125);
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    b_main_menu.init(font, "Main menu", View_mode::MAIN_MENU, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 380.f, 240.f, 52.f));

    buttons.push_back(&b_main_menu);
}

View_mode settings_menu::Run(sf::RenderWindow& window) {
    sf::Clock clock;
    View_mode to_return;
    while (true) {
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        to_return = button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            return View_mode::MAIN_MENU;

        window.clear(_color);
        b_main_menu.print_button(window);
        window.display();
    }
}