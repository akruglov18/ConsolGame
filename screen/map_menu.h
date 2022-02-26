#pragma once
#include "screen.h"

class map_menu : public screen {
public:
    map_menu();
    sf::Color color;
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
