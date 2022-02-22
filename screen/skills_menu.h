#pragma once
#include "screen.h"
#include "skills_graph.h"

class skills_menu : public screen {
public:
    skills_menu();
    sf::Color color;
    SkillsGraph graph;

    button exit_button;
    std::vector<button*> buttons;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
