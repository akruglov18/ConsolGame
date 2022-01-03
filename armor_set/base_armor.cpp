#include "base_armor.h"

BaseArmor::BaseArmor(const sf::Vector2f& pos) {
    _item_type = ItemType::ARMOR;
    _textures.resize(T_SIZE);
    _suffixes[T_WALK] = "_walk";
    _suffixes[T_THRUST] = "_thrust";
    _suffixes[T_SPELLCAST] = "_spellcast";
    _suffixes[T_SLASH] = "_slash";
    _suffixes[T_HURT] = "_hurt";
    _suffixes[T_BOW] = "_bow";
}

void BaseArmor::init_scale(const sf::Vector2f& pos) {
    _sprite.setTexture(*_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

void BaseArmor::walk() {
    _sprite.setTexture(*_textures[T_WALK]);
}

void BaseArmor::thrust() {
    _sprite.setTexture(*_textures[T_THRUST]);
}

void BaseArmor::spellcast() {
    _sprite.setTexture(*_textures[T_SPELLCAST]);
}

void BaseArmor::slash() {
    _sprite.setTexture(*_textures[T_SLASH]);
}

void BaseArmor::hurt() {
    _sprite.setTexture(*_textures[T_HURT]);
}

void BaseArmor::bow() {
    _sprite.setTexture(*_textures[T_BOW]);
}
