#include "main_menu.h"

MainMenu::MainMenu()
        : b_play("Start game", sf::FloatRect({540.f, 260.f}, {240.f, 52.f}), View_mode::GAME),
          b_settings("Settings", sf::FloatRect({540.f, 320.f}, {240.f, 52.f}), View_mode::SETTINGS_MENU),
          b_exit("Exit", sf::FloatRect({540.f, 380.f}, {240.f, 52.f}), View_mode::EXIT) {
    color = sf::Color(240, 164, 99);

    buttons.push_back(&b_play);
    buttons.push_back(&b_settings);
    buttons.push_back(&b_exit);
}

View_mode MainMenu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        window.clear(color);
        b_play.print_button(window);
        b_settings.print_button(window);
        b_exit.print_button(window);
        window.display();
        play_music();
    }
}
