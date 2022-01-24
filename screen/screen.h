#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "utils.h"

class screen {
public:
    virtual View_mode Run(sf::RenderWindow& window) = 0;
};