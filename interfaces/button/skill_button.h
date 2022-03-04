#pragma once
#include "button.h"

class skill_button : public button {
public:
    skill_button(const std::string& _text, const sf::FloatRect& _coord, const sf::Color& _text_color = {100, 30, 30});
    sf::Sprite node_linker;
    static bool clicked;
    virtual void print_button(sf::RenderWindow& window) override;
};