#include "settings_menu.h"

settings_menu::settings_menu()
        : b_main_menu("Main menu", sf::FloatRect({540.f, 380.f}, {240.f, 52.f}), View_mode::MAIN_MENU),
          s_sound("Sound volume", sf::FloatRect({540.f, 320.f}, {240.f, 52.f}), {}),
          s_difficulty("Difficulty", sf::FloatRect({540.f, 260.f}, {240.f, 52.f}), {}) {
    color = sf::Color(30, 101, 125);
    buttons.push_back(&b_main_menu);
    sliders.push_back(&s_sound);
    sliders.push_back(&s_difficulty);
}

View_mode settings_menu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    View_mode to_return{View_mode::NONE};
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            slider::was_released = false;
            return View_mode::EXIT;
        }
        if (slider::clicked_slider == nullptr)
            to_return = menu_button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE) {
            slider::was_released = false;
            return to_return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            slider::was_released = false;
            return View_mode::MAIN_MENU;
        }

        slider::sliders_checker(sf::Mouse::getPosition(window), sliders);

        window.clear(color);
        b_main_menu.print_button(window);
        s_sound.print_button(window);
        s_difficulty.print_button(window);
        window.display();
    }
}
