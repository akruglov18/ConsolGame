#include "settings_menu.h"

SettingsMenu::SettingsMenu(GameSettings& _settings)
        : b_main_menu("Main menu", sf::FloatRect({540.f, 380.f}, {240.f, 52.f}), View_mode::MAIN_MENU),
          s_sound("Sound volume", sf::FloatRect({540.f, 320.f}, {240.f, 52.f}), {}),
          s_difficulty("Difficulty", sf::FloatRect({540.f, 260.f}, {240.f, 52.f}), {}),
          settings(_settings) {
    color = sf::Color(30, 101, 125);
    buttons.push_back(&b_main_menu);
    sliders.push_back(&s_sound);
    sliders.push_back(&s_difficulty);
}

View_mode SettingsMenu::Run(sf::RenderWindow& window) {
    sf::Event event;
    window.waitEvent(event);
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            Slider::was_released = false;
            to_return = View_mode::EXIT;
            break;
        }
        if (Slider::clicked_slider == nullptr) {
            to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        }
        if (to_return != View_mode::NONE) {
            Slider::was_released = false;
            break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            Slider::was_released = false;
            to_return = View_mode::MAIN_MENU;
            break;
        }

        Slider::sliders_checker(sf::Mouse::getPosition(window), sliders);

        window.clear(color);
        b_main_menu.print_button(window);
        s_sound.print_button(window);
        s_difficulty.print_button(window);
        Cursor::move(window);
        window.display();
        menu_music.setVolume(static_cast<float>(s_sound.slide_value));
        play_music();
    }
    
    set();

    return to_return;
}

void SettingsMenu::set() {
    auto difficulty_value = s_difficulty.slide_value;
    if (difficulty_value >= 50) {
        settings.difficulty = true;
    } else {
        settings.difficulty = false;
    }
}
