#include "base_armor.h"

BaseArmor::BaseArmor(const sf::Vector2f& pos) {
    _item_type = ItemType::ARMOR;
}

void BaseArmor::walk() {
    _sprite.setTexture(*_textures["walk"]);
}

void BaseArmor::thrust() {
    _sprite.setTexture(*_textures["thrust"]);
}

void BaseArmor::spellcast() {
    _sprite.setTexture(*_textures["spellcast"]);
}

void BaseArmor::slash() {
    _sprite.setTexture(*_textures["slash"]);
}

void BaseArmor::hurt() {
    _sprite.setTexture(*_textures["hurt"]);
}

void BaseArmor::bow() {
    _sprite.setTexture(*_textures["bow"]);
}