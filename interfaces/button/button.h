#pragma once
#include <functional>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "utils.h"

#define FONT_SIZE 28

class button {
public:
    button(const std::string& text, const sf::FloatRect& coord, const sf::Color& text_color);
    sf::Font font;
    sf::Text text;
    std::shared_ptr<sf::Texture> texture;
    sf::Color text_color;
    sf::FloatRect coord;
    sf::Sprite spriteL;
    sf::Sprite spriteM;
    sf::Sprite spriteR;

    virtual void print_button(sf::RenderWindow& window) = 0;
};
