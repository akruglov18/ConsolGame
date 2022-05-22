#pragma once
#include "menu_button.h"
#include "screen.h"
#include "skills_graph.h"

class SkillsMenu : public Screen {
public:
    SkillsMenu();
    sf::Color color;
    SkillsGraph graph;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;

    static void node_click_checker(sf::Vector2i mouse_pos, const std::vector<std::shared_ptr<Node>>& _skills,
                                   const sf::Event& _event, Player& player);

    virtual View_mode Run(sf::RenderWindow& window, Player* player) override;
};
