#pragma once
#include "screen.h"

class MapMenu : public Screen {
public:
    MapMenu();
    sf::Color color;
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
