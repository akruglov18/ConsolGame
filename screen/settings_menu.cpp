#include "settings_menu.h"

settings_menu::settings_menu() {
    color = sf::Color(30, 101, 125);
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    b_main_menu.init(font, "Main menu", View_mode::MAIN_MENU, 28, sf::Color(96, 76, 66), sf::FloatRect(540.f, 380.f, 240.f, 52.f));
    s_sound.init(font, "Sound volume", Function::SOUND , 28, sf::Color(100, 30, 30), sf::FloatRect(540.f, 320.f, 240.f, 52.f));
    s_difficulty.init(font, "Difficulty", Function::DIFFICULTY, 28, sf::Color(100, 30, 30), sf::FloatRect(540.f, 260.f, 240.f, 52.f));
    buttons.push_back(&b_main_menu);
    sliders.push_back(&s_sound);
    sliders.push_back(&s_difficulty);
}

View_mode settings_menu::Run(sf::RenderWindow& window) {
    sf::Clock clock;
    View_mode to_return = View_mode::NONE;
    while (true) {
        // auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            slider::was_released = false;
            return View_mode::EXIT;
        }
        if (slider::clicked_slider == nullptr)
            to_return = button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
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
        s_sound.print_slider(window);
        s_difficulty.print_slider(window);
        window.display();
    }
}
