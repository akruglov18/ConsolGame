#pragma once
#include "screen.h"

class MapMenu : public Screen {
public:
    MapMenu();
    sf::Color color;

    virtual View_mode Run(sf::RenderWindow& window) override;
};
