#include "menu_button.h"

menu_button::menu_button(const std::string& _text, const sf::FloatRect& _coord, View_mode _func,
                         const sf::Color& _text_color)
        : button(_text, _coord, _text_color) {
    function = _func;
    spriteL.setTexture(*texture);
    spriteL.setTextureRect(sf::IntRect({634, 24}, {42, 26}));
    spriteL.setScale(sf::Vector2f(2.f, 2.f));
    spriteL.setPosition(sf::Vector2f(coord.left, coord.top));

    spriteM.setTexture(*texture);
    spriteM.setTextureRect(sf::IntRect({674, 24}, {42, 26}));
    spriteM.setScale(sf::Vector2f(coord.width / 84, 2.f));
    spriteM.setPosition(sf::Vector2f(coord.left + 66, coord.top));

    spriteR.setTexture(*texture);
    spriteR.setTextureRect(sf::IntRect({714, 24}, {42, 26}));
    spriteR.setScale(sf::Vector2f(2.f, 2.f));
    spriteR.setPosition(sf::Vector2f(coord.left + coord.width - 84, coord.top));

    text.setCharacterSize(FONT_SIZE);
    text.setFillColor(text_color);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(coord.left + coord.width / 2.f - FONT_SIZE * (_text.size() / 4.f), coord.top + 8));
}

void menu_button::normal() {
    hovered = false;
    spriteL.setTextureRect(sf::IntRect({634, 24}, {42, 26}));
    spriteL.move(sf::Vector2f(2, 0));
    spriteM.setTextureRect(sf::IntRect({674, 24}, {42, 26}));
    spriteR.setTextureRect(sf::IntRect({714, 24}, {42, 26}));
    text.setFillColor(text_color);
}

void menu_button::hover() {
    hovered = true;
    spriteL.setTextureRect(sf::IntRect({633, 54}, {42, 30}));
    spriteL.move(sf::Vector2f(-2, 0));
    spriteM.setTextureRect(sf::IntRect({674, 54}, {42, 30}));
    spriteR.setTextureRect(sf::IntRect({714, 54}, {43, 30}));
    text.setFillColor(sf::Color(100, 30, 30));
}

View_mode menu_button::buttons_checker(sf::Vector2i mouse_pos, const std::vector<menu_button*>& _buttons,
                                       const sf::Event& _event) {
    for (auto but : _buttons) {
        if (mouse_pos.x > but->coord.left && mouse_pos.x < but->coord.left + but->coord.width &&
            mouse_pos.y > but->coord.top && mouse_pos.y < but->coord.top + but->coord.height) {
            if (!but->hovered)
                but->hover();
            if (_event.type == sf::Event::MouseButtonPressed) {
                return but->function;
            }
        } else {
            if (but->hovered)
                but->normal();
        }
    }
    return View_mode::NONE;
}

void menu_button::print_button(sf::RenderWindow& window) {
    window.draw(spriteL);
    window.draw(spriteM);
    window.draw(spriteR);
    window.draw(text);
}
