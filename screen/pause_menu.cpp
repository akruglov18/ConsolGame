#include "pause_menu.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
static auto HOLDERF = getGlobalResourceHolder<sf::Font, std::string>;

pause_menu::pause_menu(): 
    b_main_menu("Main menu", sf::FloatRect(540.f, 320.f, 240.f, 52.f), View_mode::MAIN_MENU), 
    b_to_game("To game", sf::FloatRect(540.f, 260.f, 240.f, 52.f), View_mode::GAME) {

    color = sf::Color(255, 255, 255);

    buttons.push_back(&b_main_menu);
    buttons.push_back(&b_to_game);

    pause_text.setFont(*HOLDERF().getResource("basic_font"));
    pause_text.setString("PAUSE");
    pause_text.setCharacterSize(78);
    pause_text.setFillColor(sf::Color(100, 30, 30));
    pause_text.setStyle(sf::Text::Bold);
    pause_text.setPosition(sf::Vector2f(520.f, 120.f));
}

View_mode pause_menu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    pause_screenIMG.loadFromFile("../../images/tmp.jpg");
    pause_screen.setTexture(pause_screenIMG);
    pause_screen.setColor(sf::Color(255, 255, 255, 180));

    sf::Clock clock;
    View_mode to_return;
    while (true) {
        // auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp.jpg");
            return View_mode::EXIT;
        }
        to_return = menu_button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE) {
            std::remove("../../images/tmp.jpg");
            return to_return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            std::remove("../../images/tmp.jpg");
            return View_mode::GAME;
        }

        window.setView(window.getDefaultView());
        window.clear(color);
        window.draw(pause_screen);
        b_main_menu.print_button(window);
        b_to_game.print_button(window);
        window.draw(pause_text);
        window.display();
    }
}
