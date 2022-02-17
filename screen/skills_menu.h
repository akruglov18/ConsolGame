#pragma once
#include "screen.h"

class skills_menu : public screen {
public:
    skills_menu();
    sf::Color _color;
    virtual View_mode Run(sf::RenderWindow& window) override;
};
