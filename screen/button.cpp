#include "button.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

void button::init(sf::Font& font, const std::string& _text, View_mode func, int font_size, sf::Color& color, sf::FloatRect& _coord) {
    texture = HOLDER().getResource("main_ui");
    text_color = color;
    coord = _coord;
    function = func;

    spriteL.setTexture(*texture);
    spriteL.setTextureRect(sf::IntRect(634, 24, 42, 26));
    spriteL.setScale(sf::Vector2f(2.f, 2.f));
    spriteL.setPosition(sf::Vector2f(coord.left, coord.top));

    spriteM.setTexture(*texture);
    spriteM.setTextureRect(sf::IntRect(674, 24, 42, 26));
    spriteM.setScale(sf::Vector2f(coord.width / 84, 2.f));
    spriteM.setPosition(sf::Vector2f(coord.left + 66, coord.top));

    spriteR.setTexture(*texture);
    spriteR.setTextureRect(sf::IntRect(714, 24, 42, 26));
    spriteR.setScale(sf::Vector2f(2.f, 2.f));
    spriteR.setPosition(sf::Vector2f(coord.left + coord.width - 84, coord.top));

    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(font_size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(coord.left + coord.width / 2.f - font_size * (_text.size() / 4.f), coord.top + 8));
}

void button::normal() {
    hovered = false;
    spriteL.setTextureRect(sf::IntRect(634, 24, 42, 26));
    spriteL.move(sf::Vector2f(2, 0));
    spriteM.setTextureRect(sf::IntRect(674, 24, 42, 26));
    spriteR.setTextureRect(sf::IntRect(714, 24, 42, 26));
    text.setFillColor(text_color);
}

void button::hover() {
    hovered = true;
    spriteL.setTextureRect(sf::IntRect(633, 54, 42, 30));
    spriteL.move(sf::Vector2f(-2, 0));
    spriteM.setTextureRect(sf::IntRect(674, 54, 42, 30));
    spriteR.setTextureRect(sf::IntRect(714, 54, 43, 30));
    text.setFillColor(sf::Color(100, 30, 30));
}

void button::print_button(sf::RenderWindow& window) {
    window.draw(spriteL);
    window.draw(spriteM);
    window.draw(spriteR);
    window.draw(text);
}

View_mode button::buttons_checker(sf::Vector2i mouse_pos, std::vector<button*>& _buttons, sf::Event& _event) {
    for (auto but : _buttons) {
        if (mouse_pos.x > but->coord.left && mouse_pos.x < but->coord.left + but->coord.width &&
            mouse_pos.y > but->coord.top && mouse_pos.y < but->coord.top + but->coord.height) {
            if (!but->hovered)
                but->hover();
            if (_event.type == sf::Event::MouseButtonPressed) {
                return but->function;
            }
        }
        else {
            if (but->hovered)
                but->normal();
        }
    }
    return View_mode::NONE;
}