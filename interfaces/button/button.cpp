#include "button.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
static auto HOLDERF = getGlobalResourceHolder<sf::Font, std::string>;

button::button(const std::string& _text, const sf::FloatRect& _coord, const sf::Color& color) {
    texture = HOLDER().getResource("main_ui");
    font = *HOLDERF().getResource("basic_font");
    text_color = color;
    coord = _coord;
    text.setFont(font);
    text.setString(_text);
}
