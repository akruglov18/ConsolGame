#pragma once
#include "button.h"

class menu_button : public button {
public:
    menu_button(const std::string& _text, const sf::FloatRect& _coord, View_mode _func,
                const sf::Color& _text_color = {96, 76, 66});
    View_mode function;
    bool hovered = false;

    static View_mode buttons_checker(sf::Vector2i mouse_pos, const std::vector<menu_button*>& _buttons,
                                     const sf::Event& _event);
    void normal();
    void hover();
    virtual void print_button(sf::RenderWindow& window) override;
};