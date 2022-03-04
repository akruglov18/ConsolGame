#include "slider.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
slider* slider::clicked_slider = nullptr;
bool slider::was_released = false;

slider::slider(const std::string& _text, const sf::FloatRect& _coord, std::function<void()> _func,
               const sf::Color& _text_color)
        : button(_text, _coord, _text_color) {
    texture = HOLDER().getResource("main_ui");
    text_color = _text_color;
    coord = _coord;
    function = _func;
    left_border = static_cast<int>(coord.left);
    right_border = static_cast<int>(coord.left + coord.width - 44);

    spriteL.setTexture(*texture);
    spriteL.setTextureRect(sf::IntRect({634, 142}, {24, 26}));
    spriteL.setScale(sf::Vector2f(2.f, 2.f));
    spriteL.setPosition(sf::Vector2f(coord.left, coord.top));

    spriteM.setTexture(*texture);
    spriteM.setTextureRect(sf::IntRect({658, 142}, {24, 26}));
    spriteM.setScale(sf::Vector2f(coord.width / 36, 2.f));
    spriteM.setPosition(sf::Vector2f(coord.left + 36, coord.top));

    spriteR.setTexture(*texture);
    spriteR.setTextureRect(sf::IntRect({682, 142}, {26, 26}));
    spriteR.setScale(sf::Vector2f(2.f, 2.f));
    spriteR.setPosition(sf::Vector2f(coord.left + coord.width - 48, coord.top));

    sprite_slide.setTexture(*texture);
    sprite_slide.setTextureRect(sf::IntRect({762, 86}, {24, 24}));
    sprite_slide.setScale(sf::Vector2f(2.f, 2.f));
    sprite_slide.setPosition(sf::Vector2f(coord.left + coord.width - 44, coord.top + 2));

    sprite_inner.setTexture(*texture);
    sprite_inner.setTextureRect(sf::IntRect({64, 120}, {16, 16}));
    sprite_inner.setScale(sf::Vector2f(2.f, 2.f));
    sprite_inner.setPosition(sf::Vector2f(coord.left + coord.width - 34, coord.top + 10));

    text.setCharacterSize(FONT_SIZE);
    text.setFillColor(_text_color);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(coord.left - FONT_SIZE * (_text.size() / 2.f) - 40, coord.top + 6));

    percent_value.setFont(font);
    percent_value.setString("100%");
    percent_value.setCharacterSize(FONT_SIZE);
    percent_value.setFillColor(_text_color);
    percent_value.setStyle(sf::Text::Bold);
    percent_value.setPosition(sf::Vector2f(right_border + 80.f, coord.top + 0.f));
}

void slider::move_slider(sf::Vector2i mouse_pos) {
    if (mouse_pos.x < right_border && mouse_pos.x > left_border) {
        sprite_slide.setPosition(sf::Vector2f(mouse_pos.x + 0.f, coord.top + 2.f));
        sprite_inner.setPosition(sf::Vector2f(mouse_pos.x + 10.f, coord.top + 10.f));
        slide_value = static_cast<int>(1.22f * (100 * (mouse_pos.x - left_border)) / coord.width);
    } else if (mouse_pos.x >= right_border) {
        sprite_slide.setPosition(sf::Vector2f(right_border + 0.f, coord.top + 2.f));
        sprite_inner.setPosition(sf::Vector2f(right_border + 10.f, coord.top + 10.f));
        slide_value = 100;
    } else {
        sprite_slide.setPosition(sf::Vector2f(left_border + 0.f, coord.top + 2.f));
        sprite_inner.setPosition(sf::Vector2f(left_border + 10.f, coord.top + 10.f));
        slide_value = 0;
    }
    percent_value.setString(std::to_string(slide_value) + "%");
}

void slider::sliders_checker(sf::Vector2i mouse_pos, const std::vector<slider*>& _sliders) {
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        was_released = true;
    }

    if (clicked_slider != nullptr) {
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            clicked_slider = nullptr;
            return;
        }
        if (was_released) {
            clicked_slider->move_slider(mouse_pos);
        }
        return;
    }

    for (auto slider : _sliders) {
        if (mouse_pos.x > slider->left_border && mouse_pos.x < slider->coord.left + slider->coord.width &&
            mouse_pos.y > slider->coord.top && mouse_pos.y < slider->coord.top + slider->coord.height) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                clicked_slider = slider;
                return;
            } else {
                clicked_slider = nullptr;
            }
        }
    }
}

void slider::print_button(sf::RenderWindow& window) {
    window.draw(spriteL);
    window.draw(spriteM);
    window.draw(spriteR);
    window.draw(sprite_slide);
    window.draw(sprite_inner);
    window.draw(percent_value);
    window.draw(text);
}
