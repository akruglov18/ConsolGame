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

void BaseArmor::change_mode(Modes mode, std::shared_ptr<BaseArmor> elem) {
    elem->get_sprite().setTexture(*elem->get_textures()[static_cast<int>(mode)]);
}
