#include "skills_menu.h"

skills_menu::skills_menu() {
    color = sf::Color(240, 164, 99);
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    exit_button.init(font, "Back", View_mode::GAME, 28, sf::Color(96, 76, 66), sf::FloatRect(20.f, 20.f, 150.f, 52.f));
    buttons.push_back(&exit_button);
    graph.init();
}

View_mode skills_menu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Clock clock;
    View_mode to_return;
    while (true) {
        // auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        sf::Event event;
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Tab)
                return View_mode::GAME;
        }

        to_return = button::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        Node::node_click_checker(sf::Mouse::getPosition(window), graph.get(), event, *player);

        window.setView(window.getDefaultView());
        window.clear(color);
        exit_button.print_button(window);
        for (int i = 0; i < graph.size(); ++i) {
            graph[i]->print_node(window);
        }
        window.display();
    }
}
