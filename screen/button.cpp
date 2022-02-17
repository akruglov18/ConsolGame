#include "button.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
slider* slider::clicked_slider = nullptr;
bool slider::was_released = false;

void button::init(const sf::Font& font, const std::string& _text, View_mode func, int font_size, const sf::Color& color,
                  const sf::FloatRect& _coord) {
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

View_mode button::buttons_checker(sf::Vector2i mouse_pos, const std::vector<button*>& _buttons,
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

void slider::init(const sf::Font& font, const std::string& _text, Function func, int font_size, const sf::Color& color,
                  const sf::FloatRect& _coord) {
    texture = HOLDER().getResource("main_ui");
    text_color = color;
    coord = _coord;
    function = func;
    left_border = static_cast<int>(coord.left);
    right_border = static_cast<int>(coord.left + coord.width - 44);

    spriteL.setTexture(*texture);
    spriteL.setTextureRect(sf::IntRect(634, 142, 24, 26));
    spriteL.setScale(sf::Vector2f(2.f, 2.f));
    spriteL.setPosition(sf::Vector2f(coord.left, coord.top));

    spriteM.setTexture(*texture);
    spriteM.setTextureRect(sf::IntRect(658, 142, 24, 26));
    spriteM.setScale(sf::Vector2f(coord.width / 36, 2.f));
    spriteM.setPosition(sf::Vector2f(coord.left + 36, coord.top));

    spriteR.setTexture(*texture);
    spriteR.setTextureRect(sf::IntRect(682, 142, 26, 26));
    spriteR.setScale(sf::Vector2f(2.f, 2.f));
    spriteR.setPosition(sf::Vector2f(coord.left + coord.width - 48, coord.top));

    sprite_slide.setTexture(*texture);
    sprite_slide.setTextureRect(sf::IntRect(762, 86, 24, 24));
    sprite_slide.setScale(sf::Vector2f(2.f, 2.f));
    sprite_slide.setPosition(sf::Vector2f(coord.left + coord.width - 44, coord.top + 2));

    sprite_inner.setTexture(*texture);
    sprite_inner.setTextureRect(sf::IntRect(64, 120, 16, 16));
    sprite_inner.setScale(sf::Vector2f(2.f, 2.f));
    sprite_inner.setPosition(sf::Vector2f(coord.left + coord.width - 34, coord.top + 10));

    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(font_size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(coord.left - font_size * (_text.size() / 2.f) - 40, coord.top + 6));

    percent_value.setFont(font);
    percent_value.setString("100%");
    percent_value.setCharacterSize(font_size);
    percent_value.setFillColor(color);
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

void slider::print_slider(sf::RenderWindow& window) {
    window.draw(spriteL);
    window.draw(spriteM);
    window.draw(spriteR);
    window.draw(sprite_slide);
    window.draw(sprite_inner);
    window.draw(text);
    window.draw(percent_value);
}
