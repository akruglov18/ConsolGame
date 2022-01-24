#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "utils.h"

class button {
public:
    sf::Text text;
    std::shared_ptr<sf::Texture> texture;
    sf::Color text_color;
    sf::FloatRect coord;
    sf::Sprite spriteL;
    sf::Sprite spriteM;
    sf::Sprite spriteR;
    View_mode function;

    bool hovered = false;

    void init(sf::Font& font, const std::string& text, View_mode func, int font_size, sf::Color& color, sf::FloatRect& coord);
    void normal();
    void hover();
    void print_button(sf::RenderWindow& window);

    static View_mode buttons_checker(sf::Vector2i mouse_pos, std::vector<button*>& _buttons, sf::Event& _event);
};