#include "base_armor.h"

BaseArmor::BaseArmor(const sf::Texture* texture, const sf::Vector2f& pos) {
    _item_type = ItemType::ARMOR;
    _texture = texture;
    _sprite.setTexture(*texture);
}