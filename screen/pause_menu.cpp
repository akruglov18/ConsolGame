#include "pause_menu.h"

pause_menu::pause_menu() {
    _color = sf::Color(255, 255, 255);
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    b_main_menu.init(font, "Main menu", View_mode::MAIN_MENU, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 320.f, 240.f, 52.f));
    b_to_game.init(font, "To game", View_mode::GAME, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 260.f, 240.f, 52.f));

    buttons.push_back(&b_main_menu);
    buttons.push_back(&b_to_game);

    _pause_text.setFont(font);
    _pause_text.setString("PAUSE");
    _pause_text.setCharacterSize(78);
    _pause_text.setFillColor(sf::Color(100, 30, 30));
    _pause_text.setStyle(sf::Text::Bold);
    _pause_text.setPosition(sf::Vector2f(520.f, 120.f));
}

View_mode pause_menu::Run(sf::RenderWindow& window) {
    pause_screenIMG.loadFromFile("../../images/tmp.jpg");
    pause_screen.setTexture(pause_screenIMG);
    pause_screen.setColor(sf::Color(255, 255, 255, 180));

    sf::Clock clock;
    View_mode to_return;
    while (true) {
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp.jpg");
            return View_mode::EXIT;
        }
        to_return = button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE) {
            std::remove("../../images/tmp.jpg");
            return to_return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            std::remove("../../images/tmp.jpg");
            return View_mode::GAME;
        }

        window.setView(window.getDefaultView());
        window.clear(_color);
        window.draw(pause_screen);
        b_main_menu.print_button(window);
        b_to_game.print_button(window);
        window.draw(_pause_text);
        window.display();
    }
}