#pragma once
#include "button.h"
#include "utils.h"

class screen {
public:
    sf::Font font;
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> p = nullptr) = 0;
};
