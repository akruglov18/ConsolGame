#pragma once
#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"

class Cursor {
private:
    static inline sf::Sprite sprite;

public:
    static void init();
    static void move(sf::RenderWindow& window);
};
