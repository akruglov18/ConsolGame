#pragma once
#include "button.h"
#include "utils.h"
#include <map>

class screen {
public:
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> p = nullptr) = 0;
};
