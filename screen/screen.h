#pragma once
#include "button.h"
#include "utils.h"

class screen {
public:
    sf::Font font;
    virtual View_mode Run(sf::RenderWindow& window) = 0;
};