#include "gameover_menu.h"

GameoverMenu::GameoverMenu()
        : b_main_menu("Main menu", sf::FloatRect({380.f, 600.f}, {240.f, 52.f}), View_mode::MAIN_MENU),
          b_restart("Restart", sf::FloatRect({680.f, 600.f}, {240.f, 52.f}), View_mode::GAME) {
    color = sf::Color(255, 255, 255);

    buttons.push_back(&b_main_menu);
    buttons.push_back(&b_restart);

    gameover_text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    gameover_text.setString("WASTED");
    gameover_text.setCharacterSize(78);
    gameover_text.setFillColor(sf::Color(100, 30, 30));
    gameover_text.setStyle(sf::Text::Bold);
    gameover_text.setPosition(sf::Vector2f(480.f, 120.f));
}

View_mode GameoverMenu::Run(sf::RenderWindow& window) {
    gameover_screenIMG.loadFromFile("../../images/tmp_gameover.jpg");
    gameover_screen.setTexture(gameover_screenIMG);
    gameover_screen.setColor(sf::Color(255, 0, 0, 70));

    sf::Event event;
    window.waitEvent(event);
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp_gameover.jpg");
            return View_mode::EXIT;
        }
        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE) {
            std::remove("../../images/tmp_gameover.jpg");
            return to_return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            std::remove("../../images/tmp_gameover.jpg");
            return View_mode::GAME;
        }

        window.clear(color);
        window.draw(gameover_screen);
        b_main_menu.print_button(window);
        b_restart.print_button(window);
        window.draw(gameover_text);
        Cursor::move(window);
        window.display();
        play_music();
    }
}
