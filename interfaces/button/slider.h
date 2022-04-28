#pragma once
#include "button.h"

class Slider : public Button {
public:
    Slider(const std::string& _text, const sf::FloatRect& _coord, std::function<void()> _func,
           const sf::Color& _text_color = {100, 30, 30});
    sf::Text percent_value;
    std::function<void()> function;

    sf::Sprite sprite_slide;
    sf::Sprite sprite_inner;

    int left_border;
    int right_border;
    int slide_value = 100;
    static bool was_released;

    void move_slider(sf::Vector2i mouse_pos);
    static void sliders_checker(sf::Vector2i mouse_pos, const std::vector<Slider*>& _sliders);
    virtual void print_button(sf::RenderWindow& window) override;

    static Slider* clicked_slider;
};
