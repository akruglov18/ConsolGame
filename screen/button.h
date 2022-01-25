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

    void init(const sf::Font& font, const std::string& text, View_mode func, int font_size, const sf::Color& color, const sf::FloatRect& coord);
    void normal();
    void hover();
    void print_button(sf::RenderWindow& window);

    static View_mode buttons_checker(sf::Vector2i mouse_pos, const std::vector<button*>& _buttons, const sf::Event& _event);
};

class slider {
public:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite spriteL;
    sf::Sprite spriteM;
    sf::Sprite spriteR;

    sf::Text text;
    sf::Text percent_value;
    sf::Color text_color;
    sf::FloatRect coord;
    Function function;

    sf::Sprite sprite_slide;
    sf::Sprite sprite_inner;

    int left_border;
    int right_border;
    int slide_value;
    static bool was_released;

    void init(const sf::Font& font, const std::string& text, Function func, int font_size, const sf::Color& color, const sf::FloatRect& coord);
    void print_slider(sf::RenderWindow& window);

    void move_slider(sf::Vector2i mouse_pos);

    static void sliders_checker(sf::Vector2i mouse_pos, const std::vector<slider*>& _sliders);
    static slider* clicked_slider;
};
