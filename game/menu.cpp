#include "menu.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Menu::Menu(sf::RenderWindow* _window) {
    window = _window;
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    text.setFont(font);
    text.setString("PLAY");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(window->getSize().x / 2.f - 50, window->getSize().y / 2.f - 50));
}

View_mode Menu::menu_loop() {

    sf::Clock clock;

    while (window->isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();

        sf::Event event;
        window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            return View_mode::EXIT;
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            return View_mode::GAME;
        }


        /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
        auto start = std::chrono::high_resolution_clock::now();
        render();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "fps: " << std::setw(9) << 1 / diff.count() << "\r";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}

void Menu::render() {
    window->clear(sf::Color(255, 199, 87));
    window->draw(text);
    window->display();
}