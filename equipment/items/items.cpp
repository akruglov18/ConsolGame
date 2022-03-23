#include "items.h"
#include <string>

const std::vector<std::string> Items::suffixes = {"_walk", "_thrust", "_spellcast", "_slash", "_hurt", "_bow"};

ItemType Items::get_type() const {
    return item_type;
}

std::string Items::get_type_str() const {
    switch (item_type) {
    case ItemType::NONE:
        return "None";
    case ItemType::WEAPON:
        return "Weapon";
    case ItemType::ARMOR:
        return "Armor";
    default:
        return "Undefined";
    }
}

void Items::set_scale(const sf::Vector2f& pos) {
    sprite.setTexture(*textures[static_cast<int>(Modes::WALK)]);
    sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));
    sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
