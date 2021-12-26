#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Action
{
public:
    // movements
    //                     sprite         global       local animation     coordinates       borders
    static void move_left(int& dir, sf::Sprite&, float time, float& current_frame, sf::Vector2f& pos);
    static void move_right(int& dir, sf::Sprite&, float time, float& current_frame, sf::Vector2f& pos, int right_border);
    static void move_up(int& dir, sf::Sprite&, float time, float& current_frame, sf::Vector2f& pos);
    static void move_down(int& dir, sf::Sprite&, float time, float& current_frame, sf::Vector2f& pos, int btm_border);

    static void stop(int dir, sf::Sprite&);

    // another actions such as take, cut, hit, trade, use magic and so on
};

