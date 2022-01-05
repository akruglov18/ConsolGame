#include "items.h"
#include <string>

const std::vector<std::string> Items::_suffixes = { "_walk", "_thrust", "_spellcast", "_slash", "_hurt", "_bow" };

ItemType Items::get_type() const {
    return _item_type;
}

std::string Items::get_type_str() const {
    switch(_item_type) {
        case ItemType::NONE   : return "None";
        case ItemType::WEAPON : return "Weapon";
        case ItemType::ARMOR  : return "Armor";
        default               : return "Undefined";
    }
}

void Items::init_scale(const sf::Vector2f& pos) {
    _sprite.setTexture(*_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
