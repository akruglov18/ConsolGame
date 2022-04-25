#pragma once
#include <map>
#include "button.h"
#include "utils.h"

class Screen {
public:
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> p = nullptr) = 0;
};
