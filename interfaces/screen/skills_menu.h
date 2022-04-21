#pragma once
#include "menu_button.h"
#include "screen.h"
#include "skills_graph.h"

class skills_menu : public screen {
public:
    skills_menu();
    sf::Color color;
    SkillsGraph graph;

    menu_button b_exit;
    std::vector<menu_button*> buttons;

    static void node_click_checker(sf::Vector2i mouse_pos, const std::vector<std::shared_ptr<Node>>& _skills,
                                   const sf::Event& _event, Player& player);

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
