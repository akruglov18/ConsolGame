#include "pants.h"

Pants::Pants(const sf::Texture* texture, const sf::Vector2f& pos) : BaseArmor(texture, pos) {
    _armor_type = ArmorType::PANTS;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}