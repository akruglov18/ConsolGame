#include "button.h"

button::button(const std::string& _text, const sf::FloatRect& _coord, const sf::Color& color) {
    texture = Resources::TexturesHolder::getResource("main_ui");
    font = *Resources::FontsHolder::getResource("basic_font");
    text_color = color;
    coord = _coord;
    text.setFont(font);
    text.setString(_text);
}
