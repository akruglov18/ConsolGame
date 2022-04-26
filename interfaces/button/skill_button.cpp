#include "skill_button.h"

bool SkillButton::clicked = false;

SkillButton::SkillButton(const std::string& _text, const sf::FloatRect& _coord, const sf::Color& _text_color)
        : Button(_text, _coord, _text_color) {
    spriteL.setTexture(*texture);
    spriteM.setTexture(*texture);
    spriteR.setTexture(*texture);

    spriteL.setTextureRect({{16, 184}, {40, 64}});
    spriteM.setTextureRect({{50, 184}, {30, 64}});
    spriteR.setTextureRect({{82, 184}, {32, 64}});

    spriteL.setPosition(sf::Vector2f(coord.left, coord.top));
    spriteM.setPosition(sf::Vector2f(coord.left + 32, coord.top));
    spriteR.setPosition(sf::Vector2f(coord.left + 60, coord.top));

    text.setCharacterSize(14);
    text.setFillColor(_text_color);
    text.setPosition(sf::Vector2f(coord.left, coord.top - 20));
}

void SkillButton::print_button(sf::RenderWindow& window) {
    window.draw(node_linker);
    window.draw(spriteL);
    window.draw(spriteM);
    window.draw(spriteR);
    window.draw(text);
}
