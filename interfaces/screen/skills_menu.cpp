#include "skills_menu.h"

SkillsMenu::SkillsMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);
    graph.init();
}

void SkillsMenu::node_click_checker(sf::Vector2i mouse_pos, const std::vector<std::shared_ptr<Node>>& _skills,
                                    const sf::Event& _event, Player& player) {
    if (_event.type == sf::Event::MouseButtonReleased && SkillButton::clicked) {
        SkillButton::clicked = false;
    }
    for (auto node : _skills) {
        if (mouse_pos.x > node->node_button.coord.left && mouse_pos.x < node->node_button.coord.left + 96 &&
            mouse_pos.y > node->node_button.coord.top && mouse_pos.y < node->node_button.coord.top + 63) {
            if (_event.type == sf::Event::MouseButtonPressed) {
                if (node->is_available() && !node->is_opened() && !SkillButton::clicked) {
                    SkillButton::clicked = true;
                    if (player.get_experience() >= node->get_cost()) {
                        node->unlock()->player_func(player);
                        player.add_experience(-node->get_cost());
                    }
                    return;
                }
            }
        }
    }
}

View_mode SkillsMenu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Tab)
                return View_mode::GAME;
        }

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        node_click_checker(sf::Mouse::getPosition(window), graph.get(), event, *player);

        window.clear(color);
        b_exit.print_button(window);
        for (int i = 0; i < graph.size(); ++i) {
            graph[i]->node_button.print_button(window);
        }
        window.display();
        play_music();
    }
}
