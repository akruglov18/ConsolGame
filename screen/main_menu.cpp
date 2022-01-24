#include "main_menu.h"

main_menu::main_menu() {
    _color = sf::Color(240, 164, 99);
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    b_play.init(font, "Start game", View_mode::GAME, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 260.f, 240.f, 52.f));
    b_settings.init(font, "Settings", View_mode::SETTINGS_MENU, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 320.f, 240.f, 52.f));
    b_exit.init(font, "Exit", View_mode::EXIT, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 380.f, 240.f, 52.f));

    buttons.push_back(&b_play);
    buttons.push_back(&b_settings);
    buttons.push_back(&b_exit);
}

View_mode main_menu::Run(sf::RenderWindow& window) {
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

        window.clear(_color);
        b_play.print_button(window);
        b_settings.print_button(window);
        b_exit.print_button(window);
        window.display();
    }
}