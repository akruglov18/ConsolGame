#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"

class Cursor {
private:
    static inline sf::Sprite sprite;
public:
    static void init();
    static void move(sf::RenderWindow& window);
};