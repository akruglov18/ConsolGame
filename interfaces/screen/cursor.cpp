#include "cursor.h"

void Cursor::init() {
    sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    sprite.setTextureRect({{184, 128}, {12, 17}});
}

void Cursor::move(sf::RenderWindow& window) {
    sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
    window.draw(sprite);
}
