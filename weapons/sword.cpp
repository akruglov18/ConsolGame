#include "sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Sword::Sword(const sf::Vector2f& pos) : Weapon () {
    _damage = 10.0;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
    _texture = std::make_shared<sf::Texture>(*HOLDER().getResource("SPEAR_wood"));
    _sprite.setTexture(*_texture);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
