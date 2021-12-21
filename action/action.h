#pragma once
#include <SFML/Graphics.hpp>

class Action
{
public:
    static void action(sf::Keyboard::Key, sf::Sprite&, float time, float& cur);
    static void stop(sf::Keyboard::Key, sf::Sprite&);
};

