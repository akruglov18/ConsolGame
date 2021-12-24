#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Action
{
public:
    //                        key            sprite         global       local animation     coordinates       borders
    static void action(sf::Keyboard::Key, sf::Sprite&, float time, float& current_frame, sf::Vector2f& pos, int right_border, int btm_border);
    static void stop(sf::Keyboard::Key, sf::Sprite&);
};

