#include "base_armor.h"

BaseArmor::BaseArmor() {
    _item_type = ItemType::ARMOR;
    _textures.resize(T_SIZE);
}

void BaseArmor::init_scale(const sf::Vector2f& pos) {
    _sprite.setTexture(*_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

void BaseArmor::walk() {
    if (this != nullptr && _textures[T_WALK] != nullptr)
        _sprite.setTexture(*_textures[T_WALK]);
}

void BaseArmor::thrust() {
    if (this != nullptr && _textures[T_THRUST] != nullptr)
        _sprite.setTexture(*_textures[T_THRUST]);
}

void BaseArmor::spellcast() {
    if (this != nullptr && _textures[T_SPELLCAST] != nullptr)
        _sprite.setTexture(*_textures[T_SPELLCAST]);
}

void BaseArmor::slash() {
    if (this != nullptr && _textures[T_SLASH] != nullptr) {
        _sprite.setTexture(*_textures[T_SLASH]);
    }
}

void BaseArmor::hurt() {
    if (this != nullptr && _textures[T_HURT] != nullptr)
        _sprite.setTexture(*_textures[T_HURT]);
}

void BaseArmor::bow() {
    if (this != nullptr && _textures[T_BOW] != nullptr)
        _sprite.setTexture(*_textures[T_BOW]);
}
